#include <iostream>
#include <vector>
using namespace std;
unsigned long long bit_array[33554432];
void set_bit(unsigned int val)
{
    bit_array[val / 64] |= (1ULL << (val % 64));
}
bool check_bit(unsigned int val)
{
    return bit_array[val / 64] & (1ULL << (val % 64));
}
int main()
{
    unsigned int N, S, P, Q;
    if (!(cin >> N >> S >> P >> Q)) return 0;
    unsigned int current = S % 2147483648;
    unsigned int count = 0;
    for (unsigned int i = 0; i < N; i++)
    {
        if (!check_bit(current))
        {
            set_bit(current);
            count++;
        }
        else
        {
            break;
        }
        current = (1ULL * current * P + Q) % 2147483648;
    }
    cout << count << endl;
    return 0;
}
