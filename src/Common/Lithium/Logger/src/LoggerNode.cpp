/*
    The implementation of Logger Node in the Lithium Project
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

#include "../include/LoggerNode.h"

using namespace Lithium::Logger;

// Constructor Functions
LogNode::LogNode(int level, std::string message)
{
    _type = Simple;
    _level = level;
    _parent = nullptr;
    _message = std::move(message);
}

// Specify relation Functions
void LogNode::SpecifyParentNode(LogNode* parent)
{
    assert(_level != Root); // Root Node cannot be specified parent node
    _type = Children;
    _parent = parent;
    _logger_name = parent->_logger_name;
}

void LogNode::AddSubNode(LogNode* children)
{
    _children.emplace_back(children);
    children->_logger_name = this->_logger_name;
}

void LogNode::AddSubNodes(std::initializer_list<LogNode*> children)
{
    for (auto it : children) {
        AddSubNode(it);
    }
}

// Return information Functions
int LogNode::type() const
{
    return _type;
}
int LogNode::level() const
{
    return _level;
}
std::string LogNode::message() const
{
    return _message;
}
std::string LogNode::logger_name() const
{
    return _logger_name;
}