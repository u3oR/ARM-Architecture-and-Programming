
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
                IMPORT  user_main
					
				; set stack pointer
				LDR SP, = (0x20000000 + 0xC0000)
                BL      user_main
                ENDP
    
                END

