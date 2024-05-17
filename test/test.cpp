#include <iostream> 

using namespace std; 

int main()
{
    int rightArr[5] = {0, 0, 0, 0, 0};

    rightArr[3] += 1; 

    for(int i = 0; i < 5; i++)
    {
        cout << rightArr[i] << endl;
    }
}