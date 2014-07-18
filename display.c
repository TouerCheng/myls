#include "ls.h"
void display(int flag, char * pathname)
{
    int	   i, j;
    struct stat	buf;
    char   name[NAME_MAX + 1];

    /*从路径中解析出文件名*/
    for (i=0, j=0; i<strlen(pathname); i++) 
    {
        if (pathname[i] == '/') 
        {
            j = 0;
	    continue;
	}
	name[j++] = pathname[i];
    }
    name[j] = '\0';
	
    /*用lstat而不是stat以方便解析链接文件*/
    if ( lstat(pathname, &buf) == -1 ) 
    {
        my_err("stat", __LINE__);
        return;
    }
	
    switch (flag) 
    {
        case PARAM_NONE:  // 没有-l和-a选项
	if (name[0] != '.') 
        {
	    display_single(name);
	}
	break;
        case PARAM_NONE+PARAM_R:  // 没有-l和-a选项
        if (name[0] != '.') 
        {
            display_single(name);
        }
        break;
        case PARAM_NONE+PARAM_R+PARAM_T:  // 没有-l和-a选项
        if (name[0] != '.')
        {
            display_single(name);
        }
        break;
        case PARAM_NONE+PARAM_R+PARAM_S:  // 没有-l和-a选项
        if (name[0] != '.')
        {
            display_single(name);
        }
        break;
        case PARAM_NONE+PARAM_S:  // 没有-l和-a选项
        if (name[0] != '.')
        {
            display_single(name);
        }
        break;
        case PARAM_NONE+PARAM_T:  // 没有-l和-a选项
        if (name[0] != '.')
        {
            display_single(name);
        }
        break;



	case PARAM_A:	  // -a:显示包括隐藏文件在内的所有文件
	display_single(name);
	break;
        case PARAM_A+PARAM_R:     // -a:显示包括隐藏文件在内的所有文件
        display_single(name);
        break; 
        case PARAM_A+PARAM_R+PARAM_S:     // -a:显示包括隐藏文件在内的所有文件
        display_single(name);
        break;
        case PARAM_A+PARAM_R+PARAM_T:     // -a:显示包括隐藏文件在内的所有文件
        display_single(name);
        break;
        case PARAM_A+PARAM_T:     // -a:显示包括隐藏文件在内的所有文件
        display_single(name);
        break;
        case PARAM_A+PARAM_S:     // -a:显示包括隐藏文件在内的所有文件
        display_single(name);
        break;


		
        case PARAM_L:	  // -l:每个文件单独占一行，显示文件的详细属性信息
	if (name[0] != '.') 
        {
	    display_attribute(buf, name);
	    printf("  %-s\n", name);
	}
	break;
        case PARAM_L+PARAM_R:     // -l:每个文件单独占一行，显示文件的详细属性信息
        if (name[0] != '.') 
        {
            display_attribute(buf, name);
            printf("  %-s\n", name);
        }
        break;  
        case PARAM_L+PARAM_S:     // -l:每个文件单独占一行，显示文件的详细属性信息
        if (name[0] != '.')
        {
            display_attribute(buf, name);
            printf("  %-s\n", name);
        }
        break;
        case PARAM_L+PARAM_T:     // -l:每个文件单独占一行，显示文件的详细属性信息
        if (name[0] != '.')
        {
            display_attribute(buf, name);
            printf("  %-s\n", name);
        }
        break;
        case PARAM_L+PARAM_R+PARAM_T:     // -l:每个文件单独占一行，显示文件的详细属性信息
        if (name[0] != '.')
        {
            display_attribute(buf, name);
            printf("  %-s\n", name);
        }
        break;
        case PARAM_L+PARAM_R+PARAM_S:     // -l:每个文件单独占一行，显示文件的详细属性信息
        if (name[0] != '.')
        {
            display_attribute(buf, name);
            printf("  %-s\n", name);
        }
        break;

	case PARAM_A + PARAM_L:		// 同时有-a和-l选项的情况
	display_attribute(buf, name);
	printf("  %-s\n", name);
	break;
        case PARAM_A + PARAM_L+ PARAM_R:         // 同时有-a和-l选项的情况
        display_attribute(buf, name);
        printf("  %-s\n", name);
        break;  
        case PARAM_A + PARAM_L+PARAM_S:         // 同时有-a和-l选项的情况
        display_attribute(buf, name);
        printf("  %-s\n", name);
        break;
        case PARAM_A + PARAM_L+PARAM_T:         // 同时有-a和-l选项的情况
        display_attribute(buf, name);
        printf("  %-s\n", name);
        break;
        case PARAM_A + PARAM_L+ PARAM_R+PARAM_S:         // 同时有-a和-l选项的情况
        display_attribute(buf, name);
        printf("  %-s\n", name);
        break;
        case PARAM_A + PARAM_L+ PARAM_R+PARAM_T:         // 同时有-a和-l选项的情况
        display_attribute(buf, name);
        printf("  %-s\n", name);
        break;



        default:
	break;
	}
}

