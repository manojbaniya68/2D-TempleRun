#include "BackGround.h"

BackGround::BackGround(sf::RenderWindow* win,float& deltaTime) :window(win),dt(deltaTime)
{
	initVariables();
	loadImage();
}

// private methods
void BackGround::initVariables()
{
	xdir1 = 0.f;
	ydir1 = 0.f;
	numSprites = 2;
	windowWidth = window->getSize().x;
	imagePositionOne = sf::Vector2f(0.f, 0.f);
	imagePositionTwo = sf::Vector2f(800.f, 0.f);
	collided = false;
}

void BackGround::loadImage()
{
	Texture.loadFromFile("./Assets/Background/bg.jpg");
	if (!roadTexture.loadFromFile("./Assets/Background/road.png"))
	{
		std::cout << "Error loading file" << std::endl;
	}
	for (int i = 0; i < numSprites; i++)
	{
		sf::Sprite sprite(roadTexture);
		xdir1 = window->getSize().x / sprite.getGlobalBounds().width;
		ydir1 = window->getSize().y / sprite.getGlobalBounds().height;
		sprite.setScale(xdir1/0.9, ydir1/0.37);
		sprite.setPosition(sf::Vector2f(i * windowWidth, -300.f));
		roadSprites.push_back(sprite);

		/*sf::Sprite sprite;
		roadSprite.setTexture(roadTexture);
		xdir1 = window->getSize().x / roadSprite.getGlobalBounds().width;
		ydir1 = window->getSize().y / roadSprite.getGlobalBounds().height;
		roadSprite.setScale(xdir1 / 0.9, ydir1 / 0.37);
		roadSprite.setPosition(sf::Vector2f(-100.f, -300.f));*/
	}
	

	for (int i = 0; i < numSprites; i++)
	{
		sf::Sprite sprite(Texture);
		xdir1 = window->getSize().x / sprite.getGlobalBounds().width;
		ydir1 = window->getSize().y / sprite.getGlobalBounds().height;
		sprite.setScale(xdir1, ydir1);
		sprite.setPosition(sf::Vector2f((i * windowWidth) - 20.f, 0.f));
		backGroundSprites.push_back(sprite);
	}
}

void BackGround::rectangle()
{
	rect.setSize(sf::Vector2f(1280.f, 200.f));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(sf::Vector2f(0.f, 450.f));
	window->draw(rect);
}

void BackGround::setCollideInfo(bool col)
{
	collided = col;
}


// Public methods
void BackGround::moves()
{
	if (!collided)
	{
		for (auto& sprite : backGroundSprites)
		{
			sprite.move(sf::Vector2f(-20 * dt, 0.f));
			if (sprite.getPosition().x <= -windowWidth)
			{
				sprite.setPosition(sf::Vector2f(sprite.getPosition().x + numSprites * windowWidth, 0.f));
			}
		}

		for (auto& sprite : roadSprites)
		{
			sprite.move(sf::Vector2f(-20 * dt, 0.f));
			if (sprite.getPosition().x <= -windowWidth)
			{
				sprite.setPosition(sf::Vector2f(sprite.getPosition().x + (numSprites * windowWidth), -300.f));
			}
		}
	}
	
}

void BackGround::render()
{
	if (!collided)
	{
		moves();
	}
	
	for (auto& sprite : backGroundSprites)
	{
		window->draw(sprite);
	}
	for (auto& sprite : roadSprites)
	{
		window->draw(sprite);
	}
	//rectangle();
}



