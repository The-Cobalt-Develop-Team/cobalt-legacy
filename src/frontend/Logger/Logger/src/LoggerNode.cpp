/*
    The implementation of Logger Node in the Cobalt Project's Logger
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

LogNode::LogNode(int level, const char* message)
{
    _type = Simple;
    _level = level;
    _parent = nullptr;
    _message = message;
}

void LogNode::SpecifyParentNode(LogNode* parent)
{
    assert(_level != Root); // Root Node cannot be specified parent node
    _parent = parent;
    _type = Children;
}

void LogNode::AddSubNode(LogNode* children)
{
    _children.emplace_back(children);
}

void LogNode::AddSubNodes(std::initializer_list<LogNode*> children)
{
    for (auto it : children) {
        AddSubNode(it);
    }
}
