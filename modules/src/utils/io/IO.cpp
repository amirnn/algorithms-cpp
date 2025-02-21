// Copyright 2025 by Amir Nourinia

module;
#include <string>
#include <fstream>
module DSA:Utils.IO;

namespace utils::io {

    bool write_to_file(const std::string& file_path, const std::string& content) {
        using namespace std;
        fstream file;
        file.open(file_path.c_str(), ios::out);
        file << content;
        file.close();
        return file.good();
    }

    bool read_from_file(const std::string& file_path, std::string& content) {
        using namespace std;
        fstream file;
        file.open(file_path.c_str(), ios::in);
        if (!file.is_open()) {
            return false;
        }
        while (!file.eof()) {
            string line;
            getline(file, line);
            content += line + "\n";
        }
        file.close();
        return true;
    }
} // namespace bluecpp::io
