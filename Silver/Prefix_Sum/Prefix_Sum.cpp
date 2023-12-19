/*
 * Created by Cometgerms
 * This C++ code is a demonstration of the Prefix Sum algorithm.
 * The main function demonstrates the functionality buy input N and an array of N integers, and outputting the prefix sum of the array.
 */

#include<bits/stdc++.h>
using namespace std;
#define makeIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define EDL std::cout<<endl;
typedef long long ll;

vector<ll> prefSum(vector<ll> arr){
    vector<ll> pref(arr.size() + 1);
    partial_sum(arr.begin(), arr.end(), pref.begin() + 1);
    return pref;
}

int main(){
    makeIO;
    int N;
    cin>>N;
    vector<ll> arr(N);
    for(ll &i: arr) cin>>i;
    vector<ll> pref(N + 1);
    pref = prefSum(arr);
    for(ll i: pref) cout<<i<<" ";
    EDL;
    return 0;
}