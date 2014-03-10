#include<iostream>

using namespace std;

int GetFirstK(int* data, int start, int end, int k)
{
    if(start > end)
        return -1;
    int middle_index = (end+start)/2;
    if(data[middle_index] == k)
    {
        if((middle_index > 0 && data[middle_index-1] != k) || middle_index == 0)
            return middle_index;
        else 
            end = middle_index - 1;
    }
    else if(data[middle_index] > k)
        end = middle_index - 1;
    else
        start = middle_index + 1;

    return GetFirstK(data, start, end, k);
}

int GetLastK(int* data, int length, int start, int end, int k)
{
    if(start > end)
        return -1;
    int middle_index = (end + start)/2;
    if(data[middle_index] == k)
    {
        if((middle_index < length -1 && data[middle_index+1] != k) || middle_index == length -1)
            return middle_index;
        else 
            start = middle_index + 1;
    }
    else if(data[middle_index] > k)
        end = middle_index - 1;
    else
        start = middle_index + 1;
    
    return GetLastK(data, length, start, end, k);
}

int GetNumberOfK(int* data, int length, int k)
{
    if(data == NULL || length <= 0)
        return 0;
    int first = GetFirstK(data, 0, length - 1, k);
    int last = GetLastK(data, length, 0, length - 1, k);
    if(first >= 0 && last >= 0)
        return last - first + 1;
    else
        return 0;
}

void Test()
{
    int data[] = {2,2,2,3,4,5};
    int length = sizeof(data)/sizeof(data[0]); 
//    cout << GetFirstK(data, 0, sizeof(data)/sizeof(data[0])-1, 7) << endl;
//    cout << GetLastK(data, length, 0, length-1, 5) << endl;
    cout << GetNumberOfK(data, length, 5) << endl;
}

int main()
{
    Test();
    return 0;
}
