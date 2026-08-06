class Solution {
    int getProduct(int n, int t){
     int prod=1;
      int num=n;
      while(num!=0){
        int digit=num%10;
        prod=prod*digit;
        num=num/10;

      }
      return prod;

    }
public:
    int smallestNumber(int n, int t) {
     while(true){
        int prod=getProduct(n,t);
        if(prod%t==0){
            return n;
        }
        else{
            n++;
        }

     }
    }
};