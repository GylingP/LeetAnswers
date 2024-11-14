int myAtoi(char* s) {
    int sgn=1;
    long int res=0;
    while(*s==' '){
        s++;
    }
    if(*s=='-'){
        sgn=-1;
        s++;
    }else if(*s=='+'){
        s++;
    }
    long int max=pow(2,31)-(1+sgn)/2;
    while(isdigit(*s)){
        res=res*10+(*s)-'0';
        s++;
        if(res>max) return max*sgn;
    }
    return res*sgn;
}