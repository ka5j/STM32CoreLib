#ifndef USART_API_H_
#define USART_API_H_

#include <stdint.h>

typedef enum
{
    USART_PORT_1,
    USART_PORT_2,
    USART_PORT_3,
    USART_PORT_6
} USART_Port;

/* Public API */
void usart_init(USART_Port port, uint32_t baud);
void usart_send_string(USART_Port port, const char *msg);
char usart_read_char(USART_Port port);
void usart_clear(USART_Port port);

#endif // USART_API_H_
