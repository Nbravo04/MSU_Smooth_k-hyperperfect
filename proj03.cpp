#include <iostream>
#include <cmath>
using std::cout; using std::cin; using std::endl;

//Functions

long biggest_prime (long n){
  long i;
  long largest_val;
  for (i = 2; n > 1; i += 1){
    if (n % i == 0){
      n = n / i;
      largest_val = i;
      i -= 1;
    }
  }
  return largest_val;
}

long sum_of_divisors (long n){
  long i,s;
  long sum = 0;
  s = sqrt(n);
  for (i = 1; i <= s; i++){
    if (n % i == 0){
      sum += i;
      sum += n / i;
    }
  }
  return sum;
}

long k_hyperperfect (long n, long k_max){
  long x;
  x = (1-n)/(n - sum_of_divisors(n) + 1);
  if (x > k_max)
    return 0;
  else
    return x;
}

bool b_smooth (long n, long b){
  long prime_fac = biggest_prime(n);
  if (prime_fac > b)
    return false;
  else
    return true;
}

//Main Program

int main(){
  double n, k_max, b;
  long t_1, t_2, t_3;
  bool t_4;
  cin >> n >> k_max >> b;
  
  t_1 = biggest_prime(n);
  t_2 = sum_of_divisors(n);
  t_3 = k_hyperperfect(n, k_max);
  t_4 = b_smooth(n,b);
  cout << t_1 << " " << t_2 << " " << t_3 << " " << std::boolalpha <<  t_4 << endl; 
  return 0;
}
