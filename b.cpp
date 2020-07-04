#include<bits/stdc++.h>
typedef long long ll;
typedef double lf;
#define ull unsigned long long

//fast i/o and external file
#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)


//definition
#define vi vector < int >
#define vll vector < ll >
#define vlld vector < lld >
#define pii pair <int, int>
#define pll pair<ll, ll>
#define vpii vector< pii >
#define vpll vector< ppl >

//iterations
#define For(i, a, b) for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a) for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n) for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar) ar.begin(), ar.end()
using namespace std;
/********************* Code starts here ************************/
int main() {
    __FastIO;
    int t;
    cin >> t;
    string str1;


    while(t--){
      cin >> str1;
      stack <int> boy;
      stack <int> girl;


      int n =  str1.size();
      Rep(i, n){
        if(str1[i] == 'x'){
          boy.push(i);
        }
        else{
          girl.push(i);
        }
      }
      int count = 0;
      while(!boy.empty() && !girl.empty()){
        if(boy.top()-girl.top() > 1){
          boy.pop();
        }
        else if(boy.top() -girl.top() < -1){
          girl.pop();
        }
        else{
          boy.pop();
          girl.pop();
          count += 1;
        }
      }
      cout << count << endl;
    }
    return 0;
}