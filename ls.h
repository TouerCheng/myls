/*作者：Cheng
 * 实现功能：ls  R S t l a  五个参数
 * 代码风格：华为要求
 */

#ifndef LS_H
#define LS_H

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

#define         PARAM_NONE      0       // 无参数
#define         PARAM_A         1       // -a: 显示所有文件
#define         PARAM_L         2       // -l:一行显示一个文件的详细信息
#define         PARAM_R         4       // -R
#define         PARAM_T         8       // -t
#define         PARAM_S         16      // -S
#define         MAXROWLEN       80      // 一行显示的最多字符数

extern int          g_leave_len ;        // 一行剩余长度，用于输出对齐
extern int          g_maxlen;            // 存放某目录下最长文件名的长度

void display(int flag, char * pathname);
void display_attribute(struct stat buf, char * name);
void display_dir(int flag_param, char *path);
void display_single(char *name);
void my_err(const char *err_string, int line);
#endif //LS_H
