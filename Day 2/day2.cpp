#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool check_if_valid(string line){
    int s, e;
    char letter;
    string password;

    if(line[1] == '-'){
       s = (line[0]  - '0');
       if(line[3] == ' '){
            e = (line[2] - '0');
            letter = line[4];
            password = line.substr(7, line.size());
       }else{
           e = stoi(line.substr(2,3));
           letter = line[5];
           password = line.substr(8, line.size());
       }
    }else{
        s = stoi(line.substr(0,2));
        e = stoi(line.substr(3,4));
        letter = line[6];
        password = line.substr(9, line.size());
    }

    /* first part
    int i = 0;
    for(char c : password){
        if(c == letter) i++;
    }

    return (i >= s && i <= e);
    */

    if(password[s-1] == letter && password[e-1] != letter){
            cout << line << endl;
            return true;
    }else if(password[s-1] != letter && password[e-1] == letter) return true;
    else return false;


}


int main(){

    string line;
    ifstream input("input_day2.txt");
    int counter = 0, check = 0;

    if(input.is_open()){
        while(getline(input, line)){
            //cout << line << endl;
            if(check_if_valid(line)) counter++;
            check++;
        }

        input.close();

    }
    cout << counter << " " << check << endl;

    return 0;

}
