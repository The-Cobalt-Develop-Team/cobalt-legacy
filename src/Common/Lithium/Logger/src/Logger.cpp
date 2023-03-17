/*
    The implementation of Logger in the Lithium Project
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
#include <utility>

#include "../include/Logger.h"

using namespace Lithium::Logger;

// Constructor Functions
SimpleLog::SimpleLog(int level, std::string message)
{
    _type = Simple;
    _level = level;
    _parent = nullptr;
    _message = std::move(message);
}

LogTree::LogTree(std::string LoggerName)
{
    _type = Root;
    _level = RootLevel;
    _parent = nullptr;
    _logger_name = std::move(LoggerName);
}

BareLogger::BareLogger(std::string LoggerName)
{
    _logger_name = std::move(LoggerName);
}

// void BareLogger::debug(std::string message)
// {
//     auto* newLog = new SimpleLog(Level::DEBUG, std::move(message));
//     _container.emplace_back(newLog);
// }

// void BareLogger::info(std::string message)
// {
//     auto* newLog = new SimpleLog(Level::INFO, std::move(message));
//     _container.emplace_back(newLog);
// }

// void BareLogger::warn(std::string message)
// {
//     auto* newLog = new SimpleLog(Level::WARN, std::move(message));
//     _container.emplace_back(newLog);
// }

// void BareLogger::error(std::string message)
// {
//     auto* newLog = new SimpleLog(Level::ERROR, std::move(message));
//     _container.emplace_back(newLog);
// }

// void BareLogger::fatal(std::string message)
// {
//     auto* newLog = new SimpleLog(Level::FATAL, std::move(message));
//     _container.emplace_back(newLog);
// }

void BareLogger::addLog(const LogNode& Log)
{
    auto* log = new LogNode;
    *log = Log;
    _container.emplace_back(log);
}

Logger::Logger(std::string LoggerName)
{
    _logger_name = std::move(LoggerName);
#if DEBUG_FLAG
    std::cerr << "Construct Logger" << std::endl;
#endif
    // LogSystem::getInstance().addLogger(this);
}
