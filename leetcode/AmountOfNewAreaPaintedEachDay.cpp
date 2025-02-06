// Question:
/*
There is a long and thin painting that can be represented by a number line.
You are given a 0-indexed 2D integer array{" "} paint of length n, where{" "} paint[i] = [starti, endi] .
This means that on the{" "} ith {" "} day you need to paint the area between{" "} starti {" "} and{" "} endi .
Painting the same area multiple times will create an uneven painting so you only want to paint each area of the painting at most once.
Return an integer array worklog of length n , where worklog[i] {" "} is the amount of new area that you painted on the{" "} ith day.
*/

// CPP 1st
class Solution
{
public:
    vector<int> amountPainted(vector<vector<int>> &paint)
    {
        set<int> unpainted;
        vector<int> ans(paint.size());
        for (int i = 0; i <= 50000; i++)
        {
            unpainted.insert(i);
        }
        for (int i = 0; i < paint.size(); i++)
        {
            int left = paint[i][0], right = paint[i][1];
            // Repeatedly delete the first element >= left until it becomes >= right
            // This clears values in [left, right) from the set
            for (auto it = unpainted.lower_bound(left); *it < right; it = unpainted.erase(it), ans[i]++)
                ;
        }
        return ans;
    }
};

// CPP 2nd
class Solution
{
public:
    vector<int> amountPainted(vector<vector<int>> &paint)
    {
        vector<int> line(50001), res(paint.size());
        for (int i = 0; i < paint.size(); ++i)
        {
            int start_i = paint[i][0], end_i = paint[i][1];
            while (start_i < end_i)
            {
                int jump = max(start_i + 1, line[start_i]);
                res[i] += line[start_i] == 0;
                line[start_i] = max(line[start_i], end_i); // compression
                start_i = jump;
            }
        }
        return res;
    }
};

// Java
class Solution
{
public
    int[] amountPainted(int[][] paint)
    {
        TreeSet<Integer> unpainted = new TreeSet<>();
        int[] ans = new int[paint.length];
        for (int i = 0; i <= 50000; i++)
        {
            unpainted.add(i);
        }
        for (int i = 0; i < paint.length; i++)
        {
            int left = paint[i][0], right = paint[i][1];
            // Repeatedly delete the first element >= left until it becomes >= right
            // This clears values in [left, right) from the TreeSet
            while (true)
            {
                int next = unpainted.ceiling(left);
                if (next >= right)
                    break;
                unpainted.remove(next);
                ans[i]++;
            }
        }
        return ans;
    }
}


//Python
from sortedcontainers import SortedList

class Solution:
    def amountPainted(self, paint: List[List[int]]) -> List[int]:
        unpainted = SortedList([i for i in range(0, 50001)])
        ans = [0 for _ in range(len(paint))]
        for i in range(len(paint)):
            left, right = paint[i]
#Repeatedly delete the first element >= left until it becomes >= right
#This clears values in[left, right) from the SortedList
            while unpainted[ind := unpainted.bisect_left(left)] < right:
                unpainted.__delitem__(ind)
                ans[i] += 1
        return ans