# The Readme file of Cobalt's Logger

The Logger contains three main parts and some support parts. 

## Main Part of Logger

### Logger

The base class of Logger is LogNode. It contains a single log information and you can specify relations between logs. You are not supposed to use this part unless you wants to add other log type.

We define 2 types to use: LogTree and SimpleLog.

And in different part of your program, you can specify different loggers and use filters to filter it. So we also define Logger class for this use.

All logger will be put into LogSystem. The object LogSystem is a simpleton. Every logger in construction will be put into LogSystem. Filter, Layout, Appender, etc. will read LogSystem and process it. As a user, it's possible not to know this part, This Library will process it automatically.

#### LogTree

A derived class of LogNode. The most parts of it is similar to LogNode, but it only contains root node and you cannot specify its parent node.

#### SimpleLog

A derived class of LogNode. I can say: It is LogNode, except you cannot let it be root node. If you wants to add a node of LogTree or you just want a simple log for use, you can use this class.

#### Logger

A container class of LogNode. Because of polymorphism, it can also contains LogTree, SimpleLog, etc.

We provide some useful functions to use.

```cpp
Logger(std::string LoggerName); // Add a new Logger and set its name.
void debug(std::string message); // Add a debug information in logger.
void info(std::string message); // Add a info information in logger.
void warn(std::string message); // Add a warn information in logger.
void error(std::string message); // Add a error information in logger.
void fatal(std::string message); // Add a fatal information in logger.
```

### Appender

## Support Part of Logger

### Config Resolver

### Filter

### Layout