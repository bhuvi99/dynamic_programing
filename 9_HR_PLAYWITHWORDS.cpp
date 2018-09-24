#include<iostream>

using namespace std;

int computeScore( string );
int computePolindromeLengths( string, int, int );
int dp[3000][3000];
int main(){

  string s;
  cin >> s;

  int len = computeScore( s );
 
  cout << len << endl;
  
  return 0;
}


int computeScore( string s ) {

  int n = s.size();

  for( int i = 0; i < n; i++ )
   for( int j = 0; j < n; j++ ){
    dp[i][j] = 0;
        if( i == j ) dp[i][j] = 1;
    }

   
   for( int i = 0; i < n; i++ ) {
     
      if( dp[i][ n - 1] == 0 ) {
        
        dp[i][ n - 1] = computePolindromeLengths( s, i, n - 1 );
      }
  }
  
  int maximum = -1;

  for( int i = 0; i < n ; i++ ) {

   for( int j = 0; j < n ;j++ ) 
    cout << dp[i][j] << " ";
    cout << endl;
  }
  
  for( int i = 1; i < n - 1; i ++ ){
  
     int temp = dp[i][n-1] * dp[ i + 1][n-1];
     cout << temp << endl; 
     maximum = max( temp, maximum );
  }
  
   
  return maximum;
}


int computePolindromeLengths( string s, int i, int j ) {

  if( dp[i][j] != 0 )
     return dp[i][j];

  if( i > j ) return 0;
 

  if( s[i] == s[j] )
   dp[i][j] = 2 + computePolindromeLengths( s, i + 1, j - 1 );
  else {
  
   int  temp  = computePolindromeLengths( s, i + 1, j);
   int temp2 = computePolindromeLengths( s, i, j - 1 );
   dp[i][j] = max( temp, temp2 );
  }
 
  return dp[i][j];
}
