
    {
        array[i] = rand() % 1000;
        printf("%d ", array[i]);
    }
    int i = 0;
    for (i = 1; i < (n / 2); i = i + 2)
    {

        int flag = array[i];
        array[i] = array[n - i - 1];
        array[n - i - 1] = flag