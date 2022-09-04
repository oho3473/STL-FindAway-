#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<list>

int FindWay(int width, int vertical)
{
	std::vector<std::vector<int>> table(width + 1, std::vector<int>(vertical + 1, 0));

	table[1][1] = 1;

	for (int row = 0; row <= width; ++row)
	{
		for (int col = 0; col <= vertical; ++col)
		{
			if (row + 1 <= width)
			{
				table[row + 1][col] += table[row][col];
			}

			if (col + 1 <= vertical)
			{
				table[row][col + 1] += table[row][col];
			}
		}
	}
	
	return table[width][vertical];
}

int FindWay(int width, int vectical, std::map<std::string,int>& answer)
{
	const std::string key = std::to_string(width) + "," + std::to_string(vectical);

	if (answer.count(key) == 1)
		return answer[key];

	if (width == 0 || vectical == 0)
		return 0;

	if (width == 1 && vectical == 1)
		return 1;


	answer[key] = FindWay(width - 1, vectical,answer) + FindWay(width, vectical - 1,answer);

	return answer[key];
	
}

int main()
{
	std::map<std::string, int> Answer;
	std::cout << FindWay(2,3) << std::endl;
	std::cout << FindWay(3, 3, Answer) << std::endl;
}