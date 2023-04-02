/*
    The header of Logger Node in the Lithium Project
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
#ifndef LITHIUM_LOGGER_NODE_H
#define LITHIUM_LOGGER_NODE_H
#include <cassert>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
namespace Lithium {
namespace Logger {
    // Enumeration structs
    enum Type_Enum {
        Root,
        Children,
        Simple,
    };

    enum Level_Enum {
        RootLevel,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
    };

    class LogNode {
    protected:
        int _type {};
        int _level {};
        LogNode* _parent {};
        std::vector<LogNode*> _children;
        std::string _message;
        std::string _logger_name;

    public:
        // Constructor Functions
        LogNode() = default;
        LogNode(int level, std::string message);

        // Destructor Functions
        virtual ~LogNode()
        {
            for (auto p : _children) {
                delete p;
            }
        }

        // Operator Functions
        LogNode& operator=(const LogNode& rhs) = default;

        // Specify relation Functions
        inline void SpecifyParentNode(LogNode* parent);
        inline void AddSubNode(LogNode* children);
        inline void AddSubNodes(std::initializer_list<LogNode*> children);

        // Return information Functions
        int type() const;
        int level() const;
        std::string message() const;
        std::string logger_name() const;

        // Interface
        friend void RecursiveOperate(); // Reserve an interface
    };
} // namespace Logger
} // namespace Lithium

#endif