#include <stdlib.h>
#include "parsing.h"
#include "obj.h"
#include "rt.h"
#include "utils.h"
#include <iostream>

int		check_line(char **tab)
{
	int		i;
	int		min_arg;

	i = 0;
	min_arg = 0;

	while (i != 2)
		if (tab[i++] == NULL)
			return (1);
	if (my_strcmp(SPHERE_PARSE, tab[1]) || my_strcmp(CYLINDER_PARSE, tab[1]) ||
		my_strcmp(CONE_PARSE, tab[1]) || my_strcmp(SPECIAL_OBJ_PARSE, tab[1]))
	{
		min_arg = 15;
	}
	else if (my_strcmp(PLAN_PARSE, tab[1]))
		min_arg = 14;
	else if (my_strcmp(EYE_PARSE, tab[1]) || my_strcmp(LIGHT_PARSE, tab[1]))
		min_arg = 8;
	else
		return (1);
	while (i != min_arg)
		if (tab[i++] == NULL)
			return (1);
	return (0);
}
