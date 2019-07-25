#include<bits/stdc++.h>
using namespace std;

class MaxStack {
public:
    int max=INT_MIN;
    vector<int> datos;
    int tope=-1;
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        if(tope+1==datos.size()){
            datos.push_back(x);
        }
        else{
            datos[tope+1]=x;
        }
        if(max<x){
            max=x;
        }
        tope++;
    }
    
    void pop() {
        if(top()==max){
             tope--;
            max=INT_MIN;
            for(int i=tope;i>=0;i--){
                if(datos[i]>max)
                    max=datos[i];
            }
        }
        else{
            tope--;
        }
    }
    
    int top() {
        return datos[tope];
    }
    
    int getMax() {
        return max;
    }
};

int main(){
 MaxStack* obj = new MaxStack();
 obj->push(10);
 obj->push(5);
 obj->push(3);
 obj->push(4);
 obj->push(20);
 obj->pop();
 int param_3 = obj->top();
 int param_4 = obj->getMax();
 cout<<param_3<<" "<<param_4<<"\n";
 return 0;
}