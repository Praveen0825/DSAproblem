//Find all emps who directly or indirectly reports to a mang

/*input
A —> A
B —> A
C —> B
D —> B
E —> D
F —> E


Output:
 
A —> B, D, C, E, F
B —> D, C, E, F
C —>
D —> E, F
E —> F
F —>
*/

#include <bits/stdc++.h>
using namespace std;
 
vector<char> func1(char mang,auto &MTE, auto &res)
{
   
    if (res.find(mang) != res.end())
    {
        return res[mang];
    }
 
    vector<char> manEmp = MTE[mang];
   
    for (char rep: MTE[mang])
    {
        
        vector<char> emps = func1(rep,MTE, res);
 
       
        move(emps.begin(), emps.end(), back_inserter(manEmp));
    }
 
    res[mang] = manEmp;
    return manEmp;
}
 
void findEmp(unordered_map<char, char> &ETM)
{
   
    unordered_map<char, vector<char>> MTE;
 
    for (auto it: ETM)
    {
        char empy = it.first;
        char mang = it.second;
 
        if (empy != mang) {
            MTE[mang].push_back(empy);
        }
    }
 
    map<char, vector<char>> res;
 
    for (auto p: ETM) {
        func1(p.first, MTE, res);
    }
 
    for (auto p: res) {
         char c=p.first;
        vector<char> v=p.second;
             cout << c << " —> ";
           for (auto i: v) {
               cout << i << " ";
         }
           cout << endl;
       
    }
}
 
int main()
{
    unordered_map<char, char> ETM = {
        {'A', 'A'}, {'B', 'A'}, {'C', 'B'}, {'D', 'B'}, {'E', 'D'}, {'F', 'E'}
    };
 
    findEmp(ETM);
 
    return 0;
}