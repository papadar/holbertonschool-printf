#include <unistd.h>

/**
 * _putchar - writes the char to stdoutput 
 * @c: the char
 * Return: on success, 1
 * On error, -1 is returned
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
