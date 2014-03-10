#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdexcept>

using namespace std;

void Swap(int* a, int* b)
{
    if(a == b)
        return;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int data[], int start, int end)
{
    if(data == NULL)
        throw runtime_error("Invalied Input"); 
    srand (time(NULL));
    int rand_num = rand()%(end - start) + start; // note!
    Swap(&data[rand_num], &data[end]);
    int index = start- 1;
    for(int j = start; j < end; j++)
    {
        if(data[j] < data[end])
        {
            index++;
            Swap(&data[index], &data[j]);
        }
    }
    index++;
    Swap(&data[index], &data[end]);
    return index;
}

int RandomizedSelect(int data[], int start, int end, int kth)
{
    if(start == end)
        return data[start];
    int index = Partition(data, start, end);
    int current_th = index - start + 1;
    if(current_th == kth)
        return data[index];
    else if(current_th < kth)
    {
        return RandomizedSelect(data, index+1, end, kth - current_th); //note
    }
    else
    {
        return RandomizedSelect(data, start, index-1, kth); //note
    }
}

int RandomizedSelectNonrecursively(int data[], int start, int end, int k_th)
{
    while(start < end)
    {
        int index = Partition(data, start, end);
        int current_th = index - start + 1;
        if(current_th == k_th)
            return data[index];
        else if (current_th > k_th)
            end = index -1;
        else
        {
            start = index + 1;
            k_th = k_th - current_th;
        }
    }
    //when begin==end
    return data[start];
}

void Test()
{
    int data[] = {1,3,4,8,7,6,5};
    int a = 2 / 0;
//    try
//    {
//     cout << RandomizedSelect(NULL, 0, sizeof(data)/sizeof(data[0])-1, 6) << endl;
//    }
//    catch(const runtime_error &err)
//    {
//        cout << err.what() << endl;
//    }
    cout << RandomizedSelect(data, 0, sizeof(data)/sizeof(data[0])-1, 6) << endl;
//    cout << RandomizedSelectNonrecursively(NULL, 0, sizeof(data)/sizeof(data[0])-1, 6) << endl;
}

int main()
{
    Test();
    return 0;
}
