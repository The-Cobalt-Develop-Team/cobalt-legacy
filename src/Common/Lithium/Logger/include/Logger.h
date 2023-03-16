/*
    The header of Logger in the Lithium Project
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

#ifndef LOGGER_H
#define LOGGER_H
#include "LoggerNode.h"
#include <string>
#include <utility>
namespace Lithium {
namespace Logger {
    class LogTree : LogNode {
    public:
        explicit LogTree(std::string LoggerName);
    };

    class SimpleLog : LogNode {
    public:
        SimpleLog(int level, std::string message);
    };

    // BareLogger will not be put into LogSystem automatically
    class BareLogger {
    protected:
        std::string _logger_name;
        std::vector<LogNode> _container;

    public:
        BareLogger() = default;
        explicit BareLogger(std::string LoggerName);
        inline void debug(std::string message);
        inline void info(std::string message);
        inline void warn(std::string message);
        inline void error(std::string message);
        inline void fatal(std::string message);
        inline void addLog(LogNode Log);
    };

    class Logger : BareLogger {
    private:
    public:
        Logger() = default;
        explicit Logger(std::string LoggerName);
    };

    class {
    private:
        std::vector<BareLogger*> _container;

    public:
        void addLogger(BareLogger* logger)
        {
            _container.emplace_back(logger);
        }
    } LogSystem; // It is a singleton,to process all Loggers
}
}
#endif