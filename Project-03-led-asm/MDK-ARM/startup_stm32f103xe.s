
                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     0 
                DCD     Reset_Handler  ; Reset Handler



                AREA    |.text|, CODE, READONLY
					
Reset_Handler   PROC
                EXPORT  Reset_Handler  [WEAK]
			
				;#define PERIPH_BASE 	(0x40000000UL)
				;#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000UL)
				;#define AHBPERIPH_BASE  (PERIPH_BASE + 0x00020000UL)

				;#define RCC_BASE 	(AHBPERIPH_BASE  + 0x00001000UL)
				;#define RCC_APB2ENR_offset (0x18)

				;#define GPIOA_BASE 	(APB2PERIPH_BASE + 0x00000800UL)
				;#define GPIO_CRL_offset (0x00)
				;#define GPIO_CRH_offset (0x04)
				;#define GPIO_ODR_offset (0x0C)
				
		;;; enable GPIOA clock
				
				; p = (uint32_t *)(RCC_BASE + RCC_APB2ENR_offset);
				LDR R0, =(0x40021000 + 0x18)
				LDR R1, [R0]
				; *p |= (1 << 2);
				ORR R1, R1, #0x04 
				STR R1, [R0]
				
				
		;;; set PA8 as output/pull-up/speed_10MHz pin
				
				; p = (uint32_t *)(GPIOA_BASE + GPIO_CRH_offset);
				LDR R0, =(0x40010800 + 0x04)
				LDR R1, [R0]
				; *p |= (1 << 0);
				ORR R1, R1, #0x01
				STR R1, [R0]
				
				; p = (uint32_t *)(GPIOA_BASE + GPIO_ODR_offset);
				LDR R2, =(0x40010800 + 0x0C)
				
		;;; set PA8 high/low level in while loop
loop
				; *p |= (uint32_t)(1 << 8);
				LDR R1, [R2]
				ORR R1, R1, #0x100 
				STR R1, [R2]
				; call delay() function
				LDR R0, =(500000)
				BL delay
				
				; *p &= ~(uint32_t)(1 << 8);
				LDR R1, [R2]
				BIC R1, R1, #0x100 
				STR R1, [R2]
				; call delay() function
				LDR R0, =(500000)
				BL delay
				
				B loop
				
                ENDP

delay			PROC
				SUBS R0, R0, #1
				BNE delay
				BX LR
				NOP
				ENDP

				END
