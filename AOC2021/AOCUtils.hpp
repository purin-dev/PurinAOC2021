#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>

namespace aoc_data
{
	template <typename T>
	std::vector<T> load_lines_from_file(std::string const& path, std::function<T(std::string const&)> Proc)
	{
		std::ifstream infile(path);
		std::vector<T> ret;
		while(infile)
		{
			std::string str;
			std::getline(infile, str);
			if(!str.empty()) ret.emplace_back(Proc(str));
		}
		return ret;
	}

	template <typename T>
	std::vector<T> load_lines_from_file(std::string const& path)
	{
		std::ifstream infile(path);
		std::vector<T> ret;
		while (infile)
		{
			T cur;
			infile >> cur;
			ret.emplace_back(cur);
		}
		return ret;
	}
}

