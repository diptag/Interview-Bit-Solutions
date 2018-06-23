/*
    Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

    Try to solve it in linear time/space.

    Example :

    Input : [1, 10, 5]
    Output : 5
    Return 0 if the array contains less than 2 elements.

    You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    You may also assume that the difference will not overflow.
*/

int Solution::maximumGap(const vector<int> &A) {
    if(A.size() < 2){
        return 0;
    }

    vector<int> forMin(A.size(), -1);
    vector<int> forMax(A.size(), -1);

    int max_dist = 0, mini = INT_MAX, maxi = INT_MIN;
    int gap = 0, bucket = 0, ind = 0;

    for(int i = 0; i < A.size(); i++){
        if(A[i] < mini){
            mini = A[i];
        }
        if(A[i] > maxi){
            maxi = A[i];
        }
    }

    gap = maxi - mini;
    gap = gap/(A.size()-1);

    if(gap == 0){
        return maxi - mini;
    }

    for(int i = 0; i < A.size(); i++){
        bucket = (int)((A[i] - mini)/gap);
        if(forMin[bucket] < 0){
            forMin[bucket] = A[i];
            forMax[bucket] = A[i];
        }
        else{
            forMin[bucket] = min(A[i], forMin[bucket]);
            forMax[bucket] = max(A[i], forMax[bucket]);
        }
    }

    int max_diff = 0;

    for(int i = 0; i < forMin.size(); i++){
        if(forMin[i] >= 0){
            max_diff = max(max_diff, forMin[i]-forMax[ind]);
            ind = i;
        }
    }

    return max_diff;
}
