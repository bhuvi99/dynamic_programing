#include<iostream>
//#include<cmath>
using namespace std;

int computeLcs( string, string );

int main() {
  int t;
  cin >> t;
  
  while( t-- ) {
    int n, m;
    string x, y;
    cin >> n >> m;
    cin >> x;
    cin >> y;

   int lcs = computeLcs( x, y );

   cout << lcs << endl;
  }

  return 0;

}


int computeLcs( string x, string y ) {

  int n = x.length(), m = y.length() ;
  int dp[ n + 1][m + 1] = {0};
  for( int i = 0; i <=n; i++ )
    for( int j = 0; j <=m; j++)
      dp[i][j] = 0;

  for ( int i = 1; i <=n; i++ )
    for( int j = 1; j <=m; j++ ) {
     
        if( x[i - 1] == y[j - 1])
         dp[i][j] = dp[i - 1][j -1] + 1;
       else
         dp[i][j] = max( dp[i - 1][j], dp[i][ j -1] );
    }

  return dp[n][m];
}
