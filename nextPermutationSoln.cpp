

vector<int> Solution::nextPermutation(vector<int> &A) {
     int flag=0;
    for(int i=0;i<A.size()-1;i++){
        if(A[i]<A[i+1]){
            flag=1;
        }
    }
    if(flag==0){
      sort(A.begin(),A.end());
    }
    else{
        int ind;
       for(int i=A.size()-2;i>=0;i--){
           if(A[i]<A[i+1]){
               ind = i;
               break;
           }
       }
       for(int i=A.size()-1;i>ind;i--){
           if(A[i]>A[ind]){
               swap(A[i],A[ind]);
               break;
           }
       }
       reverse(A.begin()+ind+1,A.end());
       
        
    }
    return A;
    
}
