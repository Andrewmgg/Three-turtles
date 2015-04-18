#include <iostream>

using namespace std;

int main()
{
    long res = 0, buffer;
    for (int i = 0 ; i < 2; ++i)
    {
        cin >> buffer;
        res += buffer;
    }
    cout << res << endl;
    return 0;
}
