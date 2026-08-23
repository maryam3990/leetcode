class CustomStack 
{
    int* arr;
    int currentSize;
    int top;
    int maxSize;
public:
    CustomStack(int max) 
    {
        arr = new int[max];
        currentSize = 0;
        top = -1;
        maxSize = max;
    }
    
    void push(int x) 
    {
        if(maxSize == currentSize) return;
        arr[++top] = x;
        ++currentSize;
    }
    
    int pop() 
    {
        if(currentSize == 0) return -1;
        int ret = arr[top];
        --top;
        --currentSize;
        return ret;
    }
    
    void increment(int k, int val) 
    {
        if(currentSize == 0) return;
        for(int i = 0; i<k; i++)
        {
            arr[i] += val;
            if(i == top) return;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */