#include <iostream>
#include "utils.h"

unsigned char	atouc(char *str)
{
  unsigned char	ret;
  int		i;

  ret = 0;
  i = 0;
  while (str[i])
    {
	  if (str[i] < '0' || str[i] > '9' || ret * 10 + str[i] - '0' > 255)
	  {
		  std::cerr << NB_ERROR;
		  return 0;
	  }
      ret = (ret * 10) + str[i] - '0';
      i += 1;
    }
  return (ret);
}
