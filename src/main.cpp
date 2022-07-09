#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

#include <Particle.hpp>
#include <Global.hpp>
#include <type_traits>
#include <Helper.hpp>


int main()
{
	sf::Clock clock;
	std::vector<Particle> particle_array(NUM_PARTICLES);

	std::srand(time(NULL)); // init rand seed

	for (int i=0; i < NUM_PARTICLES; i++){
		Particle p;
		particle_array.push_back(p); 
	}

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "C++ App");
	window.setFramerateLimit(FPS);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		sf::Time delta_time = clock.restart();

		for (int i=0; i < NUM_PARTICLES; i++) {
			particle_array[i].update(window, delta_time.asSeconds());
		}
		window.display();
	}

	return 0;
}
