#!/bin/bash -ex

if [ "$TRAVIS_BRANCH" != "master" ]; then
  exit 0
fi

build_name=$1
map_file=$build_name.map
if [ ! -f $map_file ]; then
	echo "$map_file does not exist!"
	exit 1
fi

pushd .travis/calcrom/
output=$(perl calcrom.pl ../../$build_name.map | sed -E ':a;N;$!ba;s/\r{0,1}\n/\\n/g')
curl -d "{\"content\":\"\`\`\`$build_name progress:\\n$output\`\`\`\"}" -H "Content-Type: application/json" -X POST https://discordapp.com/api/webhooks/457300770635907082/S4FkZ0xu8Oswr9b-6YRTnainXHvrygQM08lr3QiSd-ut6REGtqrpiwODBmLUTggARiKO
popd
