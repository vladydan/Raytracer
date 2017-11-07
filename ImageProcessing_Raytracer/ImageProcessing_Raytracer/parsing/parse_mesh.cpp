#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include "obj.h"

void	init_face(int v[6], t_mesh *mesh, int i)
{
  mesh->face[i].p1 = v[0];
  mesh->face[i].p2 = v[1];
  mesh->face[i].p3 = v[2];
  init_vector(&mesh->face[i].normal,
	      mesh->normal[v[3]].x + mesh->normal[v[4]].x
	      + mesh->normal[v[5]].x,
	      mesh->normal[v[3]].y + mesh->normal[v[4]].y
	      + mesh->normal[v[5]].y,
	      mesh->normal[v[4]].z + mesh->normal[v[4]].z
	      + mesh->normal[v[5]].z);
  normalize(&mesh->face[i].normal);
  mesh->face[i].d = -1 * (mesh->face[i].normal.x * mesh->vertice[v[0]].x
			  + mesh->face[i].normal.y * mesh->vertice[v[0]].y
			  + mesh->face[i].normal.z * mesh->vertice[v[0]].z);
}

int	get_face(t_mesh *mesh, char *line, int i)
{
  char	**tab;
  int	v[6];

  tab = str_to_wordtab(line);
  if (tab[1] == NULL || tab[2] == NULL || tab[3] == NULL)
	  throw new std::exception("Need three points to define a face!\n");
  v[0] = atoi(tab[1]) - 1;
  v[1] = atoi(tab[2]) - 1;
  v[2] = atoi(tab[3]) - 1;
  v[3] = atoi(tab[1] + to_normal(tab[1])) - 1;
  v[4] = atoi(tab[2] + to_normal(tab[2])) - 1;
  v[5] = atoi(tab[3] + to_normal(tab[3])) - 1;
  if (v[3] < 0 || v[3] >= mesh->count_normal || v[4] < 0 ||
	  v[4] >= mesh->count_normal ||
	  v[5] < 0 || v[5] >= mesh->count_normal)
  {
	  std::cerr << "Unkown normal!\n";
	  return 1;
  }
  if (v[0] < 0 || v[0] >= mesh->count_vert || v[1] < 0 ||
	  v[1] >= mesh->count_vert || v[2] < 0 || v[2] >= mesh->count_vert)
  {
	  std::cerr << "Unkown normal!\n";
	  return 1;
  }
  init_face(v, mesh, i);
  free_tab(tab);
  return (0);
}

//TODO HERE
t_mesh		*init_mesh(t_mesh *mesh, int fd,
			  int count_normal, int count_face)
{
  int		count_vert;
  char		*line;

 // count_vert = 0;
 // while ((line = get_next_line(fd)))
 //   {
 //     if (line[0] == 'v' && line[1] == ' ')
	//{
	//  if (get_vertice(mesh, line, count_vert++))
	//    return (NULL);
	//}
 //     else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
	//{
	//  if (get_normal(mesh, line, count_normal++))
	//    return (NULL);
	//}
 //     else if (line[0] == 'f' && line[1] == ' ')
	//{
	//  if (get_face(mesh, line, count_face++))
	//    return (NULL);
	//}
 //     free(line);
 //   }
  return (mesh);
}

//TODO MESH TO FIX
t_mesh		*get_mesh(char *file)
{
  int		count_vert;
  int		count_normal;
  int		count_face;
  int		fd;
  t_mesh	*mesh;

  //if ((fd = open(file, O_RDONLY)) == -1)
  //  return (NULL);
  //count_obj(fd, &count_vert, &count_face, &count_normal);
  //mesh = xmalloc(sizeof(t_mesh));
  //mesh->count_vert = count_vert;
  //mesh->count_normal = count_normal;
  //mesh->count_face = count_face;
  //mesh->vertice = xmalloc(sizeof(t_vector) * count_vert);
  //mesh->normal = xmalloc(sizeof(t_vector) * count_normal);
  //mesh->face = xmalloc(sizeof(t_face) * count_face);
  //lseek(fd, 0, SEEK_SET);
  //mesh = init_mesh(mesh, fd, 0, 0);
  return (mesh);
}
