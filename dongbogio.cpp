#include <iostream>
#include <sstream>
#include <vector>
#include <string> 
using namespace std;

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}
int ConvertH(string Hour){
    
    vector<string> v = split (Hour, ':');
    int sum = 0;
    int s = 3600;
    for (auto i : v) {
        sum += stoi(i)*s;
        s = s/60;
    }
    return sum;
}
int main(){
    int solan = 0;
    int T;
    std::cin >> T;
    int n;
    std::cin >> n ;
    vector<string> nArray(n);
    vector<int> sArray(n);
    for (int i = 0; i < n; i++){
        std::cin >> nArray[i];
        sArray[i] = ConvertH(nArray[i]);
    }
    vector<int> tArray(n);
    for (int ii = 0; ii < n; ii++){
        std::cin >> tArray[ii];
    }
    for (int ii = 0; ii < n; ii++){
    std::cout << sArray[ii] << " " << std::endl;
    }
    int H = 0;
    while(H++){
        std::cout << H << std::endl;
        vector<int> sSum(n);
        int sum2;
        for(int iii = 0; iii < n; iii++)
        {
            sSum[iii] = (tArray[iii] * H) + sArray[iii];
        }
        for(int iv = 0; iv < n; iv++)
        {
            if(sSum[iv] == sSum[iv+1]){
                sum2++;
            }
        }
        if(sum2 == (n-1)){
            solan++;
        }
        if(H > 10) break;
    }
    std::cout << solan << std::endl;

    // int H = 86400;
    // while(H--)
    // {
    //     for(int iii = 0; iii < n; iii++){
    //         if(H*tArray[iii] == H)
    //     }
    // }
    return 0;
}