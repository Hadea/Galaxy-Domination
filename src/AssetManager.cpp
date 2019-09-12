#include "AssetManager.h"

AssetManager::AssetManager()
{
	//mTextures = new std::map<std::string, sf::Texture>();
	//mFonts = new std::map<std::string, sf::Font>();
}

AssetManager::~AssetManager()
{
	//delete(mTextures);
	//delete(mFonts);
}

void AssetManager::TextureLoad(std::string pIdentifier, std::string pFileName)
{
	if ( mTextures.count(pIdentifier) == 0) //TODO: Reference Counting
	{
		sf::Texture tex;
		if (tex.loadFromFile(pFileName))
		{
			mTextures[pIdentifier] = tex;
		}
		else
		{
			std::cout << "failed to load " << pIdentifier;
		}
	}
}

void AssetManager::FontLoad(std::string pIdentifier, std::string pFileName)
{
	if (!mFonts.count(pIdentifier)) //TODO: Reference Counting
	{
		sf::Font font;
		if (font.loadFromFile(pFileName))
		{
			mFonts.at(pIdentifier) = font;
		}
	}
}

void AssetManager::SoundLoad(std::string pIdentifier, std::string pFileName)
{
	if (!mSound.count(pIdentifier)) //TODO: Reference Counting
	{
		sf::SoundBuffer soundBuffer;
		if (soundBuffer.loadFromFile(pFileName))
		{
			mSound[pIdentifier] = soundBuffer;
		}
	}
}

sf::Texture& AssetManager::TextureGet(std::string pIdentifier)
{
	return mTextures[pIdentifier];
}

sf::Font& AssetManager::FontGet(std::string pIdentifier)
{
	return mFonts[pIdentifier];
}

sf::SoundBuffer& AssetManager::SoundGet(std::string pIdentifier)
{
	return mSound[pIdentifier];
}
