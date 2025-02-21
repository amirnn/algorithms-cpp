// Copyright 2025 by Amir Nourinia

module;
#include <string>
export module DSA:Utils.IO;

export namespace utils::io {
    bool write_to_file(std::string const& file_path, std::string const& content);
    bool read_from_file(std::string const& file_path, std::string& content);
}
