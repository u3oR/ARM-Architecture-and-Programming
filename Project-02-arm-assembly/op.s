		
		mov		r2, #2
		mov		r3, #3
		;加法指令	R1=R2+R3
		add		r1, r2, r3
		;加法指令	R4=R2+9
		add		r4, r2, #9
		
		
		;;位操作
		
		ldr		r0, =0xFFFFFFFF
		ldr		r1, =0x10 ;0x10 == (1 << 4)
		
		;與操作		r0 = r0 & 0x10;
		;and		r0, r0, r1
		;位清除
		bic		r0, r0, r1
