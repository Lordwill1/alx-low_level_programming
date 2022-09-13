/**
 * @file 0-putchar.c
 * @author Godswill Kalu
 * @brief Algorithm to print a message in a specific language
 * @date 2022-09-13
 *
 */
#include <main.h>

/**
 * main -  function is the entry point of the program
 *
 * Returns: 0 if the program ends successfully
 */
int main(void)
{
	char *message = "_putchar";
	_putchar(message);
	_putchar('\n');
	return (0);
}
