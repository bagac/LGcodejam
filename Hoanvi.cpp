#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void findVH(vector<int>& v, vector<int>& h){
    int max = 3;
    int max_h = 30;
    int Dt = 0;
    std::vector<int> vAh(max);
    std::vector<int> vIndex(max);
    std::vector<int> out(max);
    for(int i = 0; i < v.size(); i++){
        int index_v = int(v[i]);
        int value_h = int(h[i]);
        vAh[index_v] = value_h;
        vIndex[index_v] = i+1;
    }
    sort(v.begin(), v.end());
    // sort(v.begin(), v.end());


    // vector should be sorted at the beginning.
    while (std::next_permutation(v.begin(), v.end())) {
        int cout_Up = 0, cout_Dow = 0, cout_one = 0;
        int pos = 0;
        int state = 0;   //trang thai chua len dinh
        for (int i = 0; i < v.size(); i++) {
            if(i == 0) {
                if(v[i] < v[i+1]) cout_Up++;
                else if(v[i] > v[i+1]) cout_Dow ++;
            }
            else if(i%2 == 0){
                if(v[i] < v[i-1]) cout_Up ++;
                else if(v[i] > v[i-1]) cout_Dow ++;
            }
            else{
                if(v[i] > v[i-1]) cout_Up++;
                else if(v[i] < v[i-1]) cout_Dow++;
            }
            
            if(vAh[v[i]] == max_h) {
                state = 1;
            }
            if(state == 0){
                if((vAh[v[i]] < vAh[v[i+1]]) && (state == 0)) cout_one++;
            }

            else if(state == 1 && (i < v.size() - 1)){
                if(vAh[v[i]] > vAh[v[i+1]]) cout_one++;
            }
        }
        if((cout_Up == v.size() || cout_Dow == v.size()) && (cout_one == v.size() - 1) ){
            Dt = 1;
            
            for (int i = 0; i < v.size(); i++){
                // std::cout << v[i] << " - " << vAh[v[i]] << "   |   ";
                std::cout << vIndex[v[i]] << "   |   ";
            }
            std::cout << " + "<< cout_Up << " - " << cout_Dow << "-  coutOne: " << cout_one << " " << std::endl;
        }
        
    } 
    for(int i = 0; i < v.size(); i++) std::cout << out[i] << " ";
}
int main()
{
    int T, n;
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cout << " t: " << t << " -  T: " << T << std::endl;
        std::cin >> n;
        std::vector<int> h(n);
        for(int h_index = 0; h_index < n; h_index++){
            std::cin >> h[h_index];
        }
        std::vector<int> v(n);
        for(int v_index = 0; v_index < n; v_index++){
            std::cin >> v[v_index];
        }
        findVH(v,h);
    }
    
}


