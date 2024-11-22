#include <iostream>

using namespace std;

class Solution {
  public:
  
  int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
  
    int lcm(int a, int b){
        return (a*b)/gcd(a,b);
    } 
  
    int minMod(int n, int arr[]) {
        
        bool is_not_one = true;
        for(int i=0;i<n;i++){
            if(arr[i] == 1)
               is_not_one = false;
        }
        
        if(is_not_one){
            return 1;
        }

        while(true){
            
            int result = arr[0];
             for (size_t i = 1; i < n; ++i) {
                  result = lcm(result, arr[i]); // Calculate LCM of result and the next element
               }
               return result;
        }
        
    }
};

int main()
{

}