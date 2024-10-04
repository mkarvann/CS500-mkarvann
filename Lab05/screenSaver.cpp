#include "screenSaver.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>

//Self-explanatory
ScreenSaver::ScreenSaver() {
  shape = sf::CircleShape(10.f);
  velocity = sf::Vector2f(0.0f, 0.0f);
  shape.setFillColor(sf::Color::White);
}

//Self-explanatory
ScreenSaver::ScreenSaver(float radius, sf::Vector2f cVelocity, sf::Color color) {
  shape = sf::CircleShape(radius);
  velocity = cVelocity;
  shape.setFillColor(color);
}

//We have to return shape as a reference!
sf::CircleShape &ScreenSaver::getShape() { return shape; }

//this will draw the sf::CircleShape member of ScreenSaver to the screen
//this will be inherited by all derived class, and shouldn't have to be overriden
void ScreenSaver::draw(sf::RenderWindow &window) { window.draw(getShape()); }

/*Here's some nifty code to resolve any collsions with a wall, by reversing
the velocity of the object to mimic bouncing, you can call this function
in your update functions to make sure your ScreenSaver doesn't wander off-screen*/
void ScreenSaver::checkWallCollision(int screenWidth, int screenHeight){
  sf::Vector2f position = getShape().getPosition();
  float diameter = getShape().getRadius() * 2;

  // Check if the circle hits the right wall
  if (position.x + diameter > screenWidth)
  {
    getShape().setPosition(screenWidth - diameter, position.y);
    velocity.x *= -1.f;
  }

  // Check if the circle hits the left wall
  if (position.x < 0)
  {
    getShape().setPosition(0, position.y);
    velocity.x *= -1.f;
  }

  // Check if the circle hits the top wall
  if (position.y < 0)
  {
    getShape().setPosition(position.x, 0);
    velocity.y *= -1.f;
  }

  // Check if the circle hits the bottom wall
  if (position.y + diameter > screenHeight)
  {
    getShape().setPosition(position.x, screenHeight - diameter);
    velocity.y *= -1.f;
  }
}

//TODO Define all necessary member functions for ClassicSaver, ColorChangingSaver, and CustomSaver Here

ClassicSaver::ClassicSaver(float radius, sf::Vector2f velocity, sf::Color color)
    : ScreenSaver(radius, velocity, color) {}

void ClassicSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    getShape().move(velocity * deltaTime);
    checkWallCollision(screenWidth, screenHeight);
}



ColorChangingSaver::ColorChangingSaver(float radius, sf::Vector2f velocity, float colorSpeed)
    : ClassicSaver(radius, velocity, sf::Color::Red), colorSpeed(colorSpeed), colorProgress(0.0f) {}

void ColorChangingSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    ClassicSaver::update(deltaTime, screenWidth, screenHeight);
    
    colorProgress += colorSpeed * deltaTime;
    if (colorProgress > 1.0f) colorProgress -= 1.0f;
    
    float r = std::sin(colorProgress * 2 * M_PI) * 127.5f + 127.5f;
    float g = std::sin((colorProgress + 0.33f) * 2 * M_PI) * 127.5f + 127.5f;
    float b = std::sin((colorProgress + 0.67f) * 2 * M_PI) * 127.5f + 127.5f;
    
    getShape().setFillColor(sf::Color(static_cast<sf::Uint8>(r), static_cast<sf::Uint8>(g), static_cast<sf::Uint8>(b)));
}

CustomSaver::CustomSaver(float radius, sf::Vector2f center, float speed)
    : ScreenSaver(radius, sf::Vector2f(0, 0), sf::Color::Green),
      angle(0), angularSpeed(speed), pulsateSpeed(2.0f), originalRadius(radius) {
    getShape().setPosition(center);
}

void CustomSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    angle += angularSpeed * deltaTime;
    if (angle > 2 * M_PI) angle -= 2 * M_PI;
    
    float x = std::sin(angle) * screenWidth * 0.25f;
    float y = std::sin(2 * angle) * screenHeight * 0.25f;
    
    getShape().setPosition(screenWidth / 2 + x, screenHeight / 2 + y);
    
    float scale = std::sin(angle * pulsateSpeed) * 0.2f + 1.0f;
    getShape().setRadius(originalRadius * scale);
    
    getShape().setOrigin(getShape().getRadius(), getShape().getRadius());
}