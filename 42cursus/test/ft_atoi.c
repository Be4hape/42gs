int	ft_atoi_buggy(const char *str){
    int i = 0;
    int sign = 1, value = 0;

    while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if(str[i] == '-'){
        sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        value = (value*10) + (str[i] - '0');
        i++;
    }
    return value * sign;
}