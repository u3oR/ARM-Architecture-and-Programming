#ifndef UART_H
#define UART_H


int putc(char c);
void puts(const char *s);
int getc(void);


void UART_Init(void);

#endif
