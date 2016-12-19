/*

约瑟夫问题.

*/

int f(n, k){
  if(n==1) return 0;
  int s=0;
  for(int i=2; i<=n; i++){
    s = (s+k)%i;
  }
  return s;
}
