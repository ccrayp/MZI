#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <Windows.h>
#include <cmath>

void init_map(std::unordered_map<char, int>& data);
void data_to_diagram(std::unordered_map<char, int>& diagram);
void text_to_diagram(std::string path, std::unordered_map<char, int>& data);
std::string get_text(std::string path);

void init_map(std::unordered_map<char, int>& data)
{
	for (int i = 0; i < 256; i++)
	{
		data.insert({ (char)i, 0 });
	}
}

int find_max(std::unordered_map<char, int>& data)
{
	int max = data['\0'];
	for (int i = 0; i < 256; i++)
	{
		if (data[(char)i] > max)
		{
			max = data[(char)i];
		}
	}

	return max;
}

void data_to_diagram(std::unordered_map<char, int>& data)
{
	int max = find_max(data);

	for (int i = 0; max != 0; i++)
	{
		if (i == 256)
		{
			std::cout << '|' << std::endl;
			i = 0;
			max--;
		}
		else
		{
			if (data[(char)i] > 0 && data[(char)i] == max)
			{
				std::cout << (char)164;
				data[(char)i]--;
			}
			else
				if ((char)i != '\0')
					std::cout << ' ';
		}
	}

	for (int i = 0; i < 256; i++)
	{
		if (i < 32)
			std::cout << ' ';
		else
			std::cout << (char)i;
	}
	std::cout << std::endl;
}

std::string get_text(std::string path)
{
	std::string data = "";
	std::ifstream in(path);
	if (in.is_open())
	{
		std::string temp;
		while (std::getline(in, temp))
		{
			data += temp;
		}
	}
	return data;
}

void text_to_diagram(std::string path, std::unordered_map<char, int>& data)
{
	std::string text = get_text(path);
	for (int i = 0; i < text.size(); i++)
	{
		data[text[i]]++;
	}
}

//void text()
//{
//	std::unordered_map<char, int> data;
//	init_map(data);
//
//	std::string path;
//	std::getline(std::cin, path);
//
//	system("cls");
//
//	text_to_diagram(path, data);
//	data_to_diagram(data);
//}

std::unordered_map<int, int> init_map_RGB()
{
	std::unordered_map<int, int> data;
	for (int i = 0; i < 256; i++)
	{
		data.insert({ i, 0 });
	}

	return data;
}

void ReadBMP(std::string filename, std::unordered_map<int, int>& R, std::unordered_map<int, int>& G, std::unordered_map<int, int>& B)
{
	R = init_map_RGB();
	G = init_map_RGB();
	B = init_map_RGB();

	std::ifstream in(filename, std::ios_base::binary);

	if (!in.is_open())
		throw "Argument Exception";

	unsigned char info[54]; //Массив заголовка файла bmp
	in.read((char*)info, sizeof(char) * 54); // Чтение в массив заголовка файла

	int width = *(int*)&info[18]; // Получение ширины изображения из массив
	int height = *(int*)&info[22]; // Получение высоты изображения из массив

	int row_padded = (width * 3 + 3) & (~3);
	unsigned char* data = new unsigned char[row_padded];
	char tmp;

	std::string result = "";
	for (int i = 0; i < height; i++)
	{
		in.read((char*)data, sizeof(char) * row_padded);
		for (int j = 0; j < width * 3; j += 3)
		{
			tmp = data[j];
			data[j] = data[j + 2];
			data[j + 2] = tmp;

			R[(int)data[j]]++;
			G[(int)data[j + 1]]++;
			B[(int)data[j + 2]]++;
		}
	}

	in.close();
}

int find_max(std::unordered_map<int, int> data)
{
	int max = data[0];
	for (int i = 0; i < 256; i++)
	{
		if (data[i] > max)
			max = data[i];
	}

	return max;
}

std::string output_acsii(std::unordered_map<char, int> data)
{
	std::string result = "";
	for (int i = 0; i < 256; i++)
	{
		if (i < 32)
			result += std::to_string(i) + ". = " + std::to_string(data[(char)i]) + "\r\n";
		else
			result += std::to_string(i) + ". " + (char)i + " = " + std::to_string(data[(char)i]) + "\r\n";
	}

	return result;
}

long countTotal(std::unordered_map<int, int> data)
{
	long total = 0;
	for (int i = 0; i < 256; i++)
	{
		total += data[i];
	}

	return total;
}

long countTotal(std::unordered_map<char, int> data)
{
	long total = 0;
	for (int i = 0; i < 256; i++)
	{
		total += data[(char)i];
	}

	return total;
}

float entropy(std::unordered_map<int, int> data)
{
	long total = countTotal(data);
	float result = 0.0;

	for (int i = 0; i < 256; i++)
	{
		if (data[i] != 0)
		{
			double posibility = (double)data[i] / (double)total;
			result += posibility * log2(1 / posibility);
		}
	}

	return round(result * 1000) / 1000;
}

float entropy(std::unordered_map<char, int> data)
{
	long total = countTotal(data);
	float result = 0.0;

	for (int i = 0; i < 256; i++)
	{
		if (data[(char)i] != 0)
		{
			double posibility = (double)data[(char)i] / (double)total;
			result += posibility * log2(1 / posibility);
		}
	}

	return round(result * 1000) / 1000;
}