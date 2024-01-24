		;複製立即數
		mov		r0, #0x20000
		mov		r1, #0x10
		mov		r2, #0x12
		
		;保存R2的值到R0指定的地址
		;uint32_t	*p
		;p=(uint32_t*)(R0)
		;*p=R2
		str		r2, [r0]
		;p=(uint32_t*)(R0+4)
		;*p=R2
		str		r2, [r0, #4]
		;p=(uint32_t*)(R0+8)
		;*p=R2
		;R0=R0+8
		str		r2, [r0, #8]!
		;p=(uint32_t*)(R0+R1)
		;*p=R2
		str		r2, [r0, r1]
		;p=(uint32_t*)(R0+(R1<<4))
		;*p=R2
		str		r2, [r0, r1, lsl #4]
		;p=(uint32_t*)(R0)
		;*p=R2
		;R0=R0+0x20
		str		r2, [r0], #0x20
		;R2=0x34
		mov		r2, #0x34
		;p=(uint32_t*)(R0)
		;*p=R2
		str		r2, [r0]
		;p=(uint32_t*)(R0)
		;*p=R3
		;R0+=(R1<<1)
		ldr		r3, [r0], +r1, lsl #1
		
