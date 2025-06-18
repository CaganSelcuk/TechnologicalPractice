#pragma once
#include <SFML/Window/Event.hpp>
#include <functional>
#include <vector>

typedef std::function <void(sf::Keyboard::Key)>     KlavyeFonksiyonu;
typedef std::vector <KlavyeFonksiyonu>              KlavyeFonksiyonListesi;

typedef std::function <void(sf::Event::MouseMoveEvent)> FareHareketFonksiyonu;
typedef std::vector < FareHareketFonksiyonu>            FareHareketFonkListesi;
typedef std::function<void(sf::Event::MouseButtonEvent)> FareTiklanmaFonksiyonu;
typedef std::vector<FareTiklanmaFonksiyonu>              FareTiklanmaFonksiyonListesi;
