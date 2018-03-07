#include <stdio.h>

int tmp[500001];
long long count;

void merge(int *array, int f, int m, int l);
void merge_sort(int *array, int f, int l);

int main()
{
    int series[500001];
    int size;

    while(scanf("%u", &size)) {
        if (size == 0) {
            break;
        }

        count = 0;
        for (int i = 0; i < size; i++) {
            scanf("%d", series + i);
        }

        merge_sort(series, 0, size - 1);
        printf("%llu\n", count);
    }
    return 0;
}

void merge(int *array, int f, int m, int l)
{
    int i = f, j = m + 1;
    int k = 0;

    while (i <= m && j <= l) {
        if (array[i] < array[j]) {
            tmp[k++] = array[i++];
        }
        else {
            tmp[k++] = array[j++];
            count += (m - i + 1);
        }
    }

    while (i <= m) {
        tmp[k++] = array[i++];
    }
    while (j <= l) {
        tmp[k++] = array[j++];
    }

    for (int idx = 0; idx < k; idx++) {
        array[f + idx] = tmp[idx];
    }

}

void merge_sort(int *array, int f, int l)
{
    if (f == l) {
        return;
    }

    merge_sort(array, f, (l + f) / 2);
    merge_sort(array, (l + f) / 2 + 1, l);

    merge(array, f, (l + f) / 2, l);

}
