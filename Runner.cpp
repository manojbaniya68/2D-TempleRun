#include "Runner.h"

Runner::Runner(sf::RenderWindow *win,float& deltaTime,sf::Event& ev):window(win),dt(deltaTime),event(ev)
{
	initVariables();
	loadImage();
}

void Runner::initVariables()
{
	runnerPosition = sf::Vector2f(300.f, 190.f);
	xdir1 = 0.f;
	ydir1 = 0.f;
	startTime = 0.f;
	legMovementTime = 2.f;
	numSprites = 8;
	velocityY = 10.f;
	groundLevel = 190.f;
	topLevel = 100.f;
	isJumping = false;
	collided = false;
	jumpSpeed = 0.f;
}

void Runner::pollEvent()
{
		while (this->window->pollEvent(this->event))
		{

			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					this->window->close();
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && runnerSprite[0].getPosition().y >= 190.f) 
				{
					if (!collided)
					{
						isJumping = true;
						jumpSpeed = jumpStrength;
					}
					
				}
				break;

			case sf::Event::Closed:
				this->window->close();
				break;

			}
		}
}

void Runner::loadImage()
{
	runnerTexturePhase[0].loadFromFile("./Assets/Runner/1.png");
	runnerTexturePhase[1].loadFromFile("./Assets/Runner/2.png");
	runnerTexturePhase[2].loadFromFile("./Assets/Runner/3.png");
	runnerTexturePhase[3].loadFromFile("./Assets/Runner/4.png");
	runnerTexturePhase[4].loadFromFile("./Assets/Runner/5.png");
	runnerTexturePhase[5].loadFromFile("./Assets/Runner/6.png");
	runnerTexturePhase[6].loadFromFile("./Assets/Runner/7.png");
	runnerTexturePhase[7].loadFromFile("./Assets/Runner/8.png");

	for (int i = 0; i < numSprites; i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(runnerTexturePhase[i]);
		xdir1 = window->getSize().x / sprite.getGlobalBounds().width;
		ydir1 = window->getSize().y / sprite.getGlobalBounds().height;
		sprite.setScale(xdir1 / 4, ydir1 / 2);
		sprite.setPosition(runnerPosition);
		runnerSprite.push_back(sprite);
	}	


}

void Runner::draw()
{
	/*
		- draw the runner.
		- makes the leg animation of runner.
		- can control the speed of leg motion.
	*/
	if (!collided)
	{
		if (startTime <= legMovementTime)
		{
			window->draw(runnerSprite[0]);
			startTime += dt;
		}
		else if (startTime > legMovementTime && startTime <= legMovementTime + 1)
		{
			window->draw(runnerSprite[1]);
			startTime += dt;
		}
		else if (startTime > legMovementTime + 1 && startTime <= legMovementTime + 2)
		{
			window->draw(runnerSprite[2]);
			startTime += dt;
		}
		else if (startTime > legMovementTime + 2 && startTime <= legMovementTime + 3)
		{
			window->draw(runnerSprite[3]);
			startTime += dt;
		}
		else if (startTime > legMovementTime + 3 && startTime <= legMovementTime + 4)
		{
			window->draw(runnerSprite[4]);
			startTime += dt;
		}
		else if (startTime > legMovementTime + 4 && startTime <= legMovementTime + 5)
		{
			window->draw(runnerSprite[5]);
			startTime += dt;
		}
		else if (startTime > legMovementTime + 5 && startTime <= legMovementTime + 6)
		{
			window->draw(runnerSprite[6]);
			startTime += dt;
		}
		else if (startTime > legMovementTime + 6 && startTime <= legMovementTime + 7)
		{
			window->draw(runnerSprite[7]);
			startTime += dt;

			if (startTime >= legMovementTime + 7)
			{
				startTime = 0.f;
			}

		}
	}
	else
	{
		window->draw(runnerSprite[0]);
	}
	
	
}
void Runner::jump()
{
	if (isJumping)
	{
		if (runnerSprite[0].getPosition().x >= topLevel)
		{   
		     for (auto& sprite : runnerSprite)
		     {
			    sprite.move(0.f, jumpSpeed);
		     }
		     jumpSpeed += gravity;
		}
		if (runnerSprite[0].getPosition().y >= groundLevel)
		{
			isJumping = false;
			jumpSpeed = 0.f;
		}
	}
}

bool Runner::getJumpingStatus()
{
	return isJumping;
}

void Runner::setCollisionInfo(bool col)
{
	collided = col;
}

void Runner::render()
	{
		pollEvent();
		draw();
		jump();
	}

	



