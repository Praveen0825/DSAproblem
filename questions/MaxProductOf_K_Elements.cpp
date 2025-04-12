/*
https://leetcode.com/discuss/interview-question/6297699/GOOGLE-SDE-Phone-Screening-Round-or-1-Question

Given an array of integers, select K elements such that product is maximized. Return product.

Did a sorting based approach - but missed some cases where all the numbers were negative, followup was
No extra space after sorting
No sorting - suggested Priority queues.
*/

/*
Seems like a lot of case work, code for sorting with no extra space.

Cases to handle:
1. not enough elements => return invalid number
2. elements exactly k => just get the product
3. only positive numbers => get the last k after sorting
4. only negative numbers =>
            A. k is odd =>  get the last k after sorting
            B. k is even => get the first k after sorting
5. Mixed =>
           A. k is odd => take the last element as part of the result and pop it out.
           k is even now.
           Have two pointers at the end and start.
           Take the product of first two from start.
           Take the product of last two from end.
           Whichever one is greater, take that and move the pointer by two positions.
*/

// assuming everthing is a 32 bit integer
// the result will fit inside a 32-bit integer

array<int, 3> getProduct(const vector<int> &nums)
{
    int product = 1, pos = 0, neg = 0;
    for (const int &num : nums)
    {
        product *= num;
        if (num < 0)
            neg++;
        else
            pos++;
    }
    return {product, pos, neg};
}

int getProductFromPositive(const vector<int> &nums, int k)
{
    int product = 1;
    for (int end = nums.size() - 1; k; end--, k--)
        product *= nums[end];
    return product;
}

int getProductFromNegative(const vector<int> &nums, int k)
{
    if (k % 2)
        return getProductFromPositive(nums, k);
    int product = 1;
    for (int start = 0; k; k--, start++)
        product *= nums[start];
    return product;
}

int getProductFromMix(vector<int> &nums, int k)
{
    int product = 1;

    if (k % 2)
    {
        product = nums.back();
        nums.pop_back();
        k--;
    }

    for (int start = 0, end = nums.size() - 1; k; k -= 2)
    {
        int left = nums[start] * nums[start + 1];
        int right = nums[end] * nums[end - 1];

        if (left < right)
        {
            product *= right;
            end -= 2;
        }
        else
        {
            product *= left;
            start += 2;
        }
    }

    return product;
}

int maxProduct(vector<int> &nums, int &k)
{
    if (nums.size() < k)
        return INT_MIN; // can't select k elements

    auto [product, pos, neg] = getProduct(nums);
    if (nums.size() == k)
        return product;

    sort(nums.begin(), nums.end());

    if (pos == nums.size())
        return getProductFromPositive(nums, k);
    if (neg == nums.size())
        return getProductFromNegative(nums, k);

    return getProductFromMix(nums, k);
}

int main()
{
    // TC 1
    // vector<int> nums = {1, 2, 3, 4, 5};
    // int k = 1;

    // TC 2
    // vector<int> nums = {-1, -2, -3, -4, -5};
    // int k = 5;

    // TC 3
    // vector<int> nums = {-6,-4,-3,-2,0,2,3,4,6};
    // int k = 4;

    // TC 4
    vector<int> nums = {-10, -10, -5, -2};
    int k = 3;

    cout << maxProduct(nums, k) << endl;
}