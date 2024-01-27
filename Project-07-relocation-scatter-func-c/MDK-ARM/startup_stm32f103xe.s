
                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
__Vectors       DCD     0 
                DCD     0x08000009;Reset_Handler  ; Reset Handler



                AREA    |.text|, CODE, READONLY
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  user_main
				
				IMPORT  |Image$$ER_IROM1$$Base|
				IMPORT  |Image$$ER_IROM1$$Length|
				IMPORT  |Load$$ER_IROM1$$Base|
				
				IMPORT  |Image$$RW_IRAM1$$Base|
				IMPORT  |Image$$RW_IRAM1$$Length|
				IMPORT  |Load$$RW_IRAM1$$Base|
				IMPORT  my_memcpy
				IMPORT	|Image$$RW_IRAM1$$ZI$$Base|
				IMPORT	|Image$$RW_IRAM1$$ZI$$Length|
				IMPORT  my_memset
				
				
				; set stack pointer
				LDR SP, = (0x20000000 + 0xC000)
				
				;; relocate text data region
				;LDR R0, = |Image$$ER_IROM1$$Base| ;dest
				;LDR R1, = |Load$$ER_IROM1$$Base| ;source
				;LDR R2, = |Image$$ER_IROM1$$Length| ;length
				;BL my_memcpy
				
				; relocate rw/zi data region
				LDR R0, = |Image$$RW_IRAM1$$Base| ;dest
				LDR R1, = |Load$$RW_IRAM1$$Base| ;source
				LDR R2, = |Image$$RW_IRAM1$$Length| ;length
				BL my_memcpy
				
				; clear zi(bss) data region
				LDR R0, = |Image$$RW_IRAM1$$ZI$$Base| ;dest
				MOV R1, #0 ;value
				LDR R2, = |Image$$RW_IRAM1$$ZI$$Length| ;length
				BL my_memset
				
				;LDR R0, =user_main
				;BLX R0
				NOP
                BL      user_main
				
                ENDP
					
                END

