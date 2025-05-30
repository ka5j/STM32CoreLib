#include "board_api.h"

int main(void)
{
    board_init();
    board_usart_clear();
    board_usart_send("System Ready. Type something:\n\r");

    while (1)
    {
        char c = board_usart_receive_char();
        board_usart_send("You typed: ");
        board_usart_send((char[]){c, '\n', '\r', '\0'});
    }
}