/*
 * Copyright 2010 Daniel Albano
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "Language.h"
#include <fstream>

/**
 * Initializes an empty language file.
 */
Language::Language() : _strings()
{

}

/**
 *
 */
Language::~Language()
{
	
}

/**
 * Loads a series of null-terminated std::strings contained in
 * a raw text file into the Language. IDs are determined
 * automatically.
 * @param filename Filename of the DAT language.
 * @sa http://www.ufopaedia.org/index.php?title=GeoScape_String_Files
 */
void Language::loadDat(std::string filename)
{
	_strings.clear();
	
	// Load file and put text in vector
	std::ifstream txtFile (filename.c_str(), std::ios::in | std::ios::binary);
	if (!txtFile)
	{
		throw "Failed to load DAT";
	}
	
	char value[1];
	std::string buffer;

	while (txtFile.read(value, 1))
	{
		if (value[0] != '\0')
		{
			buffer += value[0];
		}
		else
		{
			_strings.push_back(buffer);
			buffer.clear();
		}
	}

	if (!txtFile.eof())
		throw "Invalid data from file";

	txtFile.close();
}

/**
 * Returns the localizable std::string with the specified ID.
 * @param id ID of the std::string.
 * @return String with the request ID.
 */
std::string Language::getString(LangString id)
{
	return _strings[id];
}
