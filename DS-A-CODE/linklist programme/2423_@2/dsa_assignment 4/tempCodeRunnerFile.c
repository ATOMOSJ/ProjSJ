  clock_t beign = clock();
    mergeSort(ar,0,n-1);
    printf("after merge sorting\n");
    display(ar, n);
    sleep(3);
    clock_t end = clock();
    time_compile += (double)(end - beign) / CLOCKS_PER_SEC;
    printf("The compile 