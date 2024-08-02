#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Fungsi binary search
vector<int> binarySearch(const vector<int>& arr, int target) {
    vector<int> result;
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            // pengecekan data duplikat
            result.push_back(mid);
            
            // pengecekan data duplikat di sebelah kiri
            int i = mid - 1;
            while (i >= 0 && arr[i] == target) {
                result.push_back(i);
                i--;
            }
            
            // pengecekan data duplikat di sebelah kanan
            i = mid + 1;
            while (i < arr.size() && arr[i] == target) {
                result.push_back(i);
                i++;
            }
            
            return result;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result; // mengembalikan vector kosong jika tidak ditemukan
}

int main() {
    vector<int> arr = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    
    // pengurutan array
    sort(arr.begin(), arr.end());

    // pengujian kasus
    vector<int> testCases = {1, 50, 100};

    for (int testCase : testCases) {
        vector<int> result = binarySearch(arr, testCase);

        if (result.empty()) {
            cout << "Angka " << testCase << " tidak ada dalam array" << endl;
        } else if (result.size() == 1) {
            cout << "Angka " << testCase << " ada di indeks ke " << result[0] + 1 << endl;
        } else {
            cout << "Angka " << testCase << " ada di indeks ke ";
            for (size_t i = 0; i < result.size(); ++i) {
                cout << result[i] + 1;
                if (i < result.size() - 1) cout << " dan ";
            }
            cout << endl;
        }
    }

    return 0;
}