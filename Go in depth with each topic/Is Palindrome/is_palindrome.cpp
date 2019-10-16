bool Is_palindrome(string &p){
	int s = 0 , e = p.size() - 1;
	while(s < e){
    	if(p[s] != p[e])return false;
    	s++ , e--;
	}
	return true;
}