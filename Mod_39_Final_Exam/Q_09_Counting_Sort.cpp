#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];            // {1 2 5 9 2 6 5 4}
    }
    cout<<"Array before sort: ";
    printArray(arr, size);

    // Step # 1 : Finding maxium value.
    int max = INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout<<"Max: "<<max<<endl;

    // Step # 2: Initialization of [count] array
    int count[max];
    cout<<"Count array initializiation: ";
    for(int i=0; i<=max; i++){
        count[i] = 0;
    }
    printArray(count, max);

    // Step # 3: Frequency calculation. [from [arr] to [count]]
    cout<<endl<<"Frequency Calculation: ";
    for(int i=0; i<size; i++){
        // count[arr[i]]++;
        int val = arr[i];
        count[val]++;
    }
    printArray(count, max+1);

    // Step # 4: Cumulative/Prefix Sum. [from count array with max value]
    cout<<endl<<"Cumulative sum: ";
    for(int i=1; i<=max; i++){
        count[i] += count[i-1];
    }
    printArray(count, max+1);

    // Step # 5: Final array - backward traversal from base array.
    int final[size];
    int k;
    for(int i=size-1; i>=0; i--){
        count[arr[i]]--;
        k = count[arr[i]];
        final[k] = arr[i];
        cout<<"Iteration: "<<i<<endl<<"\t";
        cout<<"Index: "<<k<<" "<<"Value: "<<final[k]<<" "<<endl;
    }
    cout<<endl<<"Array after sort: ";
    printArray(final, size);
    
}


/*
    8
    3 3 1 7 7 4 4 5
    Index               0 1 2 3 4 5 6 7
    arr                 3 3 1 7 7 4 4 5
    Iteration: 7        0 0 0 0 0 5 0 0
    Iteration: 6        0 0 0 0 4 0 0 0
    Iteration: 5        0 0 0 4 0 0 0 0
    Iteration: 4        0 0 0 0 0 0 0 7
    Iteration: 3        0 0 0 0 0 0 7 0
    Iteration: 2        1 0 0 0 0 0 0 0
    Iteration: 1        0 0 3 0 0 0 0 0
    Iteration: 0        0 3 0 0 0 0 0 0


    arr[10], max=6
    index   0 1 2 3 4 5 6 7 8 9
    
    arr     5 6 5 6 2 3 2 1 4 5             Base Array
    count   0 1 2 1 1 3 2                   Frequenct Array
    count   0 1 3 4 5 8 10                  Cumulative Array
    final   1 2 2 3 4 5 5 5 6 6             Sorted Array


    int final[size];
    for(int i=size-1; i>=0; i--){
        count[arr[i]]--;                // cumulative array count
        int k = count[arr[i]];
        final[k] = arr[i]

        count[arr[i]]--     = count[arr[9]] arr[9]  --> value = 5
                            = count[5]              --> value = 8-1 = 7
                          k = 7       
                   final[7] = arr[size-1] --> 5

                      index = 0 1 2 3 4 5 6 7 8 9 
                   final[7] = 1|2|2|3|4|5|5|5|6|6




    index   0 1 2 3 4 5 6 7 8 9  
    arr     5 6 5 6 2 3 2 1 4|5|        arr[9]5 = count[5]8     count[arr[i]]--;    arr[size-1] = arr[9] --> value = 5
    count   0 1 2 1 1 3 2                   
    count   0 1 3 4 5|8|10              count[5]8-1 = 7         k = count[arr[i]];      
    final   1 2 2 3 4 5 5|5|6 6         final[7]5=arr[9]5       final[k] = arr[i]             

            5 4 1 2 3 2 6 5 6 5 
*/