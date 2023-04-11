#include <stdio.h>
#include <stdlib.h>

void	chage_str(char **str)
{
	// str = malloc(sizeof(char) * 10);
	str[0][0] = 'H';
	str[0][1] = 'i';
	str[0][2] = '\0';
}

int	main(void)
{
	char *str = "sup";
	str = malloc(sizeof(char) * 10);
	chage_str(&str);
	printf("%s\n", str);
}