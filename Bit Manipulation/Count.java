class count
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int c = 0;

        for (int p = 1; p <= n; p *= 2)
        {
            c += (((n + 1) / p) / 2) * p;

            if (((n + 1) / p) % 2)
            {
                c += (n + 1) % p;
            }
        }
        return c;
    }
};