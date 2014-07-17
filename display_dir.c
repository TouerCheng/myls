#include "ls.h"
void display_dir(int flag_param, char *path)
{
    DIR            *dir;   //目录流符号
    struct dirent  *ptr;
    int       count = 0;   //文件数量
    char  filenames[2047][255],temp[255];

    /*取该目录下文件总数和最长的文件名*/
    dir = opendir(path);
    if (dir == NULL) 
    {
        my_err("opendir", __LINE__);
        return;
    }
    while((ptr = readdir(dir))!=NULL) 
    {
        if (g_maxlen < strlen(ptr->d_name))
        {
            g_maxlen =  strlen(ptr->d_name);
        }
        count++;
    }
    closedir(dir);

    if(count>2047)
    {
       my_err("too many files under this dir",__LINE__);
    }		
    int i, j, len = strlen(path);
  
    /*取该目录下所有的文件名*/
    dir = opendir(path);
    for(i = 0; i < count; i++)
    {
       ptr = readdir(dir);
       if( ptr == NULL)
       {
           my_err("readdir",__LINE__);
       }
       strncpy(filenames[i],path,len);
       filenames[i][len] = '\0';
       strcat(filenames[i],ptr->d_name);
       filenames[i][len+strlen(ptr->d_name)] = '\0';
    }

    /*使用冒泡法对文件名进行排序，排序后文件名按字母顺序存储于filenames*/
    for(i = 0; i < count-1; i++)
    for(j = 0; j < count-1-i; j++) 
    {
        if( strcmp(filenames[j],filenames[j+1]) > 0 ) 
        {
            strcpy(temp,filenames[j+1]);
            temp[strlen(filenames[j+1])] = '\0';
            strcpy(filenames[j+1],filenames[j]);
            filenames[j+1][strlen(filenames[j])] = '\0';
            strcpy(filenames[j], temp);
            filenames[j][strlen(temp)] = '\0';
        }
    }
    for(i = 0; i < count; i++)
    {
    display(flag_param, filenames[i]);
    }
    closedir(dir);


    if((flag_param==4)||(flag_param==6)) 
    {
       struct stat bufnow; 
       for(i = 0; i < count; i++)
       {   
           int jnow=0,inow;
           char  namenow;
           for (inow=0; inow<strlen(filenames[i]); inow++) 
           {
               if (filenames[i][inow] == '/') 
               {
	           jnow=inow+1;
                   continue;
	       }
	   namenow= filenames[i][jnow];
           }
          if(namenow=='.')
          {
              continue;
          }

          
          if (filenames[i][strlen(filenames[i])-1]=='.')
          {
             continue;
          }
           if (filenames[i][strlen(filenames[i])-2]=='.')
          {
             continue;
          }
          if ( stat(filenames[i], &bufnow) == -1 )  
	  {
           printf("specal error"); 
          }
          if ( S_ISDIR(bufnow.st_mode) )
          {     
              strcat(filenames[i],"/");
              printf("\n%s:\n",filenames[i]);
              display_dir(flag_param,filenames[i] );
          } 
       }
    }
    if((flag_param==5)||(flag_param==7))
    {
       struct stat bufnow;
       for(i = 0; i < count; i++)
       {

          if (filenames[i][strlen(filenames[i])-1]=='.')
          {
             continue;
          }
           if (filenames[i][strlen(filenames[i])-2]=='.')
          {
             continue;
          }
          if ( stat(filenames[i], &bufnow) == -1 )
          {
           printf("specal error");
          }
          if ( S_ISDIR(bufnow.st_mode) )
          {
              strcat(filenames[i],"/");
              printf("\n%s:\n",filenames[i]);
              display_dir(flag_param,filenames[i] );
          }
       }
    }

    /*如果命令行中没有-l选项，打印一个换行符*/
    if( (flag_param & PARAM_L) == 0)
    {
       printf("\n");
    }
}






