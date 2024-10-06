#include"Dragon.h"
#include"Runner.h"
#include"BackGround.h"

#include"Coin.h"
int main()
{
	

	sf::Event event;
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("./Assets/Audio/gamePlay.wav"))
	{
		std::cout<<"Error in loading audio";
	}

	


	sf::Sound sound(buffer);
	sf::RenderWindow* window;
	sf::Clock clock;
	bool isGameEnd = false;

	window = new sf::RenderWindow(sf::VideoMode(1280.f, 720.f), "Tmeple Run");
	window->setFramerateLimit(60);
	float deltaTime = clock.restart().asSeconds() * 1.2;


	Dragon dragon(window,deltaTime);
	Runner runner(window, deltaTime,event);
	BackGround backGround(window, deltaTime);
	Coin coin(window, deltaTime,event);

	sf::Texture gameOverTexture;
	sf::Sprite gameOverSprite;
	float xdir = 0, ydir = 0;
	gameOverTexture.loadFromFile("./Assets/GameOver/gameOver.png");
	gameOverSprite.setTexture(gameOverTexture);

	xdir = window->getSize().x / gameOverSprite.getGlobalBounds().width;
	ydir = window->getSize().y / gameOverSprite.getGlobalBounds().height;
	gameOverSprite.setScale(xdir, ydir);
	gameOverSprite.setPosition(sf::Vector2f(0.f, 0.f));
	


	sound.play();
	while (window->isOpen())
	{	
		//window->pollEvent(event);
		backGround.moves();
		window->clear();
	
		backGround.render();
		coin.setBooleanValue(runner.getJumpingStatus());
		backGround.setCollideInfo(coin.getCollisionInfo());
		runner.setCollisionInfo(coin.getCollisionInfo());
		dragon.setCollisionInfo(coin.getCollisionInfo());
		//isGameEnd = dragon.endGameInfo();
		/*if (isGameEnd)
		{
			window->close();
		}*/
		dragon.render();
		runner.render();
		coin.render();
		if (dragon.isGameEnd())
		{
			window->draw(gameOverSprite);
		}
		
	
		
		window->display();
	}

	delete window;

	
}

