#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

namespace fs = std::filesystem;

// ----------- FileSystemScanner Class -----------
class FileSystemScanner {
public:
    FileSystemScanner() {
        roots = detectRoots();
    }

    void scanAll(bool filesOnly = false, const std::string& extension = "") const {
        for (const auto& root : roots | std::views::all) {
            std::cout << "\n📂 Scanning: " << root << '\n';
            listPaths(root, filesOnly, extension);
        }
    }

    /*std::vector<fs::path> searchFile(const std::string& fileName) const {
        std::vector<fs::path> foundPaths;

        for (const auto& root : roots) {
            try {
                for (const auto& entry : fs::recursive_directory_iterator(
                         root, fs::directory_options::skip_permission_denied)) {
                    if (entry.is_regular_file() && entry.path().filename() == fileName) {
                        foundPaths.push_back(entry.path());
                    }
                }
            } catch (...) {
                // skip inaccessible directories silently
            }
        }

        return foundPaths;
    }*/
   std::vector<fs::path> searchFile(const std::string& fileName) const {
    std::vector<fs::path> foundPaths;
    std::string target = toLower(fileName);

    for (const auto& root : roots) {
        try {
            for (const auto& entry : fs::recursive_directory_iterator(
                     root, fs::directory_options::skip_permission_denied)) {
                if (entry.is_regular_file()) {
                    std::string current = toLower(entry.path().filename().string());
                    if (current.find(target) != std::string::npos) {
                        foundPaths.push_back(entry.path());
                    }
                }
            }
        } catch (...) {
            // skip inaccessible directories silently
        }
    }

    return foundPaths;
}

std::string toLower(const std::string& str) const {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}


private:
    std::vector<fs::path> roots;

    std::vector<fs::path> detectRoots() const {
#ifdef _WIN32
        DWORD drive_mask = GetLogicalDrives();
        std::vector<fs::path> drives;

        for (char letter = 'A'; letter <= 'Z'; ++letter) {
            if (drive_mask & (1 << (letter - 'A'))) {
                drives.emplace_back(std::string(1, letter) + ":\\");
            }
        }

        return drives;
#else
        return {"/"};
#endif
    }

    void listPaths(const fs::path& root_path, bool filesOnly, const std::string& extension) const {
        try {
            for (const auto& entry : fs::recursive_directory_iterator(
                     root_path, fs::directory_options::skip_permission_denied)) {

                if (filesOnly && !entry.is_regular_file()) continue;
                if (!extension.empty() && entry.path().extension() != extension) continue;

                std::cout << entry.path().string() << '\n';
            }
        } catch (const fs::filesystem_error& e) {
            std::cerr << "❌ Access error in " << root_path << ": " << e.what() << '\n';
        }
    }
};

// ----------- Terminal Interface Class -----------
class CLI {
public:
    void run() {
        FileSystemScanner scanner;

        while (true) {
            printMenu();
            int choice;
            std::cin >> choice;
            std::cin.ignore(); // flush newline

            switch (choice) {
                case 1:
                    scanner.scanAll(false);
                    break;
                case 2:
                    scanner.scanAll(true);
                    break;
                case 3: {
                    std::string ext;
                    std::cout << "Enter file extension (e.g. .txt): ";
                    std::cin >> ext;
                    scanner.scanAll(true, ext);
                    break;
                }
                case 4: {
                    std::string name;
                    std::cout << "Enter file name to search (e.g. notes.txt or just notes): ";
                    std::cin >> name;
                    auto found = scanner.searchFile(name);
                    if (found.empty()) {
                        std::cout << "No file named '" << name << "' found.\n";
                    } else {
                        std::cout << "Found:\n";
                        for (const auto& path : found) {
                            std::cout << "  " << path.string() << '\n';
                        }
                    }
                    break;
                }
                case 0:
                    std::cout << "Exiting. Goodbye!\n";
                    return;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        }
    }

private:
    void printMenu() const {
        std::cout << "\n🧭 Terminal File Explorer Options:\n"
                  << "1. List all files and folders\n"
                  << "2. List only files\n"
                  << "3. List files with specific extension\n"
                  << "4. Search for a specific file by name\n"
                  << "0. Exit\n"
                  << "Choose an option: ";
    }
};

// ----------- Entry Point -----------
int main() {
    CLI cli;
    cli.run();
    return 0;
}
