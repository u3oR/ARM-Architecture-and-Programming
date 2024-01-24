		;指向一個地址
		MOV		R0, #0X20000
		;加載立即數
		LDR		R1, =0X1234
		LDR		R2, =0X5678
		;比較兩個數據
		CMP		R1, R2
		;如果		R1<=R2, 把R1的值保存到R0指向的地址
		STRLE	R1, [R0]
		;R1>R2,	把R2的值保存到R0指向的地址
		STRGT	R2, [R0]
