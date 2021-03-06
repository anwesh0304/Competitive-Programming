#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void editDist (string &s1, string &s2)
{
    int i, j, M = s1.length (), N = s2.length () ;
    vector<vector<int>> dp (M+1, vector<int> (N+1, 0)) ;
    
    dp[0][0] = 0 ;
    for (j = 0 ; j < N ; j++)
        dp[0][j+1] = j+1 ;
        
    for (i = 0 ; i < M ; i++)
        dp[i+1][0] = i+1 ;
        
    for (i = 0 ; i < M ; i++)
    {
        for (j = 0 ; j < N ; j++)
        {
            if (s1[i] == s2[j])
                dp[i+1][j+1] = dp[i][j] ;
            else
                dp[i+1][j+1] = min (dp[i][j], min(dp[i+1][j], dp[i][j+1])) + 1 ; 
        }
    }
    
    cout << dp[M][N] << "\n" ;
}

int main() 
{
	int noTest, M, N ;
	string s1, s2 ;
	
	cin >> noTest ;
	for (int i = 0 ; i < noTest ; i++)
	{
	    cin >> M >> N ;
	    cin >> s1 >> s2 ;
	    editDist (s1, s2) ;
	    s1.clear () ;
	    s2.clear () ;
	}
	
	return 0;
}
