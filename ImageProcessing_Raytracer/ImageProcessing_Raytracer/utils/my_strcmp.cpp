int		my_strcmp(char *str_1, char *str_2)
{
  int		i;

  i = 0;
  while (str_1[i] && str_2[i])
    {
      if (str_1[i] != str_2[i])
	return (0);
      i++;
    }
  if (str_1[i] || str_2[i])
    return (0);
  return (1);
}
