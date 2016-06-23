#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#define k 3
using namespace std;

struct Tuple
{
    float attr1;
    float attr2;
};

float getDistXY(Tuple t1,Tuple t2)
{
    return sqrt(pow(t1.attr1-t2.attr1,2)+pow(t1.attr2-t2.attr2,2));
}

int clusterofTuple(Tuple means[],Tuple t)
{
    float dist=getDistXY(means[0],t);
    float tmp;
    int label=0;
    for(int i=1;i<k;i++)
    {
        tmp=getDistXY(means[i],t);
        if(tmp<dist) {dist=tmp;label=i;}
        return label;
    }
}

float getVar()

