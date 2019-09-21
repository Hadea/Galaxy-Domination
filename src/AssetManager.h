#pragma once
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class AssetManager
{
public:
	AssetManager();
	~AssetManager();
	void TextureLoad(std::string pIdentifier, std::string pFileName);
	void FontLoad(std::string pIdentifier, std::string pFileName);
	void SoundLoad(std::string pIdentifier, std::string pFileName);
	sf::Texture& TextureGet(std::string pIdentifier);
	sf::Font& FontGet(std::string pIdentifier);
	sf::SoundBuffer& SoundGet(std::string pIdentifier);
	void TextureUnload(std::string pIdentifier);
	void FontUnload(std::string pIdentifier);
	void SoundUnload(std::string pIdentifier);

private:
	std::map<std::string, sf::Texture> mTextures;
	std::map<std::string, sf::Font> mFonts;
	std::map<std::string, sf::SoundBuffer> mSounds;
};

