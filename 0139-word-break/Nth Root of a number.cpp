/*
  TC => O(n* log m)
  SC => O(1)

int func(int mid , int n ,int m){
  long long int ans =1;
  for(int i=1;i<=n;i++){
    ans = ans*mid;
    if(ans>m)
      return 2;
  }
  if(ans == m)return 1;
  return 0;
}
int NthRoot(int n, int m) {
  long long int low =1;
  long long int high = m;
  while(low<=high){
    long long  mid = (low+high)/2;
    int midN = func(mid , n,m);
    if(midN == 1)
      return mid;
    else if(midN == 0)
      low = mid+1;
    else 
      high = mid-1;
  }
  return -1;

}
