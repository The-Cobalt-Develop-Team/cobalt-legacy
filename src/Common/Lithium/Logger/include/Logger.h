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

#ifndef LITHIUM_LOGGER_H
#define LITHIUM_LOGGER_H
#include "LoggerNode.h"
#include <string>
#include <utility>

#define DEBUG_FLAG 1

#if DEBUG_FLAG
#include <iostream>
#endif

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
        std::vector<LogNode*> _container;

    public:
        BareLogger() = default;
        virtual ~BareLogger()
        {
            for (auto p : _container) {
                delete p;
            }
        }
        explicit BareLogger(std::string LoggerName);
        void debug(std::string message);
        void info(std::string message);
        void warn(std::string message);
        void error(std::string message);
        void fatal(std::string message);
        void addLog(const LogNode& Log);
        std::vector<LogNode*> returnContain() const
        {
            return _container;
        }
    };

    class Logger : public BareLogger {
    public:
        Logger() = default;
        explicit Logger(std::string LoggerName);
    };

    //     class LogSystem {
    //     private:
    //         static LogSystem instance;

    //     private:
    //         std::vector<BareLogger*> _container;
    //         LogSystem();
    //         ~LogSystem();

    //     public:
    //         static LogSystem& getInstance()
    //         {
    //             return instance;
    //         }

    //         void addLogger(BareLogger* logger)
    //         {
    //             _container.push_back(logger);
    //             std::cerr << _container.size() << std::endl;
    //         }
    //         std::vector<BareLogger*> returnContain()
    //         {
    //             return _container;
    //         }
    //         auto returnSize()
    //         {
    //             return _container.size();
    //         }
    //     }; // It is a singleton,to process all Loggers
    //     LogSystem LogSystem::instance;

    static const char* Builtin_Type_String[] = { "Root", "Children", "Simple" };

    static const char* Builtin_Level_String[] = { "Unknown", "DEBUG", "INFO", "WARN", "ERROR", "FATAL" };
}
}

#endif