#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

#include <Particle.hpp>
#include <Global.hpp>
#include <Helper.hpp>

        // default class
/* Particle::Particle() */
/* { */
/* 	pos=sf::Vector2f(900/2, 900/2); */
/* 	vel=sf::Vector2f(100, 0.6); */
/* 	acc=sf::Vector2f(0, 0); */
/* 	radius=10; */
/* 	mass=1; */
/* 	shape.setRadius(radius); */
/* 	shape.setFillColor(sf::Color::White); */
/* } */

// used to create random particles
Particle::Particle()
{
	radius=HelperFunc::randNum(std::rand(), MIN_RADIUS, MAX_RADIUS);
	pos=sf::Vector2f(HelperFunc::randNum(std::rand(), 0, (int)(WIDTH-2*radius)), 
			HelperFunc::randNum(std::rand(), 0, (int)(HEIGHT-2*radius)));

	vel=sf::Vector2f(HelperFunc::randNum(std::rand(), 0, MAX_VELOCITY), 
			HelperFunc::randNum(std::rand(), 0, MAX_VELOCITY));

	acc=sf::Vector2f(0, 0);
	mass=1;
	shape.setRadius(radius);
	shape.setFillColor(sf::Color::White);
}

Particle::Particle(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc, double radius, double mass, sf::Color color)
{
	pos=pos;
	vel=vel;
	acc=acc;
	radius=radius;
	mass=mass;
	shape.setFillColor(color);
	shape.setRadius(radius);
}


void Particle::check_wall_collision(sf::RenderWindow& window, double delta_time) {

	if (pos.x  <= 0) {
		vel.x *= -1;
		pos.x=0;

	}
	if (pos.x + 2*shape.getRadius() >= WIDTH) {
		vel.x *= -1;
		pos.x = WIDTH-shape.getRadius()*2;
	}

	if (pos.y <= 0) {
		vel.y *= -1;
		pos.y = 0;
	}

	if (pos.y + 2*shape.getRadius() >= HEIGHT) {
		vel.y *= -1;
		pos.y = HEIGHT-shape.getRadius()*2;
	}
}

void Particle::update(sf::RenderWindow& window, double delta_time)
{
	check_wall_collision(window, delta_time);

	pos.x = pos.x + vel.x*delta_time;
	pos.y = pos.y + vel.y*delta_time;

	shape.setPosition(pos);

	window.draw(shape);
}
