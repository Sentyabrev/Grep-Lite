#include "searcher.h"
#include <algorithm>
#include <iostream>

std::vector<Match> search(
    const std::string& pattern,
    const std::string& filename,
    bool ignore_case
){
    std::vector<Match> matches;

    std::ifstream file(filename);
    if (!file.is_open()){
        std::cerr << "File not found" << std::endl;
        return matches;
    }

    std::string line;
    int line_number = 1;
    Match match;
    match.filename = filename;

    while(getline(file, line)){
        const std::string* search_line = &line;
    
        if (ignore_case) {
            std::string line_lower = line;
            std::transform(line_lower.begin(), line_lower.end(), line_lower.begin(), [](unsigned char c){ return std::tolower(c); });
            search_line = &line_lower;
        }

        if (search_line->find(pattern) != std::string::npos) {
            match.line = line;
            match.line_number = line_number;
            matches.push_back(match);
        }
        line_number++;
    }

    file.close();

    return matches;
}