int n;
    struct node *x, *y, *p;
    printf("Number of nodes: ");
    scanf("%d", &n);

    x = (struct node *)malloc(sizeof(struct node));
    printf("Enter Node 1 data: ");
    scanf("%d", &x->data);

    y = x;

    for (int i = 2; i <= n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        printf("Enter Node %d data: ", i);
        scanf("%d", &p->data);
        y->next = p;
        y = p;
    }

    y->next = NULL;
    y = x;