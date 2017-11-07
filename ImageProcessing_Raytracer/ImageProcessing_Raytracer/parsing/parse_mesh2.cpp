#include <stdlib.h>
#include <iostream>
#include "obj.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

int		count_obj(int fd, int *vert, int *face, int *normal)
{
  char		*line;

  *vert = 0;
  *face = 0;
  *normal = 0;
  // TODO HERE
 // while ((line = get_next_line(fd)))
 //   {
 //     if (line[0] == 'v' && line[1] == ' ')
	//*vert += 1;
 //     else if (line[0] == 'f' && line[1] == ' ')
	//*face += 1;
 //     else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
	//*normal += 1;
 //     free(line);
 //   }
  return (0);
}

int	get_vertice(t_mesh *mesh, char *line, int i)
{
  char	**tab;

  tab = str_to_wordtab(line);
  if (tab[1] == NULL || tab[2] == NULL || tab[3] == NULL)
  {
	  std::cerr << "Need x, y and z for v!\n";
	  return 1;
  }
  mesh->vertice[i].x = atof(tab[1]);
  mesh->vertice[i].y = atof(tab[2]);
  mesh->vertice[i].z = atof(tab[3]);
  free_tab(tab);
  return (0);
}

int	get_normal(t_mesh *mesh, char *line, int i)
{
  char	**tab;

  tab = str_to_wordtab(line);
  if (tab[1] == NULL || tab[2] == NULL || tab[3] == NULL)
  {
	  std::cerr << "Need x, y and z for vn!\n";
	  return 1;
  }
  mesh->normal[i].x = atof(tab[1]);
  mesh->normal[i].y = atof(tab[2]);
  mesh->normal[i].z = atof(tab[3]);
  free_tab(tab);
  return (0);
}

int	to_normal(char *str)
{
  int	i;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    i += 1;
  i += 1;
  while (str[i] >= '0' && str[i] <= '9')
    i += 1;
  i += 1;
  return (i);
}
