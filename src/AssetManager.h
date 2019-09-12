#pragma once
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

class AssetManager
{
public:
	AssetManager();
	~AssetManager();
	void TextureLoad(std::string pIdentifier, std::string pFileName);
	void FontLoad(std::string pIdentifier, std::string pFileName);
	sf::Texture& TextureGet(std::string pIdentifier);
	sf::Font& FontGet(std::string pIdentifier);

	//TODO: Texture unload
	//TODO: Font unload
	//TODO: Audio load
	//TODO: Audio unload

private:
	std::map<std::string, sf::Texture> mTextures;
	std::map<std::string, sf::Font> mFonts;
};

