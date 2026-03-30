#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vec;

vec merge(vec left, vec right){
    vec res;

    long unsigned int i=0, j=0;

    while(i<left.size() && j<right.size()){
        if (left[i]<=right[j]){
            res.push_back(left[i++]);
        }else{
            res.push_back(right[j++]);
        }
    }
    while (j<right.size())
    {
        res.push_back(right[j++]);
    }
    while (i<left.size())
    {
        res.push_back(left[i++]);
    }
    return res;
}

vec mergesort(vec &flash){

    int x = flash.size();
    if (x<=1){
        return flash;
    }
    auto mid = flash.begin() + x/2;
    vec left(flash.begin(), mid);
    vec right(mid, flash.end());


    return merge(mergesort(left), mergesort(right));
}


void coolerMergesort(vec &flash, vec &temp, int start, int end){
    if(end - start <=1){return;}

    int middle = start + (end-start)/2;
    coolerMergesort(flash, temp, start, middle);
    coolerMergesort(flash, temp, middle, end);

    int i=start, j=middle, k=start;

    while(i<middle && j<end){
        if (flash[i]<=flash[j])
        {
            temp[k++] = flash[i++];
        }else{
            temp[k++] = flash[j++];
        }
    }

    while (i<middle)
    {
        temp[k++] = flash[i++];
    }
    while (j<end)
    {
        temp[k++] = flash[j++];
    }

    i = start;
    while (i<end)
    {
        flash[i] = temp[i];
        i++;
    }
}

int main(){

    vec flash = {5,6,9,8,7,1,5,69,8,54,25,69,8,45,2,568,89,87,45,52,869,8,457};

    vec sorted = mergesort(flash);

    cout << "sorted results" << endl;
    for( int &s:sorted){
        cout << s << "  ";
    }
    cout << endl;

    vec temp(flash.size());
    coolerMergesort(flash, temp, 0, flash.size());
    cout << "cooler sorted results" << endl;
    for( int &s:flash){
        cout << s << "  ";
    }
    cout << endl;


    return 0;
}