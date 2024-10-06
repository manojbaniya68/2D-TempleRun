//#include "Game.h"
//
//// private member functions
//void Game::initVariables()
//{
//	this->window = nullptr;
//}
//
//void Game::initWindow()
//{
//	this->videoMode.width = 800;
//	this->videoMode.height = 600;
//	this->window = new sf::RenderWindow(this->videoMode, "Temple Run");
//}
//
////float Game::getDeltaTime()
////{
////	/*
////	    -return delta time
////		-delta time is the time difference between two frames.
////	*/
////	sf::Clock clock;
////	return clock.restart().asSeconds();
////}
//
////constructor
//Game::Game()
//{
//	//this->initVariables();
//	this->initWindow();
//}
//
//Game::Game(int a)
//{
//	std::cout << "Consturctor ";
//}
//
////destructor
//Game::~Game()
//{
//	std::cout<<"Game destructor:\n";
//	//delete this->window;
//}
//
//
////Accessor
//const bool Game::running() const
//{
//	return this->window->isOpen();
//}
//
//
//
////Public member functions
//void Game::pollEvent()
//{
//	while (this->window->pollEvent(this->event))
//	{
//		switch (event.type)
//		{
//			// window will be closed when escape key is pressed in keyboard
//		case sf::Event::KeyPressed:
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//				this->window->close();
//			break;
//
//		case sf::Event::Closed:
//			this->window->close();
//			break;
//		}
//	}
//}
//
//void Game::update()
//{
//	this->pollEvent();
//}
//
//void Game::render()
//{
//	// clear() will clear the old frame.
//	this->window->clear();
//	//this->window->draw(dragon.dragonSprite());
//	//this->window->draw(dragon.getDragonSprite());
//	//dragon.drawDragon();
//	//drawDragon();
//	//window->draw(dragonSpritePhase);
//	this->window->display();
//}
//
//
//
