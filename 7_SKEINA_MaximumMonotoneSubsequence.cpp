#include<iostream>
#include<vector>

using namespace std;

int computeLIS( vector< int > );

int main(){

  int t;
  cin >> t;

  while( t-- ) {
  
    int n;
    cin >> n;
    vector< int > ar( n );
    for( int i = 0; i < n; i++ )
      cin >> ar[i];
    
    int length = computeLIS( ar );
    cout << length << endl;

  }

  return 0;
}


int computeLIS( vector< int > ar ) {

  int n = ar.size();
  int dp[n];
 
  for( int i = 0; i < n; i++ )
    dp[i] = 1;
  int maxLength = -1;
  for( int i = 1; i < n; i++ ) {
   
    if( ar[i] == ar[ i -1 ])
      dp[i] = dp[i - 1] + 1;
    
    else {
    
      int j = 0, temp = 0;
      for( j = i - 1; j >= 0; j--) {
        if( ar[i] > ar[j] ){
          if( temp <= dp[j] ){
              
             temp = dp[j];
          }
        }
          
      }
     
    
      dp[i] = dp[i] + temp;   
    }
    maxLength = max( maxLength, dp[i] );
  }
  for( int i = 0; i < n; i++) {
   cout << dp[i] << " ";
  }
  return maxLength;
}
