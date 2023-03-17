#include "../Logger/include/Logger.h"
#include <iostream>

using namespace std;
using namespace Lithium::Logger;

int main()
{
    BareLogger log("Main Logger");
    log.addLog(LogNode(Level::DEBUG, "Test Now"));
    // cout << LogSystem::getInstance().returnSize() << endl;
    auto container = log.returnContain();
    // for (auto iit : container) {
    //     cout << iit->message() << endl;
    // }
}