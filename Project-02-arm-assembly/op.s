		
		mov		r2, #2
		mov		r3, #3
		;�ӷ�ָ��	R1=R2+R3
		add		r1, r2, r3
		;�ӷ�ָ��	R4=R2+9
		add		r4, r2, #9
		
		
		;;λ����
		
		ldr		r0, =0xFFFFFFFF
		ldr		r1, =0x10 ;0x10 == (1 << 4)
		
		;�c����		r0 = r0 & 0x10;
		;and		r0, r0, r1
		;λ���
		bic		r0, r0, r1
