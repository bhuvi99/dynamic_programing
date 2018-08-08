#include<iostream>
#include<cmath>
#include<climits>
using namespace std;


long buyApple( int* price, int N, int K ){

	if( K == 0 ) return 0;
	
	long cost[ K + 1] ;
	cost[0] = 0;

	for ( int w = 1; w <= K; w ++ ) {
		long q = LONG_MAX;
		bool found = false;
		cost[w] = -1;
		for (int i = 1; i <= w; i++ ){
			
			if( price[i] > 0 ) {
				
				if(  w - i >= 0 && cost[ w - i ] != -1 ) {
					q = min( q, price[i] + cost[ w - i]);
					found = true;
				}	
			}
			
		}
		if( found )
			cost[w] = q;
//		if( price[w] != -1 ) 
//			cost[w] = price[w];
	}
//	for ( int i = 0; i <=K; i++) cout << cost[i] << " ";
	//cout << endl;
	return cost[K];
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, N, K;
	cin >> t;

	while( t-- ) {
	
		cin >> N >> K;
		int prices[ K + 1];
		for ( int i = 1; i <= K; i++ )
			cin >> prices[i];

		long minCost = buyApple(prices, N, K);

		cout << minCost << endl;
	}	

}
