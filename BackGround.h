#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
//#include<SFML/Network.hpp>

#include<iostream>
class BackGround
{
private:
	sf::Texture Texture,roadTexture;
	sf::RenderWindow* window;
	sf::Event event;
	sf::Vector2f imagePositionOne, imagePositionTwo;
	sf::RectangleShape rect;
	std::vector<sf::Sprite> backGroundSprites;
	std::vector<sf::Sprite> roadSprites;
	float dt,windowWidth;

	float xdir1, ydir1;
	int numSprites;
	bool collided;
	//private methods
	void initVariables();
	void loadImage();
	void rectangle();

public:
	BackGround(sf::RenderWindow*,float&);
	~BackGround() {};

	// Public methods
	void setCollideInfo(bool);
	void render();
	void moves();
};



