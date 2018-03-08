#include <stdio.h>
#include <assert.h>

struct job {
    double r;
    int order;
};

void sort(struct job *array, int size);

int main()
{
    int cases;
    int count;

    int time, fine;

    struct job job_list[1001];

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d", &count);

        for (int i = 0; i < count; i++) {
            scanf("%d %d", &time, &fine);
            job_list[i].r = fine * 1.0 / time;
            job_list[i].order = i + 1;
        }

        sort(job_list, count);

        printf("%d", job_list[0].order);
        for (int i = 1; i < count; i++) {
            printf(" %d", job_list[i].order);
        }
        printf("\n");

        if (cases > 0) {
            printf("\n");
        }
    }

    return 0;
}

void sort (struct job *array, int size)
{
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j].r < array[j + 1].r || (array[j].r == array[j + 1].r && array[j].order > array[j + 1].order)) {
                double r = array[j].r;
                int order = array[j].order;

                array[j].r = array[j + 1].r;
                array[j].order = array[j + 1].order;

                array[j + 1].r = r;
                array[j + 1].order = order;
            }
        }
    }
}
