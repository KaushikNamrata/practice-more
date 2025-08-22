class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int pivot=-1,n=A.size();

        for(int i=n-2;i>=0;i--){
            if(A[i]<A[i+1]){
                pivot=i;
                break;
            }

        }
        if(pivot==-1){
            reverse(A.begin(),A.end());
            return;
        }

        //2nd step next largest element
        for(int i=n-1;i>pivot;i--){
            if(A[i]>A[pivot]){
                swap(A[i],A[pivot]);
                break;
            }
        }
        //3rd step : Reverse piv+1 se n-1;
        int i=pivot+1;
        int j=n-1;
        while(i<=j){
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
};