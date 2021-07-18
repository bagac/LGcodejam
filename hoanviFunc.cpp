#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int T, n ;
    int max_v = 1;
    int outArray[20][400] = {-1};
    std::cin >> T;
    int t_index = T;
    for(int tt = 0; tt < T; tt++){
        std::cin >> n;
        std::vector<int> h(n);
        int max_h = 0;
        for(int h_index = 0; h_index < n; h_index++){
            std::cin >> h[h_index];
            if(h[h_index] > max_h) max_h = h[h_index];
        }
        std::vector<int> v(n);
        for(int v_index = 0; v_index < n; v_index++){
            std::cin >> v[v_index];
            if(v[v_index] > max_v) max_v = v[v_index] + 1;

        }
        std::vector<int> vAh(max_v);
        std::vector<int> vIndex(max_v);      
        for(int i = 0; i < v.size(); i++){
            int value_v = int(v[i]);
            int value_h = int(h[i]);
            vIndex[i+1] = value_v;
            vAh[i+1] = value_h;
        }
        sort(v.begin(), v.end());
        do{
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
                
                if(i > 1 && vAh[i+1] == max_h ) {
                    state = 1;
                }
                if(state == 0){
                    if(vAh[i+1] < vAh[i+2]) cout_one++;
                }

                else if(state == 1 && (i < v.size() - 1)){
                    if(vAh[i+1] > vAh[i+2]) cout_one++;
                }
            }
            if((cout_Up == v.size() || cout_Dow == v.size()) && (cout_one == v.size() - 1) ){  
                for (int i = 0; i < v.size(); i++){
                    vector <int> :: iterator itr;
                    int index = 0;
                    itr = find (vIndex.begin(), vIndex.end(), v[i]);
                    if (itr != vIndex.end ()){
                        index = distance (vIndex.begin (), itr);
                    }
                    std::cout << v[i] << " - " << index << "   |   ";
                    // for(int ii = 0; ii < vIndex.size(); ii++){
                    //     if(v[i] = vIndex[ii] ) std::cout << " ** " << ii << "   **   ";
                    // }
                    
                    // std::cout << v[i] << " - " << vAh[i+1] << "   |   ";
                    // std::cout << " ** " << i+1 << "   **   ";
                    
                    
                }
            
                std::cout << " + "<< cout_Up << " - " << cout_Dow << "-  coutOne: " << cout_one << " " << std::endl;
            
            }
        } while (std::next_permutation(v.begin(), v.end()));
    }
    // for(int index = 0; index < T; index ++){
    //     for(int ii = 0; ii < max; ii++){
    //         std::cout << outArray[index][ii] << " ";
    //     }
    // std::cout << std::endl; 
    // }

            
}