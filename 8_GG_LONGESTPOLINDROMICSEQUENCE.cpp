#include<iostream>

using namespace std;

int getLongestPolindromicSubSequenceLength( string );
int computePolindromeLengths( string, int, int );
int dp[3000][3000];
int main(){

  int t;
  cin >> t;

  while( t-- ) {
   string s;
   cin >> s;

   int len = getLongestPolindromicSubSequenceLength( s );
 
   cout << len << endl;
  
  }
  
  return 0;
}


int getLongestPolindromicSubSequenceLength( string s ) {

  int n = s.size();

  for( int i = 0; i < n; i++ )
   for( int j = 0; j < n; j++ ){
    dp[i][j] = 0;
        if( i == j ) dp[i][j] = 1;
    }


  int result = computePolindromeLengths( s, 0, n - 1);  
   
  return result;
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
