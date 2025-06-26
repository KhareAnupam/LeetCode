class Solution {
public:
    double f(double x, int n){
        if(n==1) return x;
        if(n==2) return x*x;
        double ans=0;
        if(n%2==0){
            n/=2;
            ans+=f(x*x,n);
        }
        else{
            n--;
            ans +=  (x*f(x*x,n/2));

        }
        return ans;
    }
    double myPow(double x, int n) {
        if(n==0) return 1;
        int m=n;
        if(n==-2147483648){
            n=2147483647;
            double ans = f(x,n);
            ans*=x;
            return 1/ans;
        }
        else if(n<0) n=n*(-1);
        return (m>0)? f(x,n): 1/f(x,n);

        // for(int i=2;i<=n;i++){
        //     int c = m;
        //     if((c+=c)>n) break;
        //     sum*=sum;
        //     m+=m;
        // }
        // for()
    }
};