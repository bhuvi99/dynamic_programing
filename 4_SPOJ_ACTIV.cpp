#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<iomanip>

using namespace std;

int getUpperBoundIndex( vector< pair< int, int> >, int);
long active( vector< pair<int, int> >, long* ); 
long activeHelper( vector< pair<int, int> >, long*, int );

bool comparator( pair< int, int> a, pair< int, int> b ) {

  return a.first < b.first;
}

int main(){
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  while( true ) {
    int n;
    cin >> n;
    if( n == -1 )
      return 0;
   
    vector< pair< int, int > > intervals(n);
    long dp[n];
    for ( int i = 0; i < n; i++ ) {
      cin >> intervals[i].first >> intervals[i].second;
      dp[i] = 0;
    }
        
    sort( intervals.begin(), intervals.end(), comparator);

    long answer =  active( intervals, dp);
   // answer = answer % 1000000000;
   // cout.fill('0');
   // cout.width(8);
    cout << answer << endl;
	
  }

  return 0;
}


long active( vector< pair< int, int > > intervals, long* dp ){

  long answer = 0;
  for( int i = 0; i < intervals.size(); i++ ) {

    answer += activeHelper( intervals, dp, i);
    answer = answer % 1000000000;
  }
  return answer;
}


long activeHelper( vector< pair< int, int> > intervals, long* dp, int i) {

  if( i >= intervals.size() )
    return 0;

  if( dp[i] != 0 )
    return dp[i];

  dp[i] = 1;

  int index = getUpperBoundIndex( intervals, intervals[i].second);

  if( index == -1 || index == i ) return dp[i];

  for( int j = index; j < intervals.size(); j++){

    if( dp[j] != 0 )
      dp[i] += dp[j];
    else
      dp[i] += activeHelper( intervals, dp, j);
  } 
  
  return dp[i];
}



int getUpperBoundIndex( vector< pair< int, int > > intervals, int value ) {

  vector< pair < int, int > > :: iterator upper;
  upper = upper_bound( intervals.begin(), intervals.end(),make_pair(value - 1, 0), comparator);

  int up = upper - intervals.begin();
  
  if( up == intervals.size() - 1){

    if( intervals[up].first < value){
     return -1;
    }
  }    
  
  return up;
}
