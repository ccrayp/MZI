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

int find_max(std::unordered_map<uint8_t, int>& data)
{
	int max = data['\0'];
	for (int i = 0; i < 256; i++)
	{
		if (data[(uint8_t)i] > max)
		{
			max = data[(uint8_t)i];
		}
	}

	return max;
}

void binary_to_diagram(std::string path, std::unordered_map<uint8_t, int>& data, int &count) {
	std::ifstream in(path, std::ios::binary);
	if (!in.is_open()) {
		return;
	}
	for (int i = 0; i < 255; i++) {
		data.insert({ i, 0 });
	}
	uint8_t value = 0;
	while (in.read(reinterpret_cast<char*>(&value), sizeof(uint8_t))) {
		data[value]++;
		count++;
	}
	in.close();
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

long countTotal(std::unordered_map<uint8_t, int> data)
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

float entropy(std::unordered_map<uint8_t, int> data)
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