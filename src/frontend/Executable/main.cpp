/*
    Cobalt - A compiler of C language
    Copyright (C) 2023  Andy Shen

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <map>
#include <string>
#include <vector>

namespace cobalt {
namespace Main {
    std::vector<std::string> Main_Words;

    enum Main_ArgumentType {
        OUTPUT,

    };
    inline int Main_ArgMap(const char* argument)
    {
        std::map<std::string, int> Main_ArgumentMap = {
            { "-o", OUTPUT }, // [input filename] ... -o [output name]
        };
        return Main_ArgumentMap[argument];
    }
    void Main_Help()
    {
    }
}

}

int main(int argc, char* argv[])
{
    if (argc <= 1) {
        cobalt::Main::Main_Help();
    }
    int pos = 1;
    while (true) {
        if (pos++ > argc) {
            break;
        }
        if (argv[pos][0] == '-') { // Options
            if (argv[pos][1] == '-') { // Specific Options
                switch (cobalt::Main::Main_ArgMap(argv[pos])) {
                case cobalt::Main::OUTPUT:
                    break;
                default:

                    break;
                }
            } else { // Non-Specific Options
            }
        } else { // Words:Filename,etc.
            cobalt::Main::Main_Words.emplace_back(argv[pos]);
        }
    }
    return 0;
}