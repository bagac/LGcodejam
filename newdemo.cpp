#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T = 0, n = 0, k = 0, coutFi = 0;
    std::cin >> T;
    vector<int> NumFiArray(T);
    for( int t = 0; t < T; t++){
        std::cin >> n >> k;
        vector<string> nArray(n);
        vector<int> UpperCout(n);
        vector<int> coutVarArray(n);
        for(int i = 0; i < n; i++){
            std::cin >> nArray[i];
            int num = 0, coutVar = 0;
            string Var = nArray[i];
            for(int i = 0; i < Var.size(); i++){
                if(Var[i] >= 65 && Var[i] <= 90){
                    num ++;  
                }
                if(Var[i] >= 97 && Var[i] <= 122) Var[i] = Var[i] - 32;
                    coutVar += int(Var[i]);
            }
            UpperCout[i] = num;
            coutVarArray[i] = coutVar;
        }
        for(int ii = 0; ii < n-1; ii++){
            for(int iii = ii+1; iii < n; iii++){
                if(UpperCout[ii] == UpperCout[iii] && coutVarArray[ii] == coutVarArray[iii] ){
                    coutFi ++;
                }
            }
        }
        NumFiArray[t] = coutFi;
        coutFi = 0;
    }
    for(int tt = 0; tt < T; tt++) std::cout << NumFiArray[tt] << std::endl;
    return 0;
}

