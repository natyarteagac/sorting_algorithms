/**
 * quick_sort-function that sorts and array in ascending
 * order using the Quick sort akgorithm
 * @array:
 * @size:
 */


void quick_sort(int *array, size_t size)
{
    /*Function that takes firts and last index in the array*/
    quicksort(array, 0, size - 1, size);
}

/**
 * partition - parts the elements of the array
 * @array:
 * @low:
 * @high:
 * Return: 
*/
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high]; /*pivot*/
    int i = array[low - 1]; // Index of smaller element and indicates the right position of pivot found so far
    int temp, j=0;
    /* traverse the elements of the given array */
    for (int j = low; j <= high - 1; j++)
    {
        /* Compare each element with the pivot and
        swap them for sorting */
        if (array[j] < pivot)
        {
            i++; // increment index of smaller element
            /*swap(&arr[i], &arr[j]);*/
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }
    temp = array[j];
    array[j] = array[i];
    array[i] = temp;
    print_array(array, size);
    return (i);
}
/**
 * quicksort - sorts and array using recursion
 * @array:
 * @lower:
 * @upper:
 * @size:
 * 
*/
void quicksort(int *array, int lower, int upper, size_t size)
{
    int pi;

    if (lower > upper)
      return;
        /* pi that returnes the partitioned place 
        in the array */
    else
    {
      pi = partition(array, lower, upper, size);

        /*Recursion that sorts the elements on the
        left of the pivot*/
      quicksort(array, lower, pi - 1, size);
       /*Recursion that sorts the elements on the 
        right pivot*/
      quicksort(array, pi + 1, upper, size);
    }
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}

void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}