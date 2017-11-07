#include <stdlib.h>

char	*my_strndup(char *str, int len)
{
  int	i;
  char	*ret;

  i = 0;
  ret = (char*) malloc(sizeof(char) * (len + 1));
  if (ret == NULL)
    return (NULL);
  while (i < len && str[i])
    {
      ret[i] = str[i];
      i += 1;
    }
  ret[i] = 0;
  return (ret);
}
