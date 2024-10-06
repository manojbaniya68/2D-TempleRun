#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include<iostream>
#include<random>
#include<fstream>
#include"Runner.h"
class Coin
{	
	private:
		sf::Texture Texture,stoneTexture;
		sf::Sprite stoneSprite;
		sf::RenderWindow* window;
		std::vector<sf::Sprite> coinSprites;
		sf::RectangleShape rects;
		sf::Event event;
		float dt, windowWidth;
		int Score,i,random_number,rand,a,b;


		float xdir1, ydir1;
		int numSprites,index,previousIndex;
		const float gravity = 0.25f;
		const float jumpStrength = -10.f;
		float jumpSpeed;
		bool is_jumping,is_jumping1;
		bool detectJump;
		bool collided;
		float velocityY;
		float groundLevel, topLevel;

		sf::Font font;

		
		bool indexs[5];
		// private member functions
		void initVariables();
		void loadImage();
		void coinCollision();
		void transparentRectangle();
		void moves();
		void coinCollection();
		void refresh();
		void update();
		void randomNumber();
		void jumpRect();
		void setJumpSpeed();
		void obstacles();
		void stoneCollision();
	
		//void pollEvents();
	public:
		
		Coin(sf::RenderWindow*, float& ,sf::Event&);
		~Coin() {};

		//public member funcions
		void render();
		void setBooleanValue(bool);
		bool getCollisionInfo();

		
		
	};



