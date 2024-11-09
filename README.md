# 42gs
당일에 필요한 테스트 코드
<pre>
--- TEST CODE ---
//ft_substr.c
    
    int main() {
    char *result;

    // Test case 1: 기본 테스트
    result = ft_substr("hello", 0, 2);
    printf("Test 1: %s (Expected: he)\n", result);
    free(result);

    // Test case 2: 문자열 중간에서 추출
    result = ft_substr("hello", 1, 3);
    printf("Test 2: %s (Expected: ell)\n", result);
    free(result);

    // Test case 3: len이 너무 클 때
    result = ft_substr("hello", 2, 10);
    printf("Test 3: %s (Expected: llo)\n", result);
    free(result);

    // Test case 4: start가 문자열 길이 이상일 때
    result = ft_substr("hello", 10, 5);
    printf("Test 4: %s (Expected: )\n", result);  // 빈 문자열 예상
    free(result);

    // Test case 5: len이 0일 때
    result = ft_substr("hello", 1, 0);
    printf("Test 5: %s (Expected: )\n", result);  // 빈 문자열 예상
    free(result);

    // Test case 6: 문자열 전체 추출
    result = ft_substr("hello", 0, 5);
    printf("Test 6: %s (Expected: hello)\n", result);
    free(result);

    // Test case 7: NULL 문자열 테스트
    result = ft_substr(NULL, 0, 5);
    printf("Test 7: %s (Expected: (null))\n", result ? result : "(null)");  // NULL 예상

    return 0;
}

//ft_strtrim.c
    
    int main() {
    char *result;

    // Test case 1: 양쪽에서 지정된 문자 제거
    result = ft_strtrim("xxHello Worldxx", "x");
    printf("Test 1: %s (Expected: Hello World)\n", result);
    free(result);

    // Test case 2: 중간에 있는 문자는 남김
    result = ft_strtrim(" xxhelloxx ", " x");
    printf("Test 2: %s (Expected: xhello)\n", result);
    free(result);

    // Test case 3: 여러 문자가 set에 포함된 경우
    result = ft_strtrim("!!Hello!!", "!");
    printf("Test 3: %s (Expected: Hello)\n", result);
    free(result);

    // Test case 4: s1이 빈 문자열일 때
    result = ft_strtrim("", "x");
    printf("Test 4: %s (Expected: )\n", result);  // 빈 문자열 예상
    free(result);

    // Test case 5: set이 빈 문자열일 때 (s1 반환)
    result = ft_strtrim("Hello", "");
    printf("Test 5: %s (Expected: Hello)\n", result);
    free(result);

    // Test case 6: 공백 문자를 set으로 지정
    result = ft_strtrim("   Hello World   ", " ");
    printf("Test 6: %s (Expected: Hello World)\n", result);
    free(result);

    // Test case 7: s1과 set이 둘 다 NULL인 경우
    result = ft_strtrim(NULL, NULL);
    printf("Test 7: %s (Expected: (null))\n", result ? result : "(null)");

    return 0;
}

    
<pre/>
