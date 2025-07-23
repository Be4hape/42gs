size_t	ft_strspn(const char *s, const char *accept){
    int i = 0, j = 0;
    while(s[i]){
        j = 0;
        while(accept[j]){
            if(s[i] == s[j]){
                break;
            }j++;
        }
        i++;
    }
    return i;
    
}