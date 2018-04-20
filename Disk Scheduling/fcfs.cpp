#include<iostream>
#include<stdlib.h>
using namespace std;
class fcfs_disk
{
    int ref[100];
    int pos,size;
public:
    void getdata();
    void total_move();
};
void fcfs_disk::getdata()
{
    cout<<"Enter the current position of head ";
    cin>>pos;
    cout<<"Enter the size of queue : ";
    cin>>size;
    cout<<"Enter the request for tracks : ";
    for(int i=0;i<size;i++)
         cin>>ref[i];
}
void fcfs_disk::total_move()
{
    int num=pos,move=0;
    for(int i=0;i<size;i++)
    {
        move+=abs(num-ref[i]);
        num=ref[i];
    }
    cout<<"Total head movements : "<<move;
}
int main()
{
    fcfs_disk fcfs;
    fcfs.getdata();
    fcfs.total_move();
    return 0;
}