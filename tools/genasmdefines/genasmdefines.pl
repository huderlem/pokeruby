#!/usr/bin/perl

use strict;
use warnings;

# Stores the key-value pairing of a constant value.
sub SaveConstant {
    my ($constants, $constantNames, $name, $value) = @_;
    $constants->{$name} = $value;
    push @$constantNames, $name;
}

# Parses the contents of an enum (between its opening and closing curly braces)
sub ParseEnumValues {
    my ($constants, $constantNames, $enumContent) = @_;

    my $counter = 0;

    # Extract enum names and values
    while ($enumContent =~ /(\w+)\s*(?:=\s*(\d+)|)\s*,?\s*(?:(?:\n|$)|\/\/.*?(?:\n|$)|)/g) {
        my $name = $1;
        my $value = $2;
        if (length $name) {
            # Check for a previously defined value.
            if (length $value && exists $constants->{$value}) {
                $value = $constants->{$value};
            } 

            # Update the internal enum value counter.
            if (length $value) {
                $counter = $value;
            } else {
                $value = $counter;
            }

            SaveConstant($constants, $constantNames, $name, $value);
            $counter += 1;
        }
    }
}

# Remove leading and trailing whitespace from a string.
sub Trim {
    my ($value) = @_;
    $value =~ s/^\s+//;
    $value =~ s/\s+$//;
    return $value;
}

# State machine to parse a header value containing only #defines and simple enums without expressions as values.
# Returns a hash reference of the key-value pairs, and an array reference of the names in the order they appear.
#
# States:
# 0: searching for enum start
# 1: searching for enum opening curly brace
# 2: building content between enum opening and closing brackets
# 3: searching for end of enum (closing bracket + semicolon)
sub Parse {
    my ($filepath) = @_;

    open(my $file, $filepath)
        or die "ERROR: could not open file '$filepath'.\n";

    my %constants;
    my @constantNames;
    my $state = 0;
    my $enumContent = "";
    while (my $line = <$file>) {
        chomp $line;
        $line = Trim($line);

        # Remove //-style comment from the line.
        $line =~ s/\/\/.*//;

        # #define may occur in the middle of enums, so always look for a #define on its own line.
        if ($line =~ /^#define\s+(\w+)\s+(\w+)/) {
            SaveConstant(\%constants, \@constantNames, $1, $2);
        } else {
            # Since multiple enums could be defined on a single line, so we'll loop when that's detected.
            my $continueProcessingLine;
            do {
                $continueProcessingLine = 0;

                # Searching for enum start.
                if ($state == 0) {
                    if ($line =~ /^enum(.*)/) {
                        $state = 1;
                        $line = $1;
                    }
                }

                # Searching for enum opening curly brace.
                if ($state == 1) {
                    if ($line =~ /[^{]*{(.*)/) {
                        $state = 2;
                        $enumContent = $1;
                        $line = $enumContent;
                    }
                }
                
                # Building content between enum opening and closing brackets.
                if ($state == 2) {
                    if ($line =~ /(^[^}]*)}(.*)/) {
                        $state = 3;
                        $enumContent .= $1;
                        $line = $2;
                    } else {
                        $enumContent .= $line."\n";
                    }
                }

                # Searching for end of enum
                if ($state == 3) {
                    if ($line =~ /[^}]*;(.*)/) {
                        $state = 0;
                        $line = $1;
                        ParseEnumValues(\%constants, \@constantNames, $enumContent);

                        # If there is still content on the line, continue processing.
                        $line = Trim($line);
                        if (length $line) {
                            $continueProcessingLine = 1;
                        }
                    }
                }
            } while ($continueProcessingLine);
        }
    }

    return (\%constants, \@constantNames)
}

sub WriteAssemblerFile {
    my ($constants, $constantNames, $outputBuildDir, $outputFilepath) = @_;

    if (!-d $outputBuildDir) {
        mkdir $outputBuildDir
            or die "ERROR: Could not create output build directory '$outputBuildDir'\n";
    }

    open (my $file, '>', $outputFilepath)
        or die "ERROR: Could not open file '$outputFilepath' for writing.\n";

    foreach my $key (@$constantNames)
    {
        print $file ".equiv $key, $constants->{$key}\n";
    }

    close $file;
}


(@ARGV == 2)
    or die "ERROR: must specify header file and output assembler file.\n";

my $inputFilepath = $ARGV[0];
my $outputFilepath = $ARGV[1];

(my $outputFilename = $inputFilepath) =~ s/.*\///;
$outputFilename =~ s/\.h$/\.inc/;
my $outputBuildDir;
if ($outputFilepath =~ /(.*)\//) {
    $outputBuildDir = $1;
} else {
    die "ERROR: invalid output filepath\n"
}

my ($constants, $constantNames) = Parse($inputFilepath);
WriteAssemblerFile($constants, $constantNames, $outputBuildDir, $outputFilepath);
