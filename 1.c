#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>

#define		PARAM_NONE	0	// 无参数
#define		PARAM_A		1	// -a: 显示所有文件
#define		PARAM_L		2	// -l:一行显示一个文件的详细信息
#define         PARAM_R         4       // -R
#define		MAXROWLEN	80	// 一行显示的最多字符数

int		g_leave_len = MAXROWLEN;	// 一行剩余长度，用于输出对齐
int		g_maxlen;			// 存放某目录下最长文件名的长度

#include "display_attribute.c"  
#include "display.c"  
#include "display_dir.c"  
#include "display_single.c"   
#include "my_err.c"
#include "main.c" 
