long long e_gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    // gcd(a,b)=gcd(b,a%b)
    long long d = e_gcd(b, a % b, x1, y1);
    /*
     *    ax+by=gcd(a,b)=gcd(b,a%b)=bx1+(a- (a/b)*b)y1
     *    ax+by=ay1-b(x1-(a/b)y1)
     *    by comparing coefficient of a,b we get,
     *    x=y1
     *    y=x1+y1*(a/b);
     */
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
