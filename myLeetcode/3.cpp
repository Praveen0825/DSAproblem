bool isV(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

bool doesAliceWin(string s) {
        int v=0;
        for(int i=0;i<s.length();i++){
            if(isV(s[i]))
                v++;
        }
        if(v==0)
        return false;
        else return true;

    }