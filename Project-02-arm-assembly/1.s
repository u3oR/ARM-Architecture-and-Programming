		;賦值爲立即數
		MOV		R0, #0x20000
		;僞指令，傳入立即數
		LDR		R1, =0x1234
		;向R0指定的地址存入數據
		STR		R1, [R0]
		;向R0指定的地址偏移4的地址存入數據
		STR		R1, [R0, #4]
		
