int Solution::solve(vector<int> &A) {
   
    // maintain PREFIX_SUM pair of <odd,even> at each index
    // for removing element i, observe the pair_sum of all elements after the element[i] and pair_sum of all the elements before element[i]
    // NOTICE: after elemetns sum = pair_of_last_index_sum - pair_of_i-th_index_sum
    //NOTICE:: <odd,even> gets interchanged for after_elements_sum pair<> because odd indexs and even indexes are flipped due to element[i]'s removal
   
   
    int n = A.size();
   
    //corener case
    if(n==1){
        return 1;
    }


    vector<pair<int,int>> arr;
    // pair ==>> <odd_sum, even_sum> till the current index
    arr.push_back(make_pair(0,A[0]));
   
    int odd_sum=0,even_sum=A[0];
    for(int i=1;i<A.size();i++){
        if(i&1){
            odd_sum+=A[i];
        }
        else{
            even_sum+=A[i];
        }
        arr.push_back(make_pair(odd_sum,even_sum));
    }
    int count=0;
    pair<int,int> prev_sum,later_sum;
    pair<int,int> last_sum = arr[n-1];
   

   

   
    for(int i=0;i<A.size();i++){
       
        if(i==0){
        //when first element is removed
        pair<int,int> first_ele;
        first_ele = make_pair(last_sum.first - arr[0].first, last_sum.second-arr[0].second);
        if(first_ele.first==first_ele.second){
            count++;
        }            
        }
        else if(i==n-1){
            //when last element is removed
            if(arr[n-2].first==arr[n-2].second){
                count++;
            }
        }
        else{
           
        prev_sum = arr[i-1];
        later_sum = make_pair(last_sum.first-arr[i].first, last_sum.second-arr[i].second);
       
        pair<int,int> reversed;
        reversed = make_pair(later_sum.second,later_sum.first);
       
        int total_odd = arr[i-1].first + reversed.first;
        int total_even = arr[i-1].second + reversed.second;
       
        if(total_even==total_odd){
            count++;
        }
        }
    }
   
    return count;
}
