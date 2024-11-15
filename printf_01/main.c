// main.c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, World!\n");  // 基本的な文字列出力
    ft_printf("Character: %c\n", 'A');  // 文字出力
    ft_printf("String: %s\n", "Test");  // 文字列出力
    ft_printf("Pointer: %p\n", (void *)0x123456);  // ポインタ出力
    ft_printf("Decimal: %d\n", 42);  // 整数出力
    ft_printf("Unsigned: %u\n", 42);  // 符号なし整数出力
    ft_printf("Hex (lower): %x\n", 255);  // 16進数（小文字）出力
    ft_printf("Hex (upper): %X\n", 255);  // 16進数（大文字）出力
    ft_printf("Percent: %%\n");  // パーセント記号出力
    return 0;
}
