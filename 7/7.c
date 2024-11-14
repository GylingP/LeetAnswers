int reverse(int x) {
    char max[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
    char res[12];
    int rev = 0;
    if (x == 0)
        return 0;
    int sign = 1;
    if (x < 0) {
        max[9]++;
        sign = -1;
    }
    int i = 0;
    int flag = 1; // little,equal,large
    while (x) {
        res[i] = x % 10;
        if (flag == 1) {
            if (res[i] * sign > max[i])
                flag = 2;
            else if (res[i] * sign < max[i])
                flag = 0;
        }
        x = x / 10;
        i++;
    }
    if (i == 10 && flag == 2)
        return 0;
    int j = 0;
    for (i = i - 1; i >= 0; i--) {
        rev += res[i] * pow(10, j);
        j++;
    }
    return rev;
}