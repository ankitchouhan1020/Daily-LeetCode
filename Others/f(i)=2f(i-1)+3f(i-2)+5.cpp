#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Recurrence{
    public:
    // Matrix multiplication
    vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B){
        int k = A.size();
        vector<vector<ll>> C(k, vector<ll>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                for(int x=0;x<k;x++){
                    C[i][j] += A[i][x]*B[x][j];
                }
            }
        }
        return C;
    }

    //Matrix Power
    vector<vector<ll>> matPower(vector<vector<ll>> A,int n){
        if(n==0) return vector<vector<ll>>(A.size(),vector<ll>(A.size(),0));
        if(n==1) return A;
        if(n&1) return multiply(A,matPower(A,n-1));
        vector<vector<ll>> X = matPower(A,n/2);
        return multiply(X,X);
    }

    //Create transformation matrix
    //isExtra if D is available
    vector<vector<ll>> transMat(vector<ll> C,bool isExtra){
        int k = C.size();
        int size = k;
        if(isExtra) size++;
        vector<vector<ll>> T(size,vector<ll>(size,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(i<k-1){
                    if(i+1==j) T[i][j]=1;
                    else T[i][j]=0;
                }else{
                    T[i][j]=C[k-j-1];
                }
            }
        }
        if(isExtra){
            T[k][k] = 1;
            T[k-1][k] = 1;
        }
        return T;
    }

    void showMat(vector<vector<ll>>&A){
        int n = A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<A[i][j]<<" ";
            cout<<"\n";
        }
    }

    // Multiply two vecotr and get add result
    ll mulMatVec(vector<ll> a, vector<ll> b){
        ll k = a.size();
        ll res=0;
        for(int i=0;i<k;i++) res+=a[i]*b[i];
        return res;
    }
};


int main() {
    Recurrence S;
    vector<ll> Constants = {2,3};
    vector<ll> F = {1,1,5};
    vector<vector<ll>> T = S.transMat(Constants,true);
    // S.showMat(T);
    int t;
    cin>>t;
    while(t--){
        int n; //fibonacchi rank
        cin>>n;
        if(n==1){
            cout<<1<<" ";
            continue;
        }
        vector<vector<ll>> Tmat = S.matPower(T,n-1);
        // S.showMat(Tmat);
        // ll res = S.mulMatVec(Tmat[0],F);
        // cout<<res
        vector<ll> res(Tmat.size(),0);
        for(int i=0;i<Tmat.size();i++){
            for(int j=0;j<Tmat[0].size();j++){
                res[i] += Tmat[i][j]*F[j];
            }
        }
        for(ll i: res){
            cout<<i<<" ";
        }
    }
    return 0;    
}
