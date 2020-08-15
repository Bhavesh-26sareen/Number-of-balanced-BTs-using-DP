Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 10^7
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315

Solution:

#include <iostream>
#include <cmath>

using namespace std;

int helper(int h , int *ans)
{
       if(h <= 1) {
		return 1;
	}
    if(ans[h] != -1)
    {
        return ans[h] ;
    }
    
   else 
   {
	int mod = (int) (pow(10, 9)) + 7;
	int x = helper(h - 1,ans);
	int y = helper(h - 2,ans);

	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x) * y) % mod);
	int answ = (temp1 + temp2) % mod;
    ans[h]=answ ;


	//int ans = (x*x + 2*x*y) % mod;
	return ans[h] ; 
   }
}
int binaryTreesOfHeightH(int h) {
    int *ans = new int[h+1];
    for(int i = 0 ; i<= h ; i++)
    {
        ans[i] = -1;
    }

    return helper(h,ans);
}


int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
}
