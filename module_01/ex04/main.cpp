#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Err: MachiSed <fileName> \"orgin\" \"replce\"" << std::endl;
        return 1;
    }

    std::string orginFileName = argv[1];
    std::string copyFileName = argv[1];
    copyFileName += ".replace";
    
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cout << "Error: \"origin\" must not be empty." << std::endl;
        return 1;
    }
    std::ifstream ifs(orginFileName.c_str());
    if (!ifs.is_open())
    {
        std::cout << "Err: Failed to open the file" << std::endl;
        return 1;
    }

    std::ofstream ofs(copyFileName.c_str());
    if (!ofs.is_open())
    {
        std::cout << "Err: Failed to open the file" << std::endl;
        return 1;
    }

    std::string line;
    size_t pos;
    while (std::getline(ifs, line))
    {
        pos = line.find(s1);
        while (pos != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos = line.find(s1, pos + s2.length());
        }
        ofs << line + "\n";
    }
    return 0;
}
