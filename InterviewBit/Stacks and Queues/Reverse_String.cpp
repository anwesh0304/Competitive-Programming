string Solution::reverseString(string A) 
{
    stack<char> s ;
    for (int i = 0 ; i < A.length() ; i++)
        s.push (A[i]) ;
        
    A.clear () ;
    while (!s.empty ())
    {
        A.push_back (s.top()) ;
        s.pop () ;
    }
    
    return A ;
}