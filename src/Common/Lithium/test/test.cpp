#include "../Logger/include/Logger.h"
#include <iostream>

using namespace std;
using namespace Lithium::Logger;

int main()
{
    BareLogger log("Main Logger");
    log.addLog(LogNode(DEBUG, "Test Debug Now"));
    log.addLog(LogNode(INFO, "Test Info Now"));
    log.addLog(LogNode(WARN, "Test Warn Now"));
    log.addLog(LogNode(ERROR, "Test Error Now"));
    log.addLog(LogNode(FATAL, "Test Fatal Now"));
    // cout << LogSystem::getInstance().returnSize() << endl;
    auto container = log.returnContain();
    cout << container.size() << endl;
    for (auto iit : container) {
        cout << '[' << Builtin_Level_String[iit->level()] << ']' << ' ' << iit->message() << endl;
    }
}