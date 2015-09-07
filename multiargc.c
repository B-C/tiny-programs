#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define vstrcat(...) __vstrcat(__VA_ARGS__, (char *)NULL)

char *__vstrcat(const char *first, ...)
{
	size_t len;
	char *retbuf;
	va_list argp;
	char *p;

	if(first == NULL)
		return NULL;

	len = strlen(first);

	va_start(argp, first);

	while((p = va_arg(argp, char *)) != NULL)
		len += strlen(p);

	va_end(argp);

	retbuf = malloc(len + 1);	/* +1 for trailing \0 */

	if(retbuf == NULL)
		return NULL;		/* error */

	(void)strcpy(retbuf, first);

	va_start(argp, first);		/* restart; 2nd scan */

	while((p = va_arg(argp, char *)) != NULL)
		(void)strcat(retbuf, p);

	va_end(argp);

	return retbuf;
}

int main()
{
	char *str = vstrcat("Hello, ", "world!","\nBOUYA");

	printf("%s\n",str);
	return 0;
}
