//cpp
int factorial(int num)
{
    if (num == 0 or num == 1)
        return 1;

    int ans = 1;
    for(int i=2;i<=num;i++)
    {
        ans *= i;
    }
    return ans;
}