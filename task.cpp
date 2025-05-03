#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    unsigned int size = 0;
    cin >> size;
    int *arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        int num = 0;
        cin >> num;
        arr[i] = num;
    }

    bool firstNumStatus = false;
    bool flag = false;

    int idealWay = 0;
    int firstNum = 0;

    vector<int> teto;

    for (size_t i = 0; i < size; i++)
    {
        // cout << idealWay << " - " << i << endl;
        if (arr[i] < arr[i + 1] && (arr[i + 1] - arr[i] == 1) && (i+1) < size)
        {
            idealWay++;

            if (!firstNumStatus)
            {
                firstNum = arr[i];
                firstNumStatus = true;
            }

        }
        else if ((arr[i] == arr[i + 1] || arr[i] > arr[i + 1]) && flag == false && (i+1) <size)
        {
            flag = true;
            idealWay++;
        }
        else if (arr[i] > arr[i + 1] && flag == true && (arr[i] - arr[i + 1] == 1) && (i+1) <size)
        {
            idealWay++;
        }
        else if (arr[i] == firstNum)
        {
            idealWay++;
            firstNumStatus = false;
            flag = false;
            teto.push_back(idealWay);
            firstNum = 0;
            idealWay = 0;
            continue;
        }
        else
        {
            idealWay = 0;
            teto.push_back(idealWay);
            continue;
        }

    }
    auto max_it = max_element(teto.begin(), teto.end());
    
    int max_value = *max_it;
    cout << max_value;
    return 0;
}