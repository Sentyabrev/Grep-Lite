#pragma once
#include <string>
#include <vector>
#include <fstream>

struct Match {
    std::string filename;
    int line_number;
    std::string line;
};

std::vector<Match> search(
    const std::string& pattern,
    const std::string& filename,
    bool ignore_case = false
);
