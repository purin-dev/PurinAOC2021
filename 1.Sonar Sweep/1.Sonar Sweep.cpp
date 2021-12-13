
#include <iostream>
#include <AOCUtils.hpp>

using namespace std;

int dataset_count_increased(vector<int> const& vals)
{
	int count_increase = 0;
	int prev = 99999; //Start at a high number, since the first value isn't considered an increase
	for (auto const& i : vals)
	{
		if (i > prev)
			count_increase++;
		prev = i;
	}
	return count_increase;
}

int main()
{
    std::vector<int> data = aoc_data::load_lines_from_file<int>("./data.txt");

	cout << "Measurement increased " << dataset_count_increased(data) << " times\n";

	std::vector<int> windows;
	auto itr = data.begin();
	while(itr < data.end() - 3)
	{
		windows.emplace_back(
			*itr + *(itr + 1) + *(itr + 2));
		++itr;
	}

	cout << "Sliding window Measurement increased " << dataset_count_increased(windows) << " times\n";


}
