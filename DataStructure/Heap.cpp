class heap{
public:

  heap(vector<int> nums){
    this->data = vector<int>(nums.begin(), nums.end());
    this->buildMaxHeap();
  }

  int right(int i){
    return 2*i+2;
  }
  int left(int i){
    return 2*i+1;
  }
  int parent(int i){
    return (i-1)/2;
  }


  void maxHeapify(int i, int s){
    // Assume the heap only start from 0 to s-1
    int l = left(i);
    int r = right(i);
    int maxIndex=i;
    if(l < s && data[maxIndex] < data[l]){
      maxIndex = l;
    }
    if(r < s && data[maxIndex] < data[r]){
      maxIndex = r;
    }
    if(maxIndex != i){
      swap(data[maxIndex], data[i]);
      if(maxIndex == l)
	maxHeapify(l, s);
      if(maxIndex == r)
	maxHeapify(r, s);
    }
  }

  void buildMaxHeap(){
    for(int i=(int)data.size()/2; i>-1; i--) {
      maxHeapify(i, (int)data.size());
    }
  }

  void heapSort(){
    buildMaxHeap();
    for(int i=(int)data.size()-1; i>0; i--){
      swap(data[0], data[i]);
      maxHeapify(0, i);
    }
  }

  void print(){
    for (int i=0; i<data.size(); i++){
      cout << data[i] << " ";
    }
    cout << endl;
  }

  void check(){
    for (int i=0; i<data.size()/2; i++) {
      cout << data[i] << " " << data[left(i)] << " " << data[right(i)] << endl;
    }
  }

  void increaseKey(int i, int newKey){
    data[i] = newKey;
    while(i>0){
      if(data[i] > data[parent(i)]){
	swap(data[i], data[parent(i)]);
	i = parent(i);
      }
      else{
	break;
      }
    }
  }

  void insertKey(int newKey){
    data.push_back(INT_MIN);
    increaseKey((int)data.size()-1, newKey);
  }

private:
  vector<int> data;
};
