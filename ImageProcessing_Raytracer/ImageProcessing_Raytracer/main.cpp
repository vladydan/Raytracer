#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "include/rt.h"
#include "include/obj.h"
#include "include/parsing.h"
#include "include/mlx_uses.h"
#include "include/utils.h"

static int	init_scene(t_rt *scene, const char *scene_name)
{
	char		**tab;
	std::string line;
	std::ifstream  infile(scene_name);

	scene->obj = NULL;
	scene->light = NULL;
	scene->cam = NULL;


	while (std::getline(infile, line))
	{
		if (!is_comment((char *)line.c_str()))
		{
			if ((tab = str_to_wordtab((char *)line.c_str())) == NULL)
				throw new std::exception(STR_WORDTAB_FAILED);
			if (check_line(tab) == 1)
				throw new std::exception("Bad file\n");
			if (my_strcmp(tab[1], EYE_PARSE))
				scene->cam = parse_cam(tab);
			else if (my_strcmp(tab[1], LIGHT_PARSE))
				scene->light = parse_light(tab, scene);
			else
				scene->obj = parse_obj(tab, scene);
		}
	}
	if (scene->cam == NULL)
		throw new std::exception("Bad file\n");
	return (0);
}

static int	init_params(t_mlx *param)
{
	param->width = W_WIDTH;
	param->height = W_HEIGHT;
	//param->image = new sf::Image(800, 600, sf::Color(0, 0, 0));
	param->image.create(W_WIDTH, W_HEIGHT, sf::Color(0, 0, 0));
	return (0);
}

int		main(const int ac, const char **av)
{
	t_rt		*rt;
	t_mlx		param;
	int		fd;
	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "RayTracer");
	sf::Texture texture;
	sf::Sprite sprite;
	if (ac != 2) {
		std::cerr << USAGE;
		return 1;
	}

	rt = (t_rt *)xmalloc(sizeof(t_rt));
	try {
		if (init_scene(rt, av[1]) == 1)
			return 1;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
		return (1);
	}
	init_params(&param);
	calc_loop(rt, &param);
	texture.create(W_WIDTH, W_HEIGHT);
	texture.update(param.image);
	sprite.setTexture(texture);

	window.draw(sprite);
	window.display();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

//		window.clear();
	//	window.display();
	}
	return (0);
}
