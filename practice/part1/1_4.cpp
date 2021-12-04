#include <iostream>
#include <fstream>
#include <string>


void ReadFile(const char* file_name)
{
    std::ifstream f(file_name, std::ifstream::in);
    std::string str;
    while(std::getline(f, str))
    {
        // str.find_first_of(str2)
        // 如果str中含有str2中的任何字符，则就会查找成功，而find则不同
        std::size_t found = str.find("#include");
        if (found != std::string::npos)
        {
            std::size_t found_file_name = str.find_first_not_of("#include");
            std::string file_name = str.substr(found_file_name);
            std::size_t found_read_file_name = file_name.find_first_not_of(" ");
            if (found_read_file_name == std::string::npos)
            {
                std::cout << str << std::endl;
            }
            else
            {
                std::string read_file_name = file_name.substr(found_read_file_name);
                ReadFile(read_file_name.c_str());
                
            }
        }
        else
        {
            std::cout << str << std::endl;
        }
        str.clear();
    }
}

// ./1_4    1_4_target_file/file_name_test1
int main(int args, char** argv)
{
    if (args != 2) return 0;
    char *buffer = argv[1];

    ReadFile(buffer);
    std::cout << std::flush;

    return 0;
}