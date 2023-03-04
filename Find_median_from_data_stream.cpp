/*
    If we split the incoming elements into two parts , we want the maximum of the left part and minimum of
    the right part. So we store the entire left part in the max heap and the entire right part in the min 
    heap.
    A min-heap that contains the larger half of the elements, with the minimum element at the root
    A max-heap that contains the smaller half of the elements, with the maximum element at the root
    Now, we can add the incoming integer to the relevant half by comparing it with the root of the
    min-heap. Next, if after insertion, the size of one heap differs from that of the other heap by more
    than 1, we can rebalance the heaps, thus maintaining a size difference of at most 1:

    if size(minHeap) > size(maxHeap) + 1:
        remove root element of minHeap, insert into maxHeap
    if size(maxHeap) > size(minHeap) + 1:
        remove root element of maxHeap, insert into minHeap

    With this approach, we can compute the median as the average of the root elements of both the heaps, if
    the size of the two heaps is equal. Otherwise, the root element of the heap with more elements is the
    median.
*/

class MedianFinder 
{
    priority_queue<int> pq_max;
    priority_queue<int,vector<int>,greater<int>> pq_min;
public:
    MedianFinder() 
    {
    }
    
    void addNum(int num) 
    {
        // left sorted part will be stored in max heap and right sorted will be stored in min heap
        if((!pq_max.empty() and num<pq_max.top()) or pq_max.empty())
        {
            // insert into max heap
            pq_max.push(num);
        }
        else
        {
            // insert into min heap
            pq_min.push(num);
        }
        // check if the sizes are crossing
        if(pq_min.size() > pq_max.size() + 1)
        {
            // insert the top element of min hap into max heap
            int top = pq_min.top();
            pq_min.pop();
            pq_max.push(top);
        }
        if(pq_max.size() > pq_min.size() + 1)
        {
            // insert the top element of min hap into max heap
            int top = pq_max.top();
            pq_max.pop();
            pq_min.push(top);
        }
    }
    
    double findMedian() 
    {
        /*
        With this approach, we can compute the median as the average of the root elements of both the heaps
        if the size of the two heaps is equal. Otherwise, the root element of the heap with more elements
        is the median.
        */
        if(pq_min.size() == pq_max.size())
        return (pq_min.top() + pq_max.top())/2.0;
        else
        {
            if(pq_min.size()>pq_max.size())
            return pq_min.top();
            else
            return pq_max.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
