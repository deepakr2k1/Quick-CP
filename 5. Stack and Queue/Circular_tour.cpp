// Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

#include<bits/stdc++.h>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

int tour(petrolPump P[],int n) {
   deque<int> Q;
   int count=0;
   int curr=0;
   while(true) {
       Q.push_back(count);
       curr+=P[(count)%n].petrol-P[(count)%n].distance;
       while(curr<0) {
           curr-=P[(Q.front())%n].petrol-P[(Q.front())%n].distance;
           Q.pop_front();
       }
       if((int)Q.size()==n) {
           return Q.front();
       }
       if(count==2*n) return -1;
       count++;
   }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}