#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>

#include<iostream>
class Runner
{
private:
	sf::Event event;
	sf::Texture runnerTexturePhase[8];
	sf::RenderWindow* window;
	sf::Vector2f runnerPosition;
	std::vector<sf::Sprite> runnerSprite;

	int numSprites;
	float dt;
	float xdir1, ydir1;
	float startTime, legMovementTime;
	const float gravity = 0.25f;
	const float jumpStrength = -10.f;
	float jumpSpeed;
	float velocityY;
	float groundLevel,topLevel;
	bool isJumping,collided;

	

	void initVariables();
	void loadImage();
	void draw();
	void jump();
	

public:
	
	sf::RectangleShape rect,rectObstacle;
	Runner(sf::RenderWindow *,float&,sf::Event&);
	~Runner() {};

	//accessor
	bool getJumpingStatus();
	void setCollisionInfo(bool);

     void render();	 
	 void pollEvent();
};

