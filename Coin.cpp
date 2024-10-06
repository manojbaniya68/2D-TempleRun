#include "Coin.h"
Coin::Coin(sf::RenderWindow* win, float& deltaTime, sf::Event& ev) :window(win), dt(deltaTime),event(ev)
{
	initVariables();
	loadImage();
	transparentRectangle();
	randomNumber();
}

// private member functions
void Coin::initVariables()
{
    a = 0;
	b = 0;
	i = 799;
	xdir1 = 0.f;
	ydir1 = 0.f;
	numSprites = 5; 

	windowWidth = static_cast<float> (window->getSize().x);

	index = -1;
	previousIndex = -2;
	Score = 0;
	rand = 0;
	random_number = 0;

	for (auto &index : indexs) { index = true; }

	velocityY = 10.f;
	groundLevel = 500.f;
	topLevel = 100.f;
	detectJump = true;
	is_jumping = false; 
	is_jumping1 = false;
	collided = false;
	jumpSpeed = jumpStrength;
	
}

void Coin::loadImage()
{
	Texture.loadFromFile("./Assets/Coin/coin.png");
	stoneTexture.loadFromFile("./Assets/Obstacles/stone.png");

	stoneSprite.setTexture(stoneTexture);
	xdir1 = window->getSize().x / stoneSprite.getGlobalBounds().width;
	ydir1 = window->getSize().y / stoneSprite.getGlobalBounds().height;
	stoneSprite.setScale(xdir1 / 6, ydir1 / 3.5);
	stoneSprite.setPosition(sf::Vector2f(1500.f, 320.f));

	for (int i = 0; i < numSprites; i++)
	{
		sf::Sprite sprite(Texture);
		xdir1 = window->getSize().x / sprite.getGlobalBounds().width;
		ydir1 = window->getSize().y / sprite.getGlobalBounds().height;
		sprite.setScale(xdir1/20, ydir1/20);
		sprite.setPosition(sf::Vector2f((i + 9) * 150.f, 370.f));
		coinSprites.push_back(sprite);
	}

	
}

void Coin::moves()
{
	/*
	  - moves the coin
	*/
	if (!collided)
	{
		stoneSprite.move(sf::Vector2f(-40 * dt, 0.f));
		for (auto& sprite : coinSprites)
		{
			sprite.move(sf::Vector2f(-40 * dt, 0.f));
		}
	}
	
}

void Coin::coinCollision()
{	
	if (random_number == 0)
	{
		if (coinSprites[0].getGlobalBounds().intersects(rects.getGlobalBounds())) { index = 0; }
		if (coinSprites[1].getGlobalBounds().intersects(rects.getGlobalBounds())) { index = 1; }
	}

	if (rand == 2)
	{
		if (coinSprites[2].getGlobalBounds().intersects(rects.getGlobalBounds())) { index = 2; }
	}
	if (coinSprites[3].getGlobalBounds().intersects(rects.getGlobalBounds())) { index = 3; }
	if (coinSprites[4].getGlobalBounds().intersects(rects.getGlobalBounds())) { index = 4; }
		

}

void Coin::refresh()
{
	if (index == 4)
	{
		index = -1;
		previousIndex = -2;
		for (auto& index : indexs) index = true;
	}
}

void Coin::update()
{
	
	b++;
	if (b == 800)
	{
		for (int i = 0; i < numSprites; i++)
		{
			coinSprites[i].setPosition(sf::Vector2f((i + 9) * 150.f, 370.f));

		}
		refresh();
	}

	
	a++;
	if (a == 420)
	{
		for (int i = 0; i < numSprites; i++)
		{
			stoneSprite.setPosition(sf::Vector2f(1200.f, 320.f));

		}
		if (a == 420) a = 0;
		refresh();
	}


	if (b == 800)
	{
		b = 0;
		randomNumber();
	}
}

void Coin::randomNumber()
{
	std::random_device rd; 
	std::mt19937 gen(rd()); 

	
	std::uniform_int_distribution<> dis(0, 4); 

	// Generate a random number
	 random_number = dis(gen);
	 rand = dis(gen);
}

void Coin::transparentRectangle()
{
	rects.setSize(sf::Vector2f(50.f, 150.f));
	rects.setOutlineThickness(2.f);
	rects.setOutlineColor(sf::Color::Transparent);
	rects.setFillColor(sf::Color::Transparent);
	rects.setPosition(sf::Vector2f(430.f, 250.f));
}

void Coin::jumpRect()
{
	setJumpSpeed();
	if (is_jumping1)
	{		
		
		if (rects.getPosition().x >= 140.f)
		{
			rects.move(0.f, jumpSpeed);
			jumpSpeed += gravity;
		}
			if (rects.getPosition().y >= 250)
			{
				is_jumping1 = false;
				detectJump = true;
				jumpSpeed = 0.f;
			}
		
		
	}
}

void Coin::setJumpSpeed()
{
	if (detectJump)
	{
		jumpSpeed = jumpStrength;
		detectJump = false;
	}
	if (is_jumping)
	{

		is_jumping1 = true;
		is_jumping = false;
	}
}

void Coin::obstacles()
{

}

void Coin::stoneCollision()
{
	if (stoneSprite.getGlobalBounds().intersects(rects.getGlobalBounds()))
	{
		collided = true;
	}
}

bool Coin::getCollisionInfo()
{
	return collided;
}

void Coin::coinCollection()
{
	switch (index)
	{
	case 0 :
		indexs[0] = false;
		break;
	case 1:
		indexs[1] = false;
		break;
	case 2:
		indexs[2] = false;
		break;
	case 3:
		indexs[3] = false;
		break;
	case 4:
		indexs[4] = false;
		break;
	}	

	if ((index == 0 || index == 1 || index == 2 || index == 3 || index == 4) && (index != previousIndex))
	{
		Score++;
		previousIndex = index;

		system("cls");
		std::ofstream outf("score.dat", std::ios::binary | std::ios::out);
		outf.write(reinterpret_cast<char*>(&Score), sizeof(Score));
		outf.close();

		std::ifstream inf("score.dat", std::ios::binary | std::ios::in);
		inf.read(reinterpret_cast<char*>(&Score), sizeof(Score));
		inf.close();
		std::cout << "Score : " << Score << std::endl;
	}

	if (random_number == 0)
	{
		if (indexs[0]) window->draw(coinSprites[0]);
		if (indexs[1]) window->draw(coinSprites[1]);
	}
	if (rand == 2)
	{
		if (indexs[2]) window->draw(coinSprites[2]);
		
	}
	if (indexs[3]) window->draw(coinSprites[3]);
	if (indexs[4]) window->draw(coinSprites[4]);



}






//public member functions
void Coin::render()
{
	moves();
	coinCollection();
	stoneCollision();
	update();
	window->draw(rects);
	window->draw(stoneSprite);
	coinCollision();
	jumpRect();
}

void Coin::setBooleanValue(bool boolValue)
{
	is_jumping = boolValue;
}

