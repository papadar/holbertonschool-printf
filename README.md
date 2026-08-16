#PRINTF Integration Project

This project is a recreation of the printf() function in C.

#Name
int _printf(const char *format, ...);

#Description
Writes the string pointed by format to the standard output. If format includes format specifiers (character followed by %), the arguments following format are inserted in the string. 

#Parameters
d or i: Signed decimal integer
u: Unsigned decimal integer
o: Unsigned octal
x: Unsigned hexadecimal integer
X: Unsigned hexadecimal integer (uppercase)
c: Character
s: String of characters
%: A % followed by another % will write one % to the output

#Return
On Success, the total number of characters written is returned.
