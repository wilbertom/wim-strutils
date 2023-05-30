#include <strutils.hpp>
#include <sstream>

namespace wim::strutils {

std::string join(std::vector<std::string> v, std::string separator) {
    std::ostringstream stream;

    if (v.empty()) {
        return stream.str();
    }

    for (auto it = v.begin(); it != v.end() - 1; ++it) {
        stream << *it << separator;
    }

    stream << v.back();

    return stream.str();
}


std::vector<std::string> split(std::string s, char separator) {
    std::vector<std::string> v;

    std::string current = "";

    for (ssize_t i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == separator) {
            if (!current.empty())
            v.push_back(current);
            current = "";
        } else {
            current += c;
        }
    }

    if (!current.empty()) {
        v.push_back(current);
    }

    return v;
}

std::vector<std::string> split(std::string s) {
    return split(s, ' ');
}


std::string tail(std::string s) {
    if (s.empty()) {
        return "";
    }

    return s.substr(1, s.length());
}

}
