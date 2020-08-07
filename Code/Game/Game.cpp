#include <SFML/Graphics.hpp>
#include "Game/Game.h"
#include "VectorFunctions/VectorFunctions.h"

sf::Clock Game::_timer{};
float Game::_deltaTime{};
void Game::deltaTime()
{
   Game::_deltaTime = Game::_timer.getElapsedTime().asSeconds();
}

Game::Game(std::string title, sf::Vector2u windowSize)
  : _title{title}, _windowSize{windowSize}
{
  start();
}

void Game::start()
{
  _window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _title);
  _window.setFramerateLimit(0);
}

void Game::pollEvents()
{
  while(_window.pollEvent(_event))
  {
    if (_event.type == sf::Event::Closed)
    {
      _window.close();
    }
  }
}

void Game::draw()
{
  _window.clear();

  _window.draw(_player._rec);

  _window.display();
}

void Game::update()
{
  Game::deltaTime();
  _player.update(_deltaTime);
  _timer.restart();
}

void Game::run()
{
  while (_window.isOpen())
  {
    pollEvents();

    update();
    draw();
    //std::cout << "FPS: " << 1.0 / _timer.getElapsedTime().asSeconds();
  }
}