class NumberContainers {
public:
    unordered_map<int, int> index_number;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> number_index;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        index_number[index] = number;
        number_index[number].push(index);
    }
    
    int find(int number) {
        if(number_index.find(number) == number_index.end()) return -1;
        auto& min_heap = number_index[number];
        while(!min_heap.empty()){
            int index = min_heap.top();
            if(index_number[index] == number) return index;
            min_heap.pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */