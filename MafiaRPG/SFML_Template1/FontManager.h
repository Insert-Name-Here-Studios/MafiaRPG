#pragma once

#include "SFML/Graphics.hpp"
#include "ResourceManager.h"

class FontManager : public ResourceManager<FontManager, sf::Font>
{
public:
	FontManager() : ResourceManager("data/fonts/fonts.txt") {}

	sf::Font* Load(const string& fileName)
	{
		sf::Font* font = new sf::Font(); //allocate memory on heap

											   //if load fails just delete allocated memory and reset it to NULL.
		if (!font->loadFromFile("data/fonts/" + fileName))
		{
			delete font;
			font = NULL;
			std::cerr << "failed to load font" << endl;
		}

		//otherwise return the texture
		return font;
	}
};

