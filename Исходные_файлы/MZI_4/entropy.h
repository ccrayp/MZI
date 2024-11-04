#pragma once

#include <string>
#include <unordered_map>

long countTotal(std::unordered_map<uint8_t, int> data)
{
	long total = 0;
	for (int i = 0; i < 256; i++)
	{
		total += data[(char)i];
	}

	return total;
}

float u_entropy(std::unordered_map<uint8_t, int> data)
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

float entropy(std::string data) {
	std::unordered_map<uint8_t, int> map;

	for (int i = 0; i < 256; i++) {
		map.insert({ i, 0 });
	}

	for (uint8_t c : data) {
		map[c]++;
	}

	return u_entropy(map);
}