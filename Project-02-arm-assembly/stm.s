		;賦值,立即數
		mov		r0, #0x20000
		mov		r1, #1
		mov		r2, #2
		mov		r3, #3
		
		;LDM指令:load	multiple registr
		;LDM{addr_mode}{cond}	Rn{!}, reglist{^}
		;STM指令:store	multiple registr
		;STM{addr_mode}{cond}	Rn{!}, reglist{^}
		;addr_mode:	IA,IB,DA,DB
		;;IA:	increment after store
		;;IB:	increment before store
		;;DA:	decrement after store
		;;DB:	decrement before store
		
		;uint32_t	*p;
		;p		= (uint32_t*)(R0)
		;*p++	= R1
		;*p++	= R2
		;*p		= R3
		;;IA:	increment after store 即先存儲再偏移(加)指針
		;;存儲時,低標號的寄存器對應低地址
		
		stmia	r0, {r1-r3}
		
		;uint32_t	*p;
		;p		= (uint32_t*)(R0)
		;*(--p)	= R3
		;*(--p)	= R2
		;*(--p)	= R1
		;;DB:	decrement before store 即先偏移(減)指針再存儲
		;;存儲時,低標號的寄存器對應低地址
		stmdb	r0, {r1-r3}
		
		;對於其它兩種	stmda stmib也是類似的。
		
		
		
