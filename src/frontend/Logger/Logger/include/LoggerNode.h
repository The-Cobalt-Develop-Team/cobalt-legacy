/*
    The header of Logger Node in the Cobalt Project's Logger
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
#ifndef LOGGER_NODE_H
#define LOGGER_NODE_H
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

class LogNode {
private:
    int _type;
    int _level;
    LogNode* _parent;
    std::vector<LogNode*> _children;
    std::string _message;

public:
    enum Type {
        Root,
        Children,
        Simple,
    };
    enum Level {
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
    };
    LogNode(int level, const char* message);
    inline void SpecifyParentNode(LogNode* parent);
    inline void AddSubNode(LogNode* children);
    inline void AddSubNodes(std::initializer_list<LogNode*> children);
};
#endif