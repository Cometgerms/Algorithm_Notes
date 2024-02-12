/*
 * Created by Cometgerms
 * This C++ code is a demonstration of the Binary Indexed Tree algorithm.
 *
*/

#include<bits/stdc++.h>
using namespace std;
#define makeIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define EDL std::cout<<endl;
typedef long long ll;

template <class T>
class BIT{
protected:
    int size;
    vector<T> bit;
    vector<T> arr;

public:
    BIT(int size): size(size), bit(size+1), arr(size) {}
    void set_val(T i, T val){
        add(i, val-arr[i]);
    }
    void add(int index, int value){
        arr[index] += value;
        index++;
        for(;index<=size; index+=index & -index) bit[index]+=value;
    }
    T pref_sum(int index){
        index++;
        T total = 0;
        for(;index>0;index-=index & -index) total += bit[index];
        return total;
    }

};
int main() {
    makeIO;
    int n;
    int num;
    cin>>n>>num;
    BIT<ll> bit(n);
    FOR(i, 0, n){
        int t;
        cin>>t;
        bit.set_val(i, t);
    }
    FOR(i, 0, num){
        int bound_min, bound_max;
        cin >> bound_min >> bound_max;
        cout<< bit.pref_sum(bound_max - 1) - bit.pref_sum(bound_min - 2);
    }
    return 0;
}
