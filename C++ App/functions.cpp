#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "functions.h"

std::vector<std::string> split(std::string inicial, char busqueda, int maxc){
    std::vector<std::string> temp;
    if(maxc==-1) maxc=inicial.size();
    if(inicial==""||maxc<2){
        temp.push_back(inicial);
        return temp;
    }
    for(int i=0; i<inicial.size()&&temp.size()<maxc-1;)
        if(inicial[i]==busqueda){
            if(i)
                temp.push_back(inicial.substr(0,i));
            inicial.erase(0, i+1);
            i=0;
        }else ++i;
    temp.push_back(inicial);
    for(int i=0; i<temp.size(); i++)
        if(temp[i]=="") temp.erase(temp.begin()+i);
    return temp;
}

bool equalIgnoreCase(std::string a, std::string b){
    if(a.size()!=b.size()) return 0;
    for(int i=0; i<a.size(); i++)
        if(toupper(a[i])!=toupper(b[i])) return false;
    return true;
}

bool isDec(std::string num){
    if(num.size()>=1)
        if(num[0]=='-') num[0]='0';
    for(int i=0; i<num.size(); i++)
        if(num[i]<'0' || num[i]>'9')
            return false;
    return true;
}

void thSleep(uint32_t ms){
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
