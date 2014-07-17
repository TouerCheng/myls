void display_single(char *name)
{
    int i, len;

    if (g_leave_len < g_maxlen) 
    {	
        printf("\n");
        g_leave_len = MAXROWLEN;
    }

    len = strlen(name);
    len = g_maxlen - len;
    printf("%-s", name);
	
    for (i=0; i<len; i++) 
    {
        printf(" ");
    }
    printf("  ");
    g_leave_len -= (g_maxlen + 2);
}
