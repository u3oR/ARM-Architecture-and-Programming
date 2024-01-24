		mov		r1, #1
		mov		r2, #2
		mov		r3, #3
		ldr		sp, =0xF0000000
		
		;STMFD,和STMDB作用一樣.	入棧使用
		;FD:full_decrement	即棧指針滿減
		
		;入棧
		;stmdb	sp!, {r1-r3}
		stmfd	sp!, {r1-r3}
		
		mov		r1, #0
		mov		r2, #0
		mov		r3, #0
		;出棧
		ldmfd	sp!, {r1-r3}
		
