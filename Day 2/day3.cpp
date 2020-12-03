#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


void printv(vector<string> v){
    for(auto i : v){
        cout << i << endl;
    }
    cout << endl;
}


/* first part
int countTrees(vector<string> v){
    int n = v.size(), m = v[0].size(), j = 0, trees = 0;

    for(int i = 0; i < n; i++){
        if(v[i][j] == '#') trees++;

        j = (j + 3) % m;
    }

    return trees;
}
*/

int countTrees(vector<string> v, int right, int down){
    int n = v.size(), m = v[0].size(), j = 0, trees = 0;

    for(int i = 0; i < n; i = i + down){
        if(v[i][j] == '#') trees++;

        j = (j + right) % m;
    }

    return trees;
}

int main(){

    string line;
    ifstream input("input_day3.txt");

    vector<string> v;

    if(input.is_open()){
        while(getline(input, line)){
            //cout << line << endl;
            v.push_back(line);
        }

        printv(v);
        int t1 = countTrees(v, 1, 1);
        cout << t1 << endl;
        int t2 = countTrees(v, 3, 1);
        cout << t2 << endl;
        int t3 = countTrees(v, 5, 1);
        cout << t3 << endl;
        int t4 = countTrees(v, 7, 1);
        cout << t4 << endl;
        int t5 = countTrees(v, 1, 2);
        cout << t5 << endl;
        // result 1st part: 205
        // result 2nd part: 3952146825
        input.close();
    }

    return 0;
}
