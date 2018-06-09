	.include "MPlayDef.s"

	.equ	bgm_pokeradar_grp, voicegroup_8431B9C
	.equ	bgm_pokeradar_pri, 0
	.equ	bgm_pokeradar_rev, reverb_set+50
	.equ	bgm_pokeradar_mvl, 127
	.equ	bgm_pokeradar_key, 0
	.equ	bgm_pokeradar_tbs, 1
	.equ	bgm_pokeradar_exg, 0
	.equ	bgm_pokeradar_cmp, 1

	.section .rodata
	.global	bgm_pokeradar
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

bgm_pokeradar_1:
	.byte	KEYSH , bgm_pokeradar_key+0
	.byte TEMPO , 123*bgm_pokeradar_tbs/2
@ 000   ----------------------------------------
	.byte		VOICE , 46
	.byte		PAN   , c_v+12
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+12
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
bgm_pokeradar_1_loop:
	.byte		PAN   , c_v+12
	.byte	W72
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W24
	.byte		N15   , Cn3 , v112
	.byte	W16
	.byte		        Bn2 
	.byte	W16
	.byte		        As2 
	.byte	W16
	.byte		N44   , An2 
	.byte	W24
@ 007   ----------------------------------------
	.byte	W24
	.byte		N07   , Fs2 
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N07   , Fs2 , v072
	.byte	W16
	.byte		PAN   , c_v+32
	.byte		N07   , Fs2 , v052
	.byte	W16
	.byte		PAN   , c_v-37
	.byte		N07   , Fs2 , v048
	.byte	W16
	.byte		PAN   , c_v+38
	.byte		N07   , Fs2 , v040
	.byte	W08
@ 008   ----------------------------------------
	.byte	W08
	.byte		PAN   , c_v-39
	.byte		N07   , Fs2 , v020
	.byte	W16
	.byte		PAN   , c_v+0
	.byte	W72
@ 009   ----------------------------------------
	.byte	W24
@ 010   ----------------------------------------
	.byte		VOICE , 46
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	GOTO
	.word	bgm_pokeradar_1_loop

@**************** Track 2 (Midi-Chn.2) ****************@

bgm_pokeradar_2:
	.byte	KEYSH , bgm_pokeradar_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 23
	.byte		PAN   , c_v+16
	.byte		VOL   , 112*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		        c_v+16
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+0
	.byte		N01   , Fn5 , v096
	.byte	W02
	.byte		        Gn5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        Gn5 
	.byte	W02
	.byte		N15   , Fn5 
	.byte	W16
bgm_pokeradar_2_loop:
	.byte		VOICE , 48
	.byte		VOL   , 53*bgm_pokeradar_mvl/mxv
	.byte		N07   , As2 , v080
	.byte	W01
	.byte		VOL   , 56*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        64*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        66*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        79*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        93*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        114*bgm_pokeradar_mvl/mxv
	.byte	W04
	.byte		N07   , As2 , v052
	.byte	W08
	.byte		        Gs3 , v080
	.byte	W08
	.byte		        Gs3 , v040
	.byte	W40
@ 001   ----------------------------------------
	.byte	W24
	.byte		VOL   , 32*bgm_pokeradar_mvl/mxv
	.byte		N44   , Cs3 , v080
	.byte	W02
	.byte		VOL   , 40*bgm_pokeradar_mvl/mxv
	.byte	W02
	.byte		        44*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        45*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        47*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        48*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        53*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        56*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        58*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        61*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        66*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        68*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        74*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        79*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        80*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        85*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        88*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        92*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        98*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        101*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        100*bgm_pokeradar_mvl/mxv
	.byte	W02
	.byte		        106*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        111*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        114*bgm_pokeradar_mvl/mxv
	.byte	W04
	.byte		N07   , Dn3 
	.byte	W08
	.byte		        Dn3 , v040
	.byte	W16
@ 002   ----------------------------------------
	.byte		        Ds3 , v080
	.byte	W08
	.byte		        Ds3 , v040
	.byte	W16
	.byte		VOL   , 53*bgm_pokeradar_mvl/mxv
	.byte		N23   , As2 , v080
	.byte	W01
	.byte		VOL   , 56*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        64*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        66*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        79*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        93*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        114*bgm_pokeradar_mvl/mxv
	.byte	W12
	.byte		N07   , Gs3 
	.byte	W08
	.byte		        Gs3 , v040
	.byte	W40
@ 003   ----------------------------------------
	.byte	W24
	.byte		VOL   , 32*bgm_pokeradar_mvl/mxv
	.byte		N44   , Dn3 , v080
	.byte	W02
	.byte		VOL   , 40*bgm_pokeradar_mvl/mxv
	.byte	W02
	.byte		        44*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        45*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        47*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        48*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        53*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        56*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        58*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        61*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        66*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        68*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        74*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        79*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        80*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        85*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        88*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        92*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        98*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        101*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        100*bgm_pokeradar_mvl/mxv
	.byte	W02
	.byte		        106*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        111*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        114*bgm_pokeradar_mvl/mxv
	.byte	W04
	.byte		N07   , Cs3 
	.byte	W08
	.byte		        Cs3 , v040
	.byte	W16
@ 004   ----------------------------------------
	.byte		VOL   , 48*bgm_pokeradar_mvl/mxv
	.byte		N23   , En3 , v080
	.byte	W01
	.byte		VOL   , 52*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        60*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        71*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        96*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        112*bgm_pokeradar_mvl/mxv
	.byte	W84
	.byte	W03
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W24
@ 010   ----------------------------------------
	.byte		VOICE , 48
	.byte		PAN   , c_v+16
	.byte		VOL   , 112*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		VOL   , 112*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		VOL   , 112*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	GOTO
	.word	bgm_pokeradar_2_loop

@**************** Track 3 (Midi-Chn.3) ****************@

bgm_pokeradar_3:
	.byte	KEYSH , bgm_pokeradar_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 24
	.byte		PAN   , c_v-1
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
bgm_pokeradar_3_loop:
	.byte		PAN   , c_v-1
	.byte		N07   , As1 , v112
	.byte	W16
	.byte		        As1 , v060
	.byte	W08
	.byte		        Gs2 , v112
	.byte	W40
	.byte		        As1 
	.byte	W08
@ 001   ----------------------------------------
	.byte		        Gs2 
	.byte	W16
	.byte		        Fn2 
	.byte	W08
	.byte		N44   , Cs2 
	.byte	W48
	.byte		N23   , Dn2 
	.byte	W24
@ 002   ----------------------------------------
	.byte		        Ds2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N07   , Gs2 
	.byte	W40
	.byte		        As1 
	.byte	W08
@ 003   ----------------------------------------
	.byte		        Gs2 
	.byte	W16
	.byte		        Fn2 
	.byte	W08
	.byte		N44   , Dn2 
	.byte	W48
	.byte		N23   , Cs2 
	.byte	W24
@ 004   ----------------------------------------
	.byte		        En2 
	.byte	W24
	.byte		N15   , Fn2 
	.byte	W16
	.byte		        En2 
	.byte	W16
	.byte		        Ds2 
	.byte	W16
	.byte		N44   , Dn2 
	.byte	W24
@ 005   ----------------------------------------
	.byte	W24
	.byte		N15   , En2 
	.byte	W16
	.byte		        Ds2 
	.byte	W16
	.byte		        Dn2 
	.byte	W16
	.byte		N44   , Cs2 
	.byte	W24
@ 006   ----------------------------------------
	.byte	W24
	.byte		N15   , Ds2 
	.byte	W16
	.byte		        Dn2 
	.byte	W16
	.byte		        Cs2 
	.byte	W16
	.byte		N44   , Cn2 
	.byte	W24
@ 007   ----------------------------------------
	.byte	W24
	.byte		N92   , Bn1 
	.byte	W72
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W24
@ 010   ----------------------------------------
	.byte		VOICE , 24
	.byte		PAN   , c_v-1
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	GOTO
	.word	bgm_pokeradar_3_loop

@**************** Track 4 (Midi-Chn.4) ****************@

bgm_pokeradar_4:
	.byte	KEYSH , bgm_pokeradar_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 23
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Fn5 , v112
	.byte	W02
	.byte		        Gn5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        Gn5 
	.byte	W02
	.byte		N15   , Fn5 
	.byte	W16
bgm_pokeradar_4_loop:
	.byte		VOICE , 1
	.byte		N07   , As2 
	.byte	W16
	.byte		        As2 , v052
	.byte	W08
	.byte		        Gs3 , v112
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N07   , Gs3 , v072
	.byte	W16
	.byte		PAN   , c_v+32
	.byte		N07   , Gs3 , v048
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N07   , As2 , v112
	.byte	W08
@ 001   ----------------------------------------
	.byte		        Gs3 
	.byte	W16
	.byte		        Fn3 
	.byte	W08
	.byte		N44   , Cs3 
	.byte	W48
	.byte		N23   , Dn3 
	.byte	W24
@ 002   ----------------------------------------
	.byte		        Ds3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N07   , Gs3 
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N07   , Gs3 , v072
	.byte	W16
	.byte		PAN   , c_v+32
	.byte		N07   , Gs3 , v048
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N07   , As2 , v112
	.byte	W08
@ 003   ----------------------------------------
	.byte		        Gs3 
	.byte	W16
	.byte		        Fn3 
	.byte	W08
	.byte		N44   , Dn3 
	.byte	W48
	.byte		N23   , Cs3 
	.byte	W24
@ 004   ----------------------------------------
	.byte		        En3 
	.byte	W24
	.byte		N15   , Fn3 
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		        Ds3 
	.byte	W16
	.byte		N44   , Dn3 
	.byte	W24
@ 005   ----------------------------------------
	.byte	W24
	.byte		N15   , En3 
	.byte	W16
	.byte		        Ds3 
	.byte	W16
	.byte		        Dn3 
	.byte	W16
	.byte		N44   , Cs3 
	.byte	W24
@ 006   ----------------------------------------
	.byte	W24
	.byte		N15   , Ds3 
	.byte	W16
	.byte		        Dn3 
	.byte	W16
	.byte		        Cs3 
	.byte	W16
	.byte		N44   , Cn3 
	.byte	W24
@ 007   ----------------------------------------
	.byte	W24
	.byte		N07   , Bn2 
	.byte	W16
	.byte		PAN   , c_v-32
	.byte		N07   , Bn2 , v072
	.byte	W16
	.byte		PAN   , c_v+32
	.byte		N07   , Bn2 , v052
	.byte	W16
	.byte		PAN   , c_v-37
	.byte		N07   , Bn2 , v048
	.byte	W16
	.byte		PAN   , c_v+38
	.byte		N07   , Bn2 , v040
	.byte	W08
@ 008   ----------------------------------------
	.byte	W08
	.byte		PAN   , c_v-39
	.byte		N07   , Bn2 , v020
	.byte	W16
	.byte		PAN   , c_v+0
	.byte	W72
@ 009   ----------------------------------------
	.byte	W24
@ 010   ----------------------------------------
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	GOTO
	.word	bgm_pokeradar_4_loop

@**************** Track 5 (Midi-Chn.5) ****************@

bgm_pokeradar_5:
	.byte	KEYSH , bgm_pokeradar_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 23
	.byte		PAN   , c_v+0
	.byte		VOL   , 101*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 101*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 101*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 101*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 101*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
bgm_pokeradar_5_loop:
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N01   , As5 , v112
	.byte	W08
	.byte		PAN   , c_v+34
	.byte		N01   , Fn5 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N01   , Cs6 
	.byte	W32
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W48
	.byte		PAN   , c_v+36
	.byte		N01   , Fn5 
	.byte	W08
	.byte		PAN   , c_v-38
	.byte		N01   , Cs6 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N01   , As5 
	.byte	W32
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W24
@ 010   ----------------------------------------
	.byte		VOICE , 23
	.byte		PAN   , c_v+0
	.byte		VOL   , 101*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 101*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 101*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	GOTO
	.word	bgm_pokeradar_5_loop

@**************** Track 6 (Midi-Chn.6) ****************@

bgm_pokeradar_6:
	.byte	KEYSH , bgm_pokeradar_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
bgm_pokeradar_6_loop:
	.byte		N07   , As1 , v127
	.byte	W08
	.byte		        As1 , v040
	.byte	W16
	.byte		        Gs2 , v127
	.byte	W08
	.byte		        Gs2 , v040
	.byte	W08
	.byte		N01   , An1 , v127
	.byte	W02
	.byte		N05   , An1 , v040
	.byte	W06
	.byte		N15   , As1 , v127
	.byte	W16
	.byte		N07   
	.byte	W08
@ 001   ----------------------------------------
	.byte		        Gs2 
	.byte	W08
	.byte		        Gs2 , v040
	.byte	W16
	.byte		        As1 , v127
	.byte	W08
	.byte		        As1 , v040
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N07   , As1 , v088
	.byte	W08
	.byte		        As1 , v028
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N07   , As1 , v076
	.byte	W16
	.byte		PAN   , c_v-37
	.byte		N07   , As1 , v060
	.byte	W16
	.byte		PAN   , c_v+42
	.byte		N07   , As1 , v040
	.byte	W08
@ 002   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		N23   , Fn1 , v127
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N07   , Fn1 
	.byte	W08
	.byte		N01   , Gs1 
	.byte	W02
	.byte		N05   , Gs1 , v040
	.byte	W06
	.byte		N01   , An1 , v127
	.byte	W02
	.byte		N05   , An1 , v040
	.byte	W06
	.byte		N23   , As1 , v127
	.byte	W24
@ 003   ----------------------------------------
	.byte		N07   , As1 , v040
	.byte	W24
	.byte		        As1 , v127
	.byte	W08
	.byte		        As1 , v040
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N07   , As1 , v080
	.byte	W08
	.byte		        As1 , v028
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N07   , As1 , v064
	.byte	W16
	.byte		PAN   , c_v-37
	.byte		N07   , As1 , v052
	.byte	W16
	.byte		PAN   , c_v+42
	.byte		N07   , As1 , v040
	.byte	W08
@ 004   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		N15   , Fn1 , v127
	.byte	W16
	.byte		N07   , Cn2 
	.byte	W08
	.byte		N36   , Fn1 
	.byte	W40
	.byte		N01   , Cs2 
	.byte	W02
	.byte		N05   , Cs2 , v040
	.byte	W06
	.byte		N44   , Dn2 , v127
	.byte	W24
@ 005   ----------------------------------------
	.byte	W24
	.byte		N36   , En1 
	.byte	W40
	.byte		N01   , Cn2 
	.byte	W02
	.byte		N05   , Cn2 , v040
	.byte	W06
	.byte		N44   , Cs2 , v127
	.byte	W24
@ 006   ----------------------------------------
	.byte	W24
	.byte		N36   , Ds1 
	.byte	W40
	.byte		N01   , Bn1 
	.byte	W02
	.byte		N05   , Bn1 , v040
	.byte	W06
	.byte		N44   , Cn2 , v127
	.byte	W24
@ 007   ----------------------------------------
	.byte	W24
	.byte		N07   , Ds1 
	.byte	W08
	.byte		        Ds1 , v040
	.byte	W32
	.byte		N54   , Ds1 , v127
	.byte	W32
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W24
@ 010   ----------------------------------------
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	GOTO
	.word	bgm_pokeradar_6_loop

@**************** Track 7 (Midi-Chn.7) ****************@

bgm_pokeradar_7:
	.byte	KEYSH , bgm_pokeradar_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		PAN   , c_v-14
	.byte		VOL   , 32*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v-14
	.byte		VOL   , 32*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		VOL   , 69*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		VOL   , 69*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		VOL   , 69*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
bgm_pokeradar_7_loop:
	.byte	W24
	.byte		N07   , Gs3 , v100
	.byte	W08
	.byte		PAN   , c_v+34
	.byte		N07   , Gs3 , v032
	.byte	W08
	.byte		PAN   , c_v-30
	.byte		N07   , Gs3 , v060
	.byte	W08
	.byte		        Gs3 , v024
	.byte	W08
	.byte		PAN   , c_v+39
	.byte		N07   , Gs3 , v036
	.byte	W16
@ 001   ----------------------------------------
	.byte		        Gs3 , v020
	.byte	W96
@ 002   ----------------------------------------
	.byte	W48
	.byte		        Gs3 , v100
	.byte	W08
	.byte		PAN   , c_v+34
	.byte		N07   , Gs3 , v032
	.byte	W08
	.byte		PAN   , c_v-30
	.byte		N07   , Gs3 , v060
	.byte	W08
	.byte		        Gs3 , v024
	.byte	W08
	.byte		PAN   , c_v+39
	.byte		N07   , Gs3 , v036
	.byte	W16
@ 003   ----------------------------------------
	.byte		        Gs3 , v020
	.byte	W96
@ 004   ----------------------------------------
	.byte	W24
	.byte		PAN   , c_v-14
	.byte		N03   , Fn3 , v112
	.byte	W04
	.byte		N07   , Fn3 , v040
	.byte	W12
	.byte		N03   , En3 , v112
	.byte	W04
	.byte		N07   , En3 , v040
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W04
	.byte		N07   , Ds3 , v040
	.byte	W12
	.byte		N44   , Dn3 , v112
	.byte	W24
@ 005   ----------------------------------------
	.byte		VOL   , 61*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        58*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        56*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        53*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        48*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        45*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        40*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        37*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        32*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        29*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        26*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        24*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        69*bgm_pokeradar_mvl/mxv
	.byte		N03   , En3 
	.byte	W04
	.byte		N07   , En3 , v040
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W04
	.byte		N07   , Ds3 , v040
	.byte	W12
	.byte		N03   , Dn3 , v112
	.byte	W04
	.byte		N07   , Dn3 , v040
	.byte	W12
	.byte		N44   , Cs3 , v112
	.byte	W24
@ 006   ----------------------------------------
	.byte		VOL   , 63*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        61*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        55*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        53*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        48*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        45*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        40*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        37*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        32*bgm_pokeradar_mvl/mxv
	.byte	W04
	.byte		        26*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        24*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        71*bgm_pokeradar_mvl/mxv
	.byte		N03   , Ds3 
	.byte	W04
	.byte		N07   , Ds3 , v040
	.byte	W12
	.byte		N03   , Dn3 , v112
	.byte	W04
	.byte		N07   , Dn3 , v040
	.byte	W12
	.byte		N03   , Cs3 , v112
	.byte	W04
	.byte		N07   , Cs3 , v040
	.byte	W12
	.byte		N44   , Cn3 , v112
	.byte	W24
@ 007   ----------------------------------------
	.byte		VOL   , 61*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        60*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        56*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        55*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        52*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        47*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        45*bgm_pokeradar_mvl/mxv
	.byte	W04
	.byte		        39*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        37*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        34*bgm_pokeradar_mvl/mxv
	.byte	W01
	.byte		        32*bgm_pokeradar_mvl/mxv
	.byte	W03
	.byte		        69*bgm_pokeradar_mvl/mxv
	.byte	W72
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W24
@ 010   ----------------------------------------
	.byte		VOICE , 48
	.byte		PAN   , c_v-14
	.byte		VOL   , 69*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v-14
	.byte		VOL   , 69*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v-14
	.byte		VOL   , 69*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	GOTO
	.word	bgm_pokeradar_7_loop

@**************** Track 8 (Midi-Chn.8) ****************@

bgm_pokeradar_8:
	.byte	KEYSH , bgm_pokeradar_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
bgm_pokeradar_8_loop:
	.byte		N15   , As1 , v084
	.byte		N03   , Dn3 , v060
	.byte	W04
	.byte		        Dn3 , v064
	.byte	W04
	.byte		        Dn3 , v088
	.byte	W04
	.byte		        Dn3 , v096
	.byte	W04
	.byte		N07   , Fs2 , v016
	.byte		N03   , Dn3 , v116
	.byte	W04
	.byte		        Dn3 , v120
	.byte	W04
	.byte		N07   , Fs2 , v040
	.byte		N07   , Dn3 , v127
	.byte	W08
	.byte		N11   , Cn1 , v064
	.byte	W08
	.byte		N09   , Dn1 , v112
	.byte	W08
	.byte		N15   , As1 , v088
	.byte	W16
	.byte		N07   , Fs2 , v016
	.byte	W08
@ 001   ----------------------------------------
	.byte		        Fs2 , v096
	.byte	W16
	.byte		        Fs2 , v076
	.byte	W08
	.byte		        Fs2 , v056
	.byte	W16
	.byte		        Fs2 , v016
	.byte	W08
	.byte		        Fs2 , v040
	.byte	W24
	.byte		        Fs2 , v060
	.byte	W16
	.byte		        Fs2 , v016
	.byte	W08
@ 002   ----------------------------------------
	.byte		N09   , Cn1 , v060
	.byte		N07   , Fs2 
	.byte	W16
	.byte		N09   , Dn1 , v112
	.byte	W08
	.byte		N15   , As1 , v088
	.byte		N03   , Dn3 , v060
	.byte	W04
	.byte		        Dn3 , v064
	.byte	W04
	.byte		        Dn3 , v068
	.byte	W04
	.byte		        Dn3 , v076
	.byte	W04
	.byte		N07   , Fs2 , v016
	.byte		N03   , Dn3 , v084
	.byte	W04
	.byte		        Dn3 , v100
	.byte	W04
	.byte		N07   , Fs2 , v040
	.byte		N07   , Dn3 , v112
	.byte	W24
	.byte		N15   , As1 , v088
	.byte	W16
	.byte		N07   , Fs2 , v016
	.byte	W08
@ 003   ----------------------------------------
	.byte	W24
	.byte		        Fs2 , v056
	.byte		N23   , Bn2 , v088
	.byte	W16
	.byte		N07   , Fs1 , v112
	.byte		N07   , Fs2 , v016
	.byte	W08
	.byte		        Fs2 , v040
	.byte	W08
	.byte		        Fs1 , v064
	.byte	W16
	.byte		        Fs1 , v052
	.byte		N07   , Fs2 , v060
	.byte	W16
	.byte		        Fs1 , v040
	.byte		N07   , Fs2 , v016
	.byte	W08
@ 004   ----------------------------------------
	.byte		        Fs2 , v032
	.byte	W08
	.byte		        Fs1 , v020
	.byte	W16
	.byte		        Fs2 , v064
	.byte	W16
	.byte		        Fs2 , v028
	.byte	W08
	.byte		        Fs2 , v040
	.byte	W16
	.byte		        Fs2 , v028
	.byte	W08
	.byte		N15   , As1 , v060
	.byte	W16
	.byte		N09   , Dn1 , v112
	.byte		N07   , Fs2 , v016
	.byte	W08
@ 005   ----------------------------------------
	.byte		        Fs2 , v060
	.byte	W16
	.byte		        Fs2 , v016
	.byte	W08
	.byte		        Fs2 , v127
	.byte	W16
	.byte		        Fs2 , v016
	.byte	W08
	.byte		        Fs2 , v040
	.byte	W24
	.byte		        Fs2 , v060
	.byte	W16
	.byte		        Fs2 , v016
	.byte	W08
@ 006   ----------------------------------------
	.byte		        Fs2 , v032
	.byte	W24
	.byte		        Fs2 , v056
	.byte		N03   , Dn3 , v060
	.byte	W04
	.byte		        Dn3 , v064
	.byte	W04
	.byte		        Dn3 , v068
	.byte	W04
	.byte		        Dn3 , v076
	.byte	W04
	.byte		N07   , Fs2 , v016
	.byte		N03   , Dn3 , v084
	.byte	W04
	.byte		        Dn3 , v100
	.byte	W04
	.byte		N07   , Fs2 , v040
	.byte		N07   , Dn3 , v112
	.byte	W16
	.byte		        Dn1 
	.byte	W08
	.byte		        Fs2 , v060
	.byte		N03   , Dn3 
	.byte	W04
	.byte		        Dn3 , v064
	.byte	W04
	.byte		        Dn3 , v068
	.byte	W04
	.byte		        Dn3 , v076
	.byte	W04
	.byte		N07   , Fs2 , v016
	.byte		N03   , Dn3 , v084
	.byte	W04
	.byte		        Dn3 , v100
	.byte	W04
@ 007   ----------------------------------------
	.byte		N07   , Fs2 , v032
	.byte		N07   , Dn3 , v112
	.byte	W24
	.byte		        Fs2 , v056
	.byte	W16
	.byte		        Fs2 , v016
	.byte	W08
	.byte		N15   , As1 , v060
	.byte	W16
	.byte		N07   , Fs2 , v040
	.byte	W08
	.byte		        Fs2 , v060
	.byte	W16
	.byte		        Fs2 , v016
	.byte	W08
@ 008   ----------------------------------------
	.byte		        Fs2 , v032
	.byte	W24
	.byte		        Fs2 , v056
	.byte	W08
	.byte		        Fs2 , v020
	.byte	W08
	.byte		        Fs2 , v036
	.byte	W08
	.byte		        Fs2 , v040
	.byte	W24
	.byte		        Fs2 , v060
	.byte	W16
	.byte		        Fs2 , v016
	.byte	W08
@ 009   ----------------------------------------
	.byte		N23   , As1 , v060
	.byte	W24
@ 010   ----------------------------------------
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*bgm_pokeradar_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	GOTO
	.word	bgm_pokeradar_8_loop

@******************************************************@
	.align	2

bgm_pokeradar:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_pokeradar_pri	@ Priority
	.byte	bgm_pokeradar_rev	@ Reverb.

	.word	bgm_pokeradar_grp

	.word	bgm_pokeradar_1
	.word	bgm_pokeradar_2
	.word	bgm_pokeradar_3
	.word	bgm_pokeradar_4
	.word	bgm_pokeradar_5
	.word	bgm_pokeradar_6
	.word	bgm_pokeradar_7
	.word	bgm_pokeradar_8

	.end
