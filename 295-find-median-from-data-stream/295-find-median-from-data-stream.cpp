class MedianFinder {
public:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
    double median;
    
    MedianFinder() {
        median = 0;
    }
    
    int signum(int a, int b){
        return a - b;
    }
    
    void addNum(double num) {
        int sig = signum(maxHeap.size(), minHeap.size());
        
        if(num < median){
            // push in max heap
            if(sig == 0){
                maxHeap.push(num);  
                median = maxHeap.top();
            }
            else if(sig == -1){
                maxHeap.push(num);  
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            else if(sig == 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }            
        }
        else{
            // push in min heap
            if(sig == 0){
                minHeap.push(num);    
                median = minHeap.top();
            }
            else if(sig == 1){
                minHeap.push(num);    
                median = (maxHeap.top() + minHeap.top()) / 2;                
            }
            else if(sig == -1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2;   
            }
        }
    }
    
    double findMedian() {
        return median; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */