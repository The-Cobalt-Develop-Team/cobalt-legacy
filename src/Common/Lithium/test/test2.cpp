#include <bits/stdc++.h>

using namespace std;

class {
private:
    int a = 0;

public:
    void add()
    {
        a++;
    }
    int ret() const
    {
        return a;
    }
} SingleTon;

int main()
{
    SingleTon.add();
    cout << SingleTon.ret() << endl;
    return 0;
}