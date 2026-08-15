#include <unistd.h>

/**
 * _putchar - Write argument char c to stdoutput.
 * @c: Char argument to pass through function.
 * Return: 1 if success, else -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
