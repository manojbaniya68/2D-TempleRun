#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>

#include<iostream>

class Dragon
{
private:
	sf::RenderWindow* window;
	sf::Texture dragonTexturePhase[8];
	std::vector<sf::Sprite> dragonSprite;
	sf::Texture gameOverTexture;
	sf::Sprite gameOverSprite;

	float xdir1, ydir1,xdir2,ydir2;
	int numSprites;
	float dt;
	float startTime,wingMovement;
	bool collided,isGameOver;
	bool endDetect;
    

	void initVariables();
	void loadImage();	
	void draw();
	void move();

public:
	Dragon(sf::RenderWindow *,float&);
	~Dragon();	

	void setCollisionInfo(bool);
	void gameOver();
	bool isGameEnd();
	void render();
};

