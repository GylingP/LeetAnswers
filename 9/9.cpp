bool isPalindrome(int x) {
    if (x < 0)
        return false;
    int x_ori = x;
    long int rev = 0;
    while (x) {
        rev = x % 10 + rev * 10;
        x = x / 10;
    }
    if (rev == x_ori)
        return true;
    return false;
}