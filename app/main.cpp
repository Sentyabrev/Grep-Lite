#include "searcher.h"
#include <iostream>

using namespace std;

struct Config{
    Config(int argc, char* argv[]) {
        bool pattern_set = false;
        
        for (int i = 1; i < argc; i++) {
            string arg = argv[i];
            
            if (arg == "--ignore-case" || arg == "-i") {
                this->ignore_case = true;
            }
            else if (!pattern_set) {
                this->pattern = arg;
                pattern_set = true;
            }
            else {
                this->files.push_back(arg);
            }
        }
    }

    bool ignore_case = false;
    vector<string> files;
    string pattern;
};

void print_err(const char* program_name) {
    cerr << "Using: " << program_name << " [options] <pattern> <file1> [file2] ..." << endl;
    cerr << "Options:" << endl;
    cerr << "  -i, --ignore-case" << endl;
}

void print_matches(vector<Match> matches){
    for(int i = 0; i < matches.size(); i++)
        cout << '[' << (i + 1) << ']' << ' '
             << matches[i].filename << ':' << matches[i].line_number << ':' << ' '
             << matches[i].line << endl;
}

int main(int argc, char*argv[]) {
    if (argc < 3) {
        print_err(argv[0]);
        return 1;
    }

    Config conf(argc, argv);
    vector<Match> matches;

    if (conf.pattern.empty()) {
        cerr << "Pattern not found" << endl;
        print_err(argv[0]);
        return 1;
    }

    if (conf.files.empty()) {
        cerr << "No files specified" << endl;
        print_err(argv[0]);
        return 1;
    }

    for (int i = 0; i < conf.files.size(); i++){
        matches = search(conf.pattern, conf.files[i], conf.ignore_case);
        print_matches(matches);
    }

    return 0;
}