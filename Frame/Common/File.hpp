/****************************************************************************

Git <https://github.com/sniper00/MoonNetLua>
E-Mail <hanyongtao@live.com>
Copyright (c) 2015-2016 moon
Licensed under the MIT License <http://opensource.org/licenses/MIT>.

****************************************************************************/

#pragma once
#include <fstream>
#include <vector>
#include <string>

namespace moon
{
	class File
	{
	public:
		static std::string ReadAllText(const std::string& path, std::ios::openmode Mode =std::ios::in)
		{
			std::fstream is(path, Mode);
			if (is.is_open())
			{
				// get length of file:
				is.seekg(0, is.end);
				size_t length = static_cast<size_t>(is.tellg());
				is.seekg(0, is.beg);

				std::string tmp(length, '\0');
				is.read(&tmp.front(), length);

				if (is)
				{
					//all characters read successfully
				}
				else
				{
					//error: only " << is.gcount() << " could be read
				}
				is.close();
				return std::move(tmp);
			}
			return std::string();
		}


		static std::vector<char> ReadAllBytes(const std::string& path, std::ios::openmode Mode = std::ios::binary | std::ios::in)
		{
			std::fstream is(path, Mode);
			if (is.is_open())
			{
				// get length of file:
				is.seekg(0, is.end);
				size_t length = static_cast<size_t>(is.tellg());
				is.seekg(0, is.beg);

				std::vector<char> tmp(length);
				is.read(&tmp[0], length);
				if (is)
				{
					//all characters read successfully
				}
				else
				{
					//error: only " << is.gcount() << " could be read
				}
				is.close();
				return std::move(tmp);
			}
			return std::vector<char>();
		}


		static size_t GetFileSize(const std::string& path)
		{
			std::ifstream is(path, std::ifstream::binary);
			if (is) {
				// get length of file:
				is.seekg(0, is.end);
				auto length = static_cast<size_t>(is.tellg());
				is.close();
				return length;
			}
			return 0;
		}
	};
}

