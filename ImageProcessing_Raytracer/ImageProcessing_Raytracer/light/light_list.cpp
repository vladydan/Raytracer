#include <stdlib.h>
#include "rt.h"

int		light_list_size(t_light *light)
{
  t_light	*tmp;
  int		i;

  i = 0;
  tmp = light;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
