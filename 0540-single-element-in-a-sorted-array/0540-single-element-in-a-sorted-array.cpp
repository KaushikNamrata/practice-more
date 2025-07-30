class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n  = A.size();

        if(n==1) return A[0];// Agar single element diya ha to return 0
        
        int s=0,e=n-1;
        while(s<=e){
                int m= s+(e-s)/2;
                if(m==0  && A[0]!=A[1]) return A[m]; //agar first element hi single element ho
                if(m==n-1  && A[n-1]!=A[n-2]) return A[m];//last element hi single element ho


                if(A[m-1]!= A[m] && A[m] != A[m+1]) return A[m]; //agar mid hi single element ho
///       isme do case hote ha jaise mid nikala 
///       agar mid ke dono side even number ha to
///       a[mid-1]=a[mid] to left mai hoga single element warna right
                if(m%2==0){
                    if(A[m-1]==A[m]){
                        e =m-1;
                    }
                    else
                    s=m+1;

                }

                ////odd case mai a[mid-1]=a[mid]
                // isme dono side odd element honge to right mai hoga warna left

                else{
                    if(A[m-1]==A[m]){
                        s=m+1;
                    }
                    else{
                        e=m-1;
                    }

                }


        }
        return -1;
        
    }
};