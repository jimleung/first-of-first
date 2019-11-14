// Author : Jinrong Liang
// This is Michigan State Univeristy 
// CSE 232 Project 2 
// In this project  will print out the common 
//passwords most similar to the password the user provided.
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cin; using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <bits/stdc++.h>
using std::sort;

int compare_place(const string& s1, const string & s2){
// this function used to compare the characters place 
// btweeen the password and the file password matching 
// times
    int count = 0;
    const string * ps1 = nullptr; // Create a nullptr
    const string * ps2 = nullptr; // Create a nullptr
    if (static_cast<int>(s1.size()) <= static_cast<int>(s2.size())){
    // compare the size of both string and assigned each of them 
    // different pointers for loop throught successfully 
    // each word in next line
        ps1 = & s1;
        ps2 = & s2;
    }else{
        ps1 = & s2;
        ps2 = & s1;
    }
    for (int i = 0; i < static_cast<int>(ps1->size()); ++i){
    // Start loop throught each of the char in string
    // If word mathched, then count ++ 
        if((*ps1)[i]==(*ps2)[i]){
            count++;
        }
    }
    //cout << "size of unmatch: "<< static_cast<int>(ps2->size()) << endl;
    //cout << "return: "<< static_cast<int>(ps2->size()) - count << endl;
    return static_cast<int>(ps2->size()) - count;
    // return the number of not matching word
    // and put it back to common_p_fun to compare
}

vector<string> common_p_fun(const string & password, \
const vector<string>&passwords, int &out){
// Take three argument
// compare each of the no matching word
    vector<string>vr;
    int min = 100000000;
    for (const auto& mima : passwords){
    // loop throught the file password list
        int out = compare_place(password, mima);
        if(out < min){
        // find the smallest out, it meaning more match
        // if it found more similar then it will push back
        // to return string vector
            min = out;
            vr = vector<string>{mima};
        }else if(out == min){
            vr.push_back(mima);
        }
    }
    out = min;
    return vr;
}

int main(){
    //run the whole codes
    const char *filename = "common_passwords.txt";
    ifstream fin_stream(filename);
    vector<string> file_datas;
    string line;
    while(getline(fin_stream,line)){
        file_datas.push_back(line);
    }
    //make all word into vector string
    string password;
    cout << "Give me a password:" <<endl;
    cin >> password;
    cout << "You provided a password of "<< password \
    << endl << "The most similar passwords to "<< password\
    <<" are:" << endl;
    int count = 0;
    vector<string>ans = common_p_fun(password,file_datas,count);
    sort(ans.begin(),ans.end());// sort the return string 
    for (const auto & pwd: ans){
    // cout all the value
        cout<<pwd<< ", ";
    }
    cout << endl;
    cout << "All of which are " << count <<" character(s)"<< \
    " different."<<endl;
}