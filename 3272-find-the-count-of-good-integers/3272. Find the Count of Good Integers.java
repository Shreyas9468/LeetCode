class Solution {



  public long countGoodIntegers(int n, int k) {
    if (n == 1) {
      long res = 0;
      for (int i = 1; i <= 9; i++) {
        if (i % k == 0) {
          res++;
        }
      }
      return res;
    }
    long res = 0;
    long[][] cnk = cnk(n);
    if (n % 2 == 0) {
      Set<Long> visited = new HashSet<>();
      int h = n / 2;
      int max = 0;
      for (int i = 0; i < h; i++) {
        max = max * 10 + 9;
      }
      int min = max / 10 + 1;
      for (int i = min; i <= max; i++) {
        long pal = buildPalindrome(i, h);
        long key = key(pal);
        if (pal % k == 0 && !visited.contains(key)) {
          res += numCombos(cnk, pal);
          visited.add(key);
        }
      }
    } else {
      Set<Long> visited = new HashSet<>();
      int h = n / 2;
      int max = 0;
      for (int i = 0; i < h; i++) {
        max = max * 10 + 9;
      }
      int min = max / 10 + 1;
      for (int i = min; i <= max; i++) {
        for (int j = 0; j <= 9; j++) {
          long pal = buildPalindrome(i, h, j);
          long key = key(pal);
          if (pal % k == 0 && !visited.contains(key)) {
            res += numCombos(cnk, pal);
            visited.add(key);
          }
        }
      }
    }
    return res;
  }

  private long key(long num) {
    int[] digits = new int[10];
    while (num > 0) {
      digits[(int) (num % 10)]++;
      num /= 10;
    }
    long key = 0;
    for (int i = 0; i < 10; i++) {
      key = key * 10 + digits[i];
    }
    return key;
  }

  private long numCombos(long[][] cnk, long number) {
    int[] digits = new int[10];
    long num = number;
    int rem = 0;
    while (num > 0) {
      digits[(int) (num % 10)]++;
      rem++;
      num /= 10;
    }
    long res = 1;
    for (int i = 0; i < 10; i++) {
      if (digits[i] > 0) {
        res *= cnk[i == 0 ? rem - 1 : rem][digits[i]];
        rem -= digits[i];
      }
    }
    return res;
  }

  private long[][] cnk(long n) {
    long[][] res = new long[(int) (n + 1)][(int) (n + 1)];
    for (int i = 0; i <= n; i++) {
      res[i][0] = 1;
      res[i][i] = 1;
    }
    res[1][1] = 1;
    for (int i = 2; i <= n; i++) {
      res[i][0] = 1;
      res[i][i] = 1;
      for (int j = 1; j <= i; j++) {
        res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
      }
    }
    return res;
  }

  private long buildPalindrome(long num, long h) {
    long multi = 1;
    for (int i = 0; i < h; i++) {
      multi *= 10;
    }
    return num * multi + reverse(num);
  }

  private long buildPalindrome(long num, int h, int mid) {
    int multi = 1;
    for (int i = 0; i <= h; i++) {
      multi *= 10;
    }
    return num * multi + mid * multi / 10 + reverse(num);
  }

  private long reverse(long num) {
    long res = 0;
    while (num > 0) {
      res = res * 10 + num % 10;
      num /= 10;
    }
    return res;
  }

}