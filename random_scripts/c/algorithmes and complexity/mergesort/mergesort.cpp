#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef std::vector<int> vec;

vec batman = {5,9,8,1,54,639,5452,6,12,7,5,9,5216415,54165165,51,351,654,51,651,651,651651,651, 6,10,1,3};                   // 1 5 9    3 8 10

vec merge(const vec &left, const vec &right){

    vec result;
    int i = 0, j = 0;
    int ls = left.size(), rs = right.size();

    while (i < ls && j < rs){
        if (left[i] <= right[j]){   
            result.push_back(left[i++]);                       
        } else {
            result.push_back(right[j++]);                        
        }
    }

    while (i < ls){
        result.push_back(left[i++]);
    }

    while (j < rs){
        result.push_back(right[j++]);
    }

    return result;
}

vec mergesort(vec &batman){

    int len = batman.size();          
    if (len<=1){return batman;}
    auto mid = batman.begin() + len/2;
    vec left(batman.begin(), mid);
    vec right(mid, batman.end());

    return merge(mergesort(left), mergesort(right));
}

void mergesort_inplace(vector<int> &v, int l, int r, vector<int> &temp){
    if (r - l <= 1) return;

    int m = l + (r-l)/2;
    mergesort_inplace(v, l, m, temp);
    mergesort_inplace(v, m, r, temp);

    int i = l, j = m, k = l;
    while(i < m && j < r){
        if(v[i] <= v[j]) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }
    while(i < m) temp[k++] = v[i++];
    while(j < r) temp[k++] = v[j++];

    for(int idx = l; idx < r; idx++) v[idx] = temp[idx];
}


int main(){


    vec batman2 = mergesort(batman);


    for (int &b:batman){
        cout << b << " "; 
    }
    cout << endl;

    cout << "-----batman2-----" << endl;

    for (int &b:batman2){
        cout << b << " "; 
    }
    cout << endl;

    vec robin(batman.size());

    mergesort_inplace(batman, 0, batman.size(), robin);

    cout << "-----batman-----" << endl;

    for (int &b:batman){
        cout << b << " "; 
    }
    cout << endl;


    return 0;
}