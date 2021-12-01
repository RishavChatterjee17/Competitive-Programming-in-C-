bool isPrime(int n)
    {
        if (n <= 1)  return false;
        if (n <= 3)  return true;

        if (n%2 == 0 || n%3 == 0) return false;

        for (int i=5; i*i<=n; i=i+6)
            if (n%i == 0 || n%(i+2) == 0)
               return false;

        return true;
    }

    int nextPrime(int N)
    {
        if (N <= 1)
            return 2;

        int prime = N;
        bool found = false;

        while (!found) 
        {
            prime++;

            if (isPrime(prime))
                found = true;
        }

        return prime;
    }
    
    int prevPrime(int n) 
    {
       for (int i = n - 1; i > 1; i--) 
       {
          if (isPrime(i)) {
             return i;
          }
       }
       return -1;
    }