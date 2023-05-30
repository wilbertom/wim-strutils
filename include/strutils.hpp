#pragma once

#include <string>
#include <vector>

std::string join(std::vector<std::string> v, std::string separator);

std::vector<std::string> split(std::string s);

std::vector<std::string> split(std::string s, char separator);
