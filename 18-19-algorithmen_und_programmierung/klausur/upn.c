//solution for UPN-Task from exam summer 2018
//softbobo 190131

/* task 1a) algorithm in pseudocode:
REQUIRE: args
ENSURE: sum

start_nums <- args/2-1
start_ops <- args
*/

/* task 1b) Big-Oh notation (time complexity):

*/

/* task 1c) C-implementation w/o <string.h> */

long berechneUPN(int upn[]) {
    long len = arr_len(upn); 
    int* stack = (int*)malloc(len * sizeof(int));
    long ind = 0;
    long sum = 0;
    for(long i = 0; upn[i] != 3; i++) {
        if(upn[i] >= 0) {
            stack[ind] = upn[i];
            ind += 1;
        }
        else if(upn[i] == -1 && ind > 1) {              
            sum += (stack[ind-1] + stack[ind-2]);
            ind -= 2;
        }
        else if(upn[i] == -1 && ind == 1) {               
            sum += stack[ind];
            ind -= 1;
        }
        else if(upn[i] == -2 && ind > 1) {
            sum += (stack[ind] * stack[ind-1]);
            ind -= 2;
        }
        else if(upn[i] == -2 && ind == 1) {
            sum *= stack[ind];
            ind -= 1;
        }
    }


}

long arr_len(int arr[]) {
    long len = 0;
    for(long i = 0; arr[i] != -3; i++)
        len++;
    return len;
}
