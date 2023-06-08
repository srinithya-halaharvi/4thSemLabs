#include <iostream>
using namespace std;
class mm{
   public:
    int min;
    int max;
};

mm m1;

mm minmax(int arr[], int low, int high) {
    int mid;

    if (low == high) {
        m1.min = arr[0];
        m1.max = arr[0];
        return m1;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            m1.max = arr[low];
            m1.min = arr[high];
        } else {
            m1.max = arr[high];
            m1.min = arr[low];
        }
        return m1;
    } else {
        int mid = (low + high) / 2;
        mm p1 = minmax(arr, low, mid);
        mm p2 = minmax(arr, mid + 1, high);

        if (p1.max > p2.max)
            m1.max = p1.max;
        else
            m1.max = p2.max;

        if (p1.min < p2.min)
            m1.min = p1.min;
        else

            m1.min = p2.min;
        return m1;
    }
}
int main() {
    int n;
    cout << "Enter no of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mm m2 = minmax(arr, 0, n - 1);
    cout << "The maximum element is " << m2.max << "\n";
    cout << "The minimum element is " << m2.min << "\n";

    return 0;
}
