		mov		r1, #1
		mov		r2, #2
		mov		r3, #3
		ldr		sp, =0xF0000000
		
		;STMFD,��STMDB����һ��.	�뗣ʹ��
		;FD:full_decrement	����ָᘝM�p
		
		;�뗣
		;stmdb	sp!, {r1-r3}
		stmfd	sp!, {r1-r3}
		
		mov		r1, #0
		mov		r2, #0
		mov		r3, #0
		;����
		ldmfd	sp!, {r1-r3}
		
