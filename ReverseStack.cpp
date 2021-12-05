void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    // stack<int> temp;
    // while(!input.empty()){
    //     extra.push(input.top());
    //     input.pop();
    // }
    // while(!extra.empty()){
    //     temp.push(extra.top());
    //     extra.pop();
    // }
    // while(!temp.empty()){
    //     input.push(temp.top());
    //     temp.pop();
    // }
    
    //By using stack explicitly using recursion
    if(input.empty()){
        return;
    }
    
    int temp = input.top();
    input.pop();
    reverseStack(input,extra);
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
     input.push(temp);
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
    
}
