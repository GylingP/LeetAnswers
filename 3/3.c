// typedef struct charNode{
//     char value;
//     char* next;
// }charNode,*charNodePtr;

// charNodePtr createNode(char c){
//    charNodePtr p=(charNodePtr)malloc(sizeof(charNode));
//    p->value=c;
//    p->next=NULL;
//    return p;
// }

// int findOrInsert(charNodePtr p;char c,int i){
//     int left=0;
//     int right=i-1;
//     while(left<=right){
//         mid=left+(right-left)/2;
//         if()
//     }
// }

// int getLengthOfLongestLeftString(char *s){
//     int i=1;
//     char* cursor=s+1;
//     charNodePtr c=createNode(*s);
//     while(*cursor){
//         if(findOrInsert(c,*cursor,i)){
//             return i;
//         }
//         i++;
//         cursor++;
//     }
//     return i;
// }

int getLengthOfLongestLeftString(char *s){
    int i=1;
    char * cursor=s+1;
    while(*cursor){
        for(int j=0;j<i;j++){
            if(s[j]==*cursor) return i;
        }
        i++;
        cursor++;
    }
    return i;
}

int lengthOfLongestSubstring(char* s) {
    int max=0;
    while(*s){
        int curMaxLeft;
        curMaxLeft=getLengthOfLongestLeftString(s);
        if (curMaxLeft>max) max=curMaxLeft;
        s++;
    }
    return max;
}