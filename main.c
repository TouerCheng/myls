#include "ls.h"
int		g_leave_len = MAXROWLEN;	
int		g_maxlen;	
int main(int argc, char ** argv)
{
    int		i, j, k, num;
    char	path[PATH_MAX+1];
    char	param[32];	      // 保存命令行参数，目标文件名和目录名不在此列
    int		flag_param = PARAM_NONE; // 用来标志参数种类，即是否有-l和-a选项
    struct stat	buf;


    /*命令行参数的解析，分析-l、-a、-al、-la选项*/
    j  = 0,
    num = 0;
    for (i=1; i<argc; i++) 
    {
        if (argv[i][0] == '-') 
        {
	    for(k=1; k < strlen(argv[i]); k++,j++) 
            {
	        param[j] = argv[i][k];	// 获取-后面的参数保存到数组param中
	    }
	    num++;  // 保存"－"的个数
	}
    }
	
    /*只支持参数a和l和R，如果含有其他选项就报错*/
    for(i=0; i<j; i++) 
    {
        if (param[i] == 'a') 
        {
	    flag_param |= PARAM_A;
	    continue;
	} 
        else if (param[i] == 'l') 
        {
	    flag_param |= PARAM_L;
	    continue;
	}
         else if (param[i] == 'R') 
        {               
            flag_param |= PARAM_R;
            continue;
        } 
        else 
        {
	    printf("my_ls: invalid option -%c\n", param[i]);
	    exit(1);
	}
    }
    param[j] = '\0';
	
	
    if ((num + 1) == argc) 
    {	
        strcpy(path, "./");
	path[2] = '\0';
	display_dir(flag_param, path);
	return 0;
    }

    i=1;
    do 
    {
		
        if (argv[i][0] == '-') 
        { 
            i++;
            continue;	
        } 
        else 
        {
            strcpy(path, argv[i]);

			
            if ( stat(path, &buf) == -1 )  
	    {
                my_err("stat", __LINE__);	
            }
 	    if ( S_ISDIR(buf.st_mode) ) 
            {   
                if ( path[ strlen(argv[i])-1 ] != '/') 
                {
	            path[ strlen(argv[i]) ] = '/';
	            path[ strlen(argv[i])+1 ] = '\0';
	        }
	        else
	            path[ strlen(argv[i]) ] = '\0';

	    display_dir(flag_param,path);
	    i++;
	    }  
            else 
            {  
                display(flag_param, path);
                i++;
	    }
	}
} while (i<argc);

return 0;
}
