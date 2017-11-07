#include <stdlib.h>
#include "utils.h"
#include <iostream>

static int	len_wordtab(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i += 1;
	return (i);
}

static char	**my_realloc(char **tab, char *str)
{
	int	i;
	char	**ret;

	i = 0;
	while (tab && tab[i])
		i += 1;
	ret = (char **)malloc(sizeof(char *) * (i + 2));
	if (ret == NULL || str == NULL)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		ret[i] = tab[i];
		i += 1;
	}
	ret[i] = str;
	ret[i + 1] = NULL;
	std::cerr <<" Got " << str << std::endl;
	free(tab);
	return (ret);
}

char		**str_to_wordtab(char *str)
{
	char	**ret;
	int	i;

	i = 0;
	ret = NULL;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i += 1;
		ret = my_realloc(ret, my_strndup(str + i, len_wordtab(str + i)));
		if (ret == NULL)
			return (NULL);
		i += len_wordtab(str + i);
	}
	return (ret);
}
