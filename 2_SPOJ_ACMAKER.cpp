//#include<iostream>
#include<bits/stdc++.h>
//#include<unordered_set>
using namespace std;
int pos( vector < string > , int , string , int , int , int , int );
int pos( vector < string > , int , string , int , int , int , int  );
int posHelper(vector< string > , int , string , int  );
int numberOfWays2( string, int, unordered_set<string> );
void temp(string, int);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_set<string> insignificant;
	int t;
	cin >> t;
	string inWord, input = "first" , abr;
	while( t != 0 ) {
		
		for( int i =0 ; i < t; i++ ){
			cin >> inWord;
			insignificant.insert( inWord );	
		}
		
	//	cin >> input;
	 cout << "stop words completed" << endl;	
		while( getline( cin, input) ) {
			if( input == "LAST CASE" ) break;
			if( input.size() == 0 ) continue;
//			temp( input, input.length );	
			int r = numberOfWays2( input, input.length(), insignificant );
			
		//	cin >> input;
		//	getline( cin, input );
		}
		
		cin >> t;
	}
}

void temp( string input, int len) {

	cout << "calling done" << endl;
}

vector<string> removeStopWords( string str, int strLen, unordered_set<string> stopWords, string *abr ) {

	istringstream ss( str );
	string word;
	ss >> word;
	*abr = word;
	
	vector<string> words;
	
	while( ss >> word ) {
		
	//	ss >> word;
		if( stopWords.find( word ) == stopWords.end() ) {
			words.push_back( word );
		//	cout << word << endl;
		} 
	}	
	
	//string *s = &words[0];
//	*sLen = words.size();
	
	return words;

}


int  numberOfWays2( string str, int  strLen,  unordered_set<string> stopWords ) {

	int sLen = 0;
	string abr;
	vector<string>  s = removeStopWords( str, strLen, stopWords, &abr);
	sLen = s.size();
	//cout << abr << " " << sLen << endl;

	int result = posHelper( s, sLen, abr, abr.length() ); 
	
	cout << abr << " " << result << endl;
	return 0;
}


int posHelper(vector< string > s, int sLen, string abr, int abrLen ) {
	transform( abr.begin(), abr.end(), abr.begin(), ::tolower);
	int n = pos( s, sLen, abr, abrLen, 0, 0, 0);
	return n;
}


int pos( vector < string > s, int sLen, string abr, int abrLen, int sP, int sWordN, int abrP ) {

	if( sWordN >= sLen && abrP >= abrLen ) 
		return 1;
	
	if( abrP >= abrLen ) 
		return 0;

	if( sWordN == sLen  ) return 0;
	if( sP >= s[ sWordN ].length() )
		return 0;
	int index = s[ sWordN ].find( abr[ abrP], sP );
	
	if( index == -1 ) return 0;

	int posN = 0;

	while( index != -1 ) {
	
		posN += pos( s, sLen, abr, abrLen, index + 1, sWordN, abrP + 1);
		index = s[ sWordN].find( abr[ abrP ], index + 1);		
	}

	//posN += pos( s, sLen, abr, abrLen, 0, sWordN + 1, abrP + 1);
	//posN += pos( s, sLen, abr, abrLen, 0, sWordN + 1, abrP );
	//posN += pos( s, sLen, abr, abrLen, 0, sWordN , abrP + 1);
	return posN;

}
