//Bubble sort
void bubbleSort(vector<int>& a) {
    int len = a.size();
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len - i - 1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

//Selection Sort
void selectionSort(vector<int>& a) {
    int len = a.size();
    for(int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < len; j++) {
            if(a[j] < a[minIndex]) {            //找最小的放在已排好后面
                swap(a[j], a[minIndex]);
            }
        }
    }
}

//Insertion Sort
void insertionSort(vector<int>& a) {
    int len = a.size();
    for(int i = 0, j, temp; i < len - 1; i++) { //循环len-1次
        j = i;
        temp = a[i+1];
        while(j >= 0 && a[j] > temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

//Shell Sort
void shellSort(vector<int>& a) {
    int len = a.size();
    for(int gap = len / 2; gap > 0; gap /= 2) {
        for(int i = 0; i < gap; i++) {
            for(int j = i + gap, temp, preIndex; j < len; j += gap) {
                temp = a[j];
                preIndex = j - gap;
                while(preIndex >= 0 && a[preIndex] > temp) {
                    a[preIndex+gap] = a[preIndex];
                    preIndex -= gap;
                }
                a[preIndex+gap] = temp;
            }
        }
    }
}

//Quick Sort
int partition(vector<int>& a, int left, int right) {
    int pivot = a[right];
    int i = left - 1;
    fro(int j = left; j < right; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[right]);
    return i+1;
}
void quickSort(vector<int> &a, int left, int right) {
    if(left < right) {
        int mid = partition(a, left, right);
        quickSort(a, left, mid - 1);
        quickSort(a, mid + 1, right);
    }
}
void qsort(vector<int> &a) {
    quickSort(a, 0, a.size()-1);
}

//Merge Sort
void mergeSort(vector<int> &a, vector<int> &T, int left, int right) {
    if(right - left == 1) return;
    mergeSort(a, T, left, mid);
    mergeSort(a, T, mid, right);
    int mid = left + right >> 1, tmid = left + right >> 1, tleft = left, i = left;
    while(tleft < mid && tmid < right) {
        if(tmid >= right || (tleft < mid && a[tleft] < a[tmid])) {
            T[i++] = a[tleft++];
        }else {
            T[i++] = a[tmid++];
        }
    }
    for(int i = left; i < right; i++) {
        a[i] = T[i];
    }
}
void mSort(vector<int>& a) {
    int len = a.szie();
    vector<int> T(len);
    mergeSort(a, T, 0, len);
}

//Heap Sort
void adjustHeap(vector<int> &a, int i, int len) {
    int maxIndex = i;
    if(2*i+1 < len && a[maxIndex] < a[2*i+1]) {
        swap(a[maxIndex], a[2*i+1]);
    }
    if(2*i+2 < len && a[maxIndex] < a[2*i + 2]) {
        swap(a[maxIndex], a[2*i+2]);
    }
    if(maxIndex != i) {
        swap(a[maxIndex], a[i]);
        adjustHeap(a, maxIndex, len);
    }
}
void heapSort(vector<int>& a) {
    int len = a.size();
    for(int i = len/2-1; i >= 0; --i) {
        adjustHeap(a, i, len);
    }
    for(int i = len-1; i >= 0; i--) {
        swap(a[0], a[i]);
        adjustHeap(a, 0, i);
    }
}