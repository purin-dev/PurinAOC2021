

#include <iostream>
#include <sstream>
#include <string>
#include <AOCUtils.hpp>
using namespace std;

enum direction
{
	NODIR = 0,
	FORWARDS = 'f',
	UP = 'u',
	DOWN = 'd'
};

struct instruction
{
	direction d;
	int n;

	string to_string() const
	{
		return "inst: " + std::to_string(n) + " " + std::to_string(d);
	}
};

instruction process_data(std::string const& str)
{
	istringstream iss(str);

	string dir_str;
	direction dir = NODIR;
	int n;
	iss >> dir_str;
	iss >> n;
	dir = static_cast<direction>(static_cast<int>(dir_str[0]));

	return instruction(dir, n);
}


int main(int argc, char* argv[])
{
	std::vector<instruction> data = aoc_data::load_lines_from_file<instruction>("./data.txt", process_data);


	/* Part One */
	long long hpos = 0;
	long long depth = 0;

	for(auto const& i : data)
	{
		switch(i.d)
		{
		case NODIR: break;
		case FORWARDS: hpos += i.n; break;
		case UP: depth -= i.n; break;
		case DOWN: depth += i.n; break;
		}
	}

	cout << "depth: " << depth << "\nhorizontal position: " << hpos <<
		"\nproduct: " << depth * hpos << endl;

	/* Part Two*/

	hpos = 0;
	depth = 0;
	long long aim = 0;

	for (auto const& i : data)
	{
		switch (i.d)
		{
		case NODIR: break;
		case FORWARDS:
			hpos += i.n;
			depth += aim * i.n;
			break;
		case UP: aim -= i.n; break;
		case DOWN: aim += i.n; break;
		}
	}

	cout << "\n\n*PART TWO*\ndepth: " << depth << "\nhorizontal position: " << hpos <<
		"\nproduct: " << depth * hpos << endl;

}
