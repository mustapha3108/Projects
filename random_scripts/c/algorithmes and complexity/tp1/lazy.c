    printf("-------------random100--------------\n");

    //algo1
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo1(random100[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random100->algo1: %f seconds \n", elapsed);
    printf("random100 algo1: %f seconds\n", elapsed);

    //algo2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo2(random100[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random100->algo2: %f seconds \n", elapsed);
    printf("random100 algo1: %f seconds\n", elapsed);

    //algo3
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo3(random100[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random100->algo3: %f seconds \n", elapsed);
    printf("random100 algo3: %f seconds\n", elapsed);

    //algo4
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo4(random100[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random100->algo4: %f seconds \n", elapsed);
    printf("random100 algo4: %f seconds\n", elapsed);

    //clock algo 2
    printf("-------------random1000--------------\n");

    //algo1
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<1000; i++){ algo1(random1000[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random1000->algo1: %f seconds \n", elapsed);
    printf("random1000 algo1: %f seconds\n", elapsed);

    //algo2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<1000; i++){ algo2(random1000[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random1000->algo2: %f seconds \n", elapsed);
    printf("random1000 algo1: %f seconds\n", elapsed);

    //algo3
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<1000; i++){ algo3(random1000[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random1000->algo3: %f seconds \n", elapsed);
    printf("random1000 algo3: %f seconds\n", elapsed);

    //algo4
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<1000; i++){ algo4(random1000[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random1000->algo4: %f seconds \n", elapsed);
    printf("random1000 algo4: %f seconds\n", elapsed);



    printf("-------------test1--------------\n");

    //algo1
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo1(test1[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test1->algo1: %f seconds \n", elapsed);
    printf("test1 algo1: %f seconds\n", elapsed);

    //algo2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo2(test1[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test1->algo2: %f seconds \n", elapsed);
    printf("test1 algo1: %f seconds\n", elapsed);

    //algo3
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo3(test1[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test1->algo3: %f seconds \n", elapsed);
    printf("test1 algo3: %f seconds\n", elapsed);

    //algo4
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo4(test1[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test1->algo4: %f seconds \n", elapsed);
    printf("test1 algo4: %f seconds\n", elapsed);


    printf("-------------test2--------------\n");

    //algo1
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo1(test2[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test2->algo1: %f seconds \n", elapsed);
    printf("test2 algo1: %f seconds\n", elapsed);

    //algo2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo2(test2[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test2->algo2: %f seconds \n", elapsed);
    printf("test2 algo1: %f seconds\n", elapsed);

    //algo3
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo3(test2[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test2->algo3: %f seconds \n", elapsed);
    printf("test2 algo3: %f seconds\n", elapsed);

    //algo4
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo4(test2[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test2->algo4: %f seconds \n", elapsed);
    printf("test2 algo4: %f seconds\n", elapsed);


    printf("-------------test3--------------\n");

    //algo1
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo1(test3[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test3->algo1: %f seconds \n", elapsed);
    printf("test3 algo1: %f seconds\n", elapsed);

    //algo2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo2(test3[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test3->algo2: %f seconds \n", elapsed);
    printf("test3 algo1: %f seconds\n", elapsed);

    //algo3
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo3(test3[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test3->algo3: %f seconds \n", elapsed);
    printf("test3 algo3: %f seconds\n", elapsed);

    //algo4
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo4(test3[i]); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test3->algo4: %f seconds \n", elapsed);
    printf("test3 algo4: %f seconds\n", elapsed);

    fclose(res);