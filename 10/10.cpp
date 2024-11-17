bool isMatch(char* s, char* p) {
    while (*p) {
        if (*(p + 1) == '*') {
            bool flag = isMatch(s, p + 2);
            if (flag)
                return true;
            while (*s && (*s == *p || *p == '.')) {
                s++;
                flag = isMatch(s, p + 2);
                if (flag)
                    return true;
            }
            return false;
        }
        if (*s == *p || (*s && *p == '.')) {
            s++;
            p++;
            continue;
        } else {
            return false;
        }
    }
    // if (*s || *p) //wrong:case 333 s="a" p="ab*"
    //     return false;
    // else
    //     return true;
    if (*s)
        return false;
    else
        return true;
}