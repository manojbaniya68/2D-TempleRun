#include "Dragon.h"

//Constructor
Dragon::Dragon(sf::RenderWindow *win,float& deltaTime):window(win),dt(deltaTime)
{
	std::cout << dt << std::endl;
	initVariables();
	loadImage();
}

Dragon::~Dragon()
{
	 
}

//Private member functions
void Dragon::initVariables()
{
	xdir1 = 0.f;
	ydir1 = 0.f;
	xdir2 = 0.f;
	ydir2 = 0.f;
	numSprites = 7;
	startTime = 0.f;
	wingMovement = 2;
	collided = false;
	endDetect = false;
	isGameOver = false;
}

void Dragon::loadImage()
{
	dragonTexturePhase[0].loadFromFile("./Assets/Dragon/1.png");
	dragonTexturePhase[1].loadFromFile("./Assets/Dragon/2.png");
	dragonTexturePhase[2].loadFromFile("./Assets/Dragon/3.png");
	dragonTexturePhase[3].loadFromFile("./Assets/Dragon/4.png");
	dragonTexturePhase[4].loadFromFile("./Assets/Dragon/5.png");
	dragonTexturePhase[5].loadFromFile("./Assets/Dragon/6.png");
	dragonTexturePhase[6].loadFromFile("./Assets/Dragon/7.png");
	//dragonTexturePhase[6].loadFromFile("./Assets/Dragon/7.png");

	for (int i = 0; i < numSprites; i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(dragonTexturePhase[i]);
		xdir1 = window->getSize().x / sprite.getGlobalBounds().width;
		ydir1 = window->getSize().y / sprite.getGlobalBounds().height;
		sprite.setScale(xdir1 / 4, ydir1 / 2);
		sprite.setPosition(sf::Vector2f(10.f, 80.f));
		dragonSprite.push_back(sprite);
	}

	  xdir1 = window->getSize().x / gameOverSprite.getGlobalBounds().width;
	  ydir1 = window->getSize().y / gameOverSprite.getGlobalBounds().height;
	  gameOverSprite.setScale(xdir1, ydir1);
	  gameOverSprite.setPosition(sf::Vector2f(0.f, 0.f));
}

void Dragon::draw()
{	
	/*
	    - draw the dragon.
		- makes the flying animation of dragon.
		- can control the speed of wing motion.
	*/	
	if (dragonSprite[0].getPosition().x <= 195.f)
	{
		if (startTime <= wingMovement)
		{
			window->draw(dragonSprite[0]);
			startTime += dt;
		}
		else if (startTime > wingMovement && startTime <= wingMovement + 1)
		{
			window->draw(dragonSprite[1]);
			startTime += dt;

		}
		else if (startTime > wingMovement + 1 && startTime <= wingMovement + 2)
		{
			window->draw(dragonSprite[2]);
			startTime += dt;
		}
		else if (startTime > wingMovement + 2 && startTime <= wingMovement + 3)
		{
			window->draw(dragonSprite[3]);
			startTime += dt;
		}
		else if (startTime > wingMovement + 3 && startTime <= wingMovement + 4)
		{
			window->draw(dragonSprite[4]);
			startTime += dt;
		}
		else if (startTime > wingMovement + 4 && startTime <= wingMovement + 5)
		{
			window->draw(dragonSprite[5]);
			startTime += dt;
		}
		else if (startTime > wingMovement + 5 && startTime <= wingMovement + 6)
		{
			window->draw(dragonSprite[6]);
			startTime += dt;

			if (startTime >= wingMovement + 6)
			{
				startTime = 0.f;
			}
		}
	}
	else
	{
		window->draw(dragonSprite[0]);
	}
}

void Dragon::move()
{
	if (collided)
	{
		if (dragonSprite[0].getPosition().x <= 195.f)
		{
			for (auto& sprite : dragonSprite)
			{
				sprite.move(dt * 10.f, .1f);
			}
		}
		else
		{
			isGameOver = true;
		}
		
	}
	
}

void Dragon::setCollisionInfo(bool col)
{
	collided = col;
}

void Dragon::gameOver()
{
	//dragonSprite[0].getPosition().x >= 190.f;
	if (isGameOver)
	{
		window->draw(gameOverSprite);
	}
	
}

bool Dragon::isGameEnd()
{
	return isGameOver;
}

void Dragon::render()
{
		draw();
		gameOver();
		move();
}



