long long merge(long long *input, long long *output, int si, int ei, int mid){
    int i = si;
    int j = mid+1;
    int k = 0;
    long long count = 0;
    int temp = mid+1;
    while(i <= mid && j <= ei){
        if(input[i] > input[j]){
            count  = count + (temp-i);
            output[k] = input[j];
            k++;
            j++;
        }else{
            output[k] = input[i];
            k++;
            i++;
        }
    }
    while(i <= mid){
        output[k] = input[i];
        i++;
        k++;
    }
    while(j <= ei){
        output[k] = input[j];
        j++;
        k++;
    }
    for(int i=0;i<ei-si+1;i++){
        input[i+si] = output[i];
    }
    return count;
}

long long mergesort(long long *input, int si, int ei){
    if(si >= ei){
        return 0;
    }
    int mid = (si+ei)/2;
    long long leftI = mergesort(input, si, mid);
    long long rightI = mergesort(input, mid+1, ei);
    long long* output = new long long[ei-si+1];
    long long count = merge(input, output, si, ei, mid);
    return leftI+rightI+count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    int si = 0;
    int ei = n-1;
    return mergesort(arr, si, ei); 
}

/*
long long merge(long long *input, long long *output, int si, int ei, int mid){
    int i = si;
    int j = mid+1;
    int k = 0;
    long long count = 0;
    int temp = mid+1;
    while(i <= mid && j <= ei){
        if(input[i] > input[j]){
            count  = count + (temp-i);
            output[k] = input[j];
            k++;
            j++;
        }else{
            output[k] = input[i];
            k++;
            i++;
        }
    }
    while(i <= mid){
        output[k] = input[i];
        i++;
        k++;
    }
    while(j <= ei){
        output[k] = input[j];
        j++;
        k++;
    }
    
    for(int i=0;i<ei-si+1;i++){
        input[i+si] = output[i];
    }
    return count;
}

long long mergesort(long long *input, int si, int ei){
    if(si >= ei){
        return 0;
    }
    int mid = (si+ei)/2;
    long long leftI = mergesort(input, si, mid);
    long long rightI = mergesort(input, mid+1, ei);
    long long* output = new long long[ei-si+1];
    long long count = merge(input, output, si, ei, mid);
    return leftI + rightI + count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    int si = 0;
    int ei = n-1;
    return mergesort(arr, si, ei); 
}*/
