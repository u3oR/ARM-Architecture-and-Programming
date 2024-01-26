
                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
__Vectors       DCD     0 
                DCD     Reset_Handler  ; Reset Handler



                AREA    |.text|, CODE, READONLY
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  main
				IMPORT  |Image$$RW_IRAM1$$Base|
				IMPORT  |Image$$RW_IRAM1$$Length|
				IMPORT  |Load$$RW_IRAM1$$Base|
				IMPORT  my_memcpy
					

				; set stack pointer
				LDR SP, = (0x20000000 + 0xC000)
				
				; relocate rw/zi data region
				LDR R0, = |Image$$RW_IRAM1$$Base| ;dest
				LDR R1, = |Load$$RW_IRAM1$$Base| ;source
				LDR R2, = |Image$$RW_IRAM1$$Length| ;length
				BL my_memcpy
				
                BL      main
                ENDP
		
                END

