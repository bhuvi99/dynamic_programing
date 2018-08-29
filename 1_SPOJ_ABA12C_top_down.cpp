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

long appleCost[1000] ={0};

long buyAppleRecursive(int* price, int N, int  K ){
    
        if( K == 0 ) return 0;
        if( N < 0 || K < 0 ) return -1;
        
        if( appleCost[K] != 0 ){
                return appleCost[K];
            }
        long q = LONG_MAX, temp;
        bool found = false;
        for ( int i = 1; i <= K; i++ ) {
                
                if( price[i] >= 0) {
                        temp = buyAppleRecursive( price, N - 1, K - i);
                        if( temp != -1){
                             q = min( q, price[i] + temp );
                             found = true;
                          }
                       //  else q = min( q, (long)price[i] );
                    }

            }
        appleCost[K] = found ? q : -1 ;
        //cout << q << endl;
        return appleCost[K];
    }

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, N, K;
	cin >> t;

	while( t-- ) {
	

		cin.clear();

		cin >> N >> K;
		
		
	//	istringstream iss(input, istringstream::in);
	
		int prices[ K + 1];
		
		for ( int i = 1 ; i <= K; i++ ) {
			cin >> prices[i];
		}

    for ( int i = 1; i <= K; i ++) appleCost[i] = 0;
		long minCost = buyApple(prices, N, K);
		
		cout << minCost << endl;
		//cin.seekg(0,ios::end);
	std::cin.ignore(INT_MAX,'\n');
		cin.clear();
		//printf( "%ld\n", minCost );
	}	
}

