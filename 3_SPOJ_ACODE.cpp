#include<iostream>

// test input 121020, expected output:2, given output :6
// test input 20020, expected :1, given : 0

using namespace std;

long decodings( string, int );
long decodingsHelper( string, int, int );

long dp[5000];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);	

  while( true ) {

   string s;
   cin >> s;  
   if ( s.size() == 1 && s[0] =='0')
    return 0;

   for ( int i = 0; i < s.size(); i++)
     dp[i] =0;  

   long result = decodings( s, s.size() );
   cout << result << endl;
	
  }

  return 0;
}

long decodings( string s, int len ) {

  long result = decodingsHelper( s, 0, len );
 // dp[ len ] = result;
  return result;
}


long decodingsHelper( string decode, int i, int len ){


  if( dp[i] != 0)
    return dp[i];

  if( i >= len )
    return 1;

  int single = decode[i] - 48;

  long sum = 0;
  if ( single != 0 ){
    sum = decodingsHelper( decode, i + 1, len );
   
    if ( i + 1 < len) {
      int doubleLength = single * 10 + decode[ i + 1] - 48;
      if( doubleLength <= 26 ){
     
        sum += decodingsHelper( decode, i + 2, len );
      }
    }
  }
  dp[i] = sum;
 return sum;
}
