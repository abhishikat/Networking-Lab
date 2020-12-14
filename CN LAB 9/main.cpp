//
//  main.cpp
//  LEAKY BUCKET
//
//  Created by Abhishikat kumar Soni on 14/12/20.
//


#include<bits/stdc++.h>

using namespace std;

int bucketSize = 800;

void delay(int delay)
{
 int now=time(NULL);
 int later=now+delay;
 while(now<=later)
     now=time(NULL);
}

void bucketInput(int a,int b) {
 if(a>bucketSize) {
     cout<<"\n\t\tBucket overflow";
 }
 else {
     delay(1);
     while(a>b){
         cout<<"\n\t\t"<<b<<" bytes outputted.";
         a-=b;
         delay(1);
     }
     
  if(a>0) {
      cout<<"\n\t\tLast "<<a<<" bytes sent\t";
  }
  
  cout<<"\n\t\tBucket output successful";
 }
 
}

int main() {
     int op, packetSize;
     cout << "Bucket size is "<<bucketSize<<endl;
     cout<<"Enter output rate : "; cin>>op;
     for(int i=1;i<=5;i++){
         delay(1);
         packetSize=rand() % 1000;
         cout<<"\nPacket no "<<i<<"\tPacket size = "<<packetSize;
         bucketInput(packetSize,op);
     }
     return 0;
}
