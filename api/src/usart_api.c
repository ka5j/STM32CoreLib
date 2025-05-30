#include "usart_api.h"
#include "bare_usart.h"

/* Map user-defined enum to USART_TypeDef* */
static USART_TypeDef *get_usart_instance(USART_Port port)
{
    switch (port)
    {
    case USART_PORT_1:
        return USART1;
    case USART_PORT_2:
        return USART2;
    case USART_PORT_3:
        return USART3;
    case USART_PORT_6:
        return USART6;
    default:
        return USART2;
    }
}

/* API Wrappers */
void usart_init(USART_Port port, uint32_t baud)
{
    USART_TypeDef *usartx = get_usart_instance(port);
    bare_usart_init_port(usartx, baud);
}

void usart_send_string(USART_Port port, const char *msg)
{
    USART_TypeDef *usartx = get_usart_instance(port);
    bare_usart_send_string_port(usartx, msg);
}

char usart_read_char(USART_Port port)
{
    USART_TypeDef *usartx = get_usart_instance(port);
    return bare_usart_read_char_port(usartx);
}

void usart_clear(USART_Port port)
{
    USART_TypeDef *usartx = get_usart_instance(port);
    bare_usart_clear_screen_port(usartx);
}
