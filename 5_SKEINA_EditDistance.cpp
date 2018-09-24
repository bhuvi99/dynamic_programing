#include<iostream>
#include<cmath>

using namespace std;

int computeEditDistance( string, string );
int computeEditDistanceHelper( string, string, int, int, int, int  );
int minimum( int, int, int );

int dp[100][100];

int main(){

  int testCases;
  cin >> testCases;
 
  while ( testCases-- ) {
    
    string t, p;
   // getline( t,100 );
  //  cin.ignore();
   // getline(  p , 100);
    cin >> t;
    cin >> p;
 
  
    int editDistance = computeEditDistance( t, p );
   
    cout << editDistance << endl;
  }

  return 0;
}


int computeEditDistance( string t, string p ) {

  int n = t.size(), m = p.size();
  
  for ( int i = 0; i < n; i++)
    for( int j = 0; j < m; j++ )
      dp[i][j] = -1;
 

  int result = computeEditDistanceHelper( t, p, 0, 0, n, m);
 
  return result;
}


int computeEditDistanceHelper( string t, string p, int i, int j, int n, int m ) {

  if( j > i ){
    return m - n;
  }
  if( i > j ) 
    return n - m;
  if( i >= n || j >= m )
    return 0;
  
  if( dp[i][j] != -1)
    return dp[i][j];

  if( t[i] == p[j] ){
   // it's a match

   dp[i][j] = computeEditDistanceHelper( t, p, i + 1, j + 1, n, m);
  }
  else {
   int replace = 1 + computeEditDistanceHelper( t, p, i + 1, j + 1, n, m);
   int remove  = 1 + computeEditDistanceHelper( t, p, i + 1, j, n, m);
   int insert  = 1 + computeEditDistanceHelper( t, p, i, j + 1, n, m);
   dp[i][j] = minimum( replace, remove, insert );
  
  }

  return dp[i][j];
}



int minimum( int a, int b, int c ) {

 return min( a, min( b, c ) );
}
