#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    string line;
    ifstream input ("input_day1.txt");
    //unordered_set<int> s;
    vector<int> v;

    if(input.is_open()){
        while(getline(input, line)){
            //cout << line << endl;
            v.push_back(stoi(line));
            //s.insert(stoi(line));
        }
        input.close();
    }

    /*  first part

    for(auto i : v){
        if(s.count(2020-i)) cout << 2020-i << " " << i << " iloczyn: " << i * (2020-i) << endl;
    }
    */

    sort(v.begin(), v.end());

    for(auto el : v){
        int i = 0, j = v.size()-1;

        while(i < j){
            if(v[i] + v[j] == 2020-el){
                cout << el << " " << v[i] << " " << v[j] << " iloczyn: " << el * v[i] * v[j] << endl;
                break;

            }else if(2020-el > (v[i] + v[j])) i++;
            else j--;
        }
    }

    return 0;
}
