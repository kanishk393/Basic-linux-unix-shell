#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<dirent.h>
#include <time.h>
// #include<readline/readline.h>
// #include<readline/history.h>

char i_eqls(char a[],char b[],int size)    {
    int i;
    for(i=0;i<size;i++){
        if(a[i]!=b[i])
            return 1;
    }
   if(a[size+1]==b[size+1])
      return 0;
   else
      return 1;
    return 0;
}
char i_eql(char a[],char b[],int size,int count)    {
    if(count==1)
    {
          int i;
         for(i=0;i<size;i++){
            if(a[i]!=b[i])
                  return 1;
         }
         if(a[size+1]==b[size+1])
            return 0;
         else
            return 1;
         return 0;

    }
    else
    {
       int i;
         for(i=0;i<size+1;i++){
            if(a[i]!=b[i])
                  return 1;
         }
    }
    return 0;
   
}
 void echo(char f_comm[200][200],int k)
{
            int t = 0;
            int i = 1;
            while(t==0)
            {
               if(f_comm[i][0]=='\0')
               {
                  i++;
               }
               else
               {
                  t=1;
               }
            }
            // printf(" ii%c90",f_comm[i][0]);
            // printf("i=%d",i);

            // for(int j = i;j<sizeof f_comm;j++ )

            // {
            //    printf("  %s",f_comm[j]); //correction needed
            // }
            if(f_comm[i][0]=='-'&&f_comm[i][1]=='h'&&f_comm[i][2]=='e'&&f_comm[i][3]=='l'&&f_comm[i][4]=='p')
            {
               printf("  help--\n");
               printf("  echo [STRING]... or echo *");
            }
            if(f_comm[i][0]=='*'){
                  
                  char path[100];
   
                        
                  getcwd(path, sizeof(path));
                  struct dirent *dp;
                  DIR *dir = opendir(path);
                  
                  while ((dp = readdir(dir)) != NULL)
                  {
                     if (dp->d_name[0] != '.')
                        printf("%s  ", dp->d_name);
                  }
                  printf("\n");
               
               }
            else{
            printf(" "); 
            while(i<k)
            {  
               if (f_comm[i][0]=='\0')
               {
                  i++;
                  
               }
               else
               {
                  printf(" %s",f_comm[i]);
                  i++;
               }
               // printf("%s ",f_comm[i]);
               // i++;
            }
            // int t =0;
            // int i =1;
            // while(t==0)
            // {
            //    if(f_comm[i][0]=='\0')
            //    {
            //       i++;
            //    }
            //    else
            //    {
            //       t=1;
            //    }
            // }
            

               
            }
            if(f_comm[i][0]!='\0'){printf("\n");} 

}
        
      
void currentdir(char* username)
{
   char *dir;
   dir=(char *)malloc(1024*sizeof(char));
   getcwd(dir,1024);
   if (getcwd(dir,1024) == NULL)
      printf("error or path exceeds the limits");
   else
      printf("• %s@%s-%s:~ ",username,username,dir);
      
}
// void cd(char f_comm[])
// {
//    int i = 1;
//    while(f_comm[i][0]=='\0')
//    {
//       i++;
//    }
//    if(f_comm[i][0]=='\0')
//    {
//       chdir("/home");
//    }
//    else
//    {
//       chdir(f_comm[i]);
//    }
// }
void main()
{
   
   char internal_commands[200][200]={"cd","echo","pwd","exit"};
   char external_commands[200][200]={"ls","cat","mkdir","date","rm"};
   char space[200][200]={' '};
   char ls[200][200]={"-m","-a"};
   char date[200][200]={"-R","-u"};
   char cd[200][200]={"~","/"};
   // printf("exit %s",commands[4]);
   int opt=1;
   char* username = getenv("USER");
   printf("                         Welcome %s                         ",username);
   printf("\n");
   printf("\n");
   sleep(0.5);
   char path[100];
   
         // printf("%d\n", argc);
   getcwd(path, sizeof(path));
         
         
   // clear();
   while (opt==1)
   {
      int j = 0;
      int k = 0;
      // printf(" Input  a string : ");
      char r_comm[4096];
      char f_comm[200][200]; 
      currentdir(username);
      fgets(r_comm, sizeof r_comm, stdin);
      // printf("a r%d",argc);
      // int count = 0
      // whille

      int flag=0;
      int it=0;
      while(flag==0)
      {
         if(r_comm[it]==' ')
         {
            it++;
         }
         else
         {
            flag=1;
         }
         
      }
      for(int i =it;i<=(strlen(r_comm));i++)
      {
         // if space or NULL found, assign NULL into f_comm[k]
         if(r_comm[i]==' '||r_comm[i]=='\0')
         {
            f_comm[k][j]='\0';
            k++;  //for next word
            j=0;    //for next word, init index to 0
         }
         else
         {
            f_comm[k][j]=r_comm[i];
            j++;
         }
      }
      int count =0;
      for(int i =0; i<k;i++)
      {
         if(f_comm[i][0]!='\0')
         {
            count++;
         }
         else{
            continue;
         }
         
         // printf(" %s",f_comm[i]);
      }
      // printf("count %d",count);
      // for(int i = 0; i<k; i++)
      // {
      //    printf("% d %s",i,f_comm[i]);
      //    printf("\n");
      // }   
      // printf("%s",f_comm[1]);

      // if(i_eql(f_comm[0],internal_commands[1],4)==0)
      
      if(i_eql(f_comm[0],internal_commands[1],4,count)==0)
      {  
         // printf("  echo\n");
         // if(f_comm[1][0]=='"')
         // {
         //    int i=1;
         //    while(f_comm[1][i]!='"')
         //    {
         //       printf("  %c",f_comm[1][i]);
         //       i++;
         //    }
         //    printf("\n");
         // }
         // else
         // {
         //    printf("  %s\n",f_comm[1]);
         // }
         echo(f_comm,k);
      }
      else if(i_eql(f_comm[0],internal_commands[2],3,count)==0)
      {
         char *dir;
         dir=(char *)malloc(1024*sizeof(char));
         getcwd(dir,1024);
         if (getcwd(dir,1024) == NULL)
            printf("error or path exceeds the limits");
         else
            printf("  %s",dir);
            printf("\n");
      }
      else if(i_eql(f_comm[0],internal_commands[0],2,count)==0)
      {
         printf("  cd\n");
         
         // int i = 1;
         // while(f_comm[i][0]=='\0')
         // {
         //    i++;
         // }
         // if(f_comm[i][0]=='\0')
         // {
         //    chdir("/home");
         // }
         // else
         // {
         //    chdir(f_comm[i]);
         // }
         if(count==1)
         {
            chdir("..");
         }
         else if(count=2)
         {  
            int t =0;
            int i =1;
            while(t==0)
            {
               if(f_comm[i][0]=='\0')
               {
                  i++;
               }
               else
               {
                  t=1;
               }
            }
            if(i_eqls(f_comm[i],cd[1],1)==0)
            {
               chdir("/");
            }
            else if(i_eqls(f_comm[i],cd[0],1)==0)
            {
               chdir("/home");
            }
            else{
            printf("Invalid arguement");
            printf("\n");
         }
         
         }
         else{
            printf("Invalid arguement");
            printf("\n");
         }
         
         
      }
      else if(i_eql(f_comm[0],internal_commands[3],4,count)==0)
      {
         printf("  exit\n");
         opt =0;
      }
      else if(i_eql(f_comm[0],external_commands[0],2,count)==0)
      {  
         char name[200][200];
         int t = 0;
         int i = 1;
         while(t==0)
         {
            if(f_comm[i][0]=='\0')
            {
               i++;
            }
            else
            {
               t=1;
            }
         }
         if(count==1||i_eqls(f_comm[i],ls[0],2)==0)
         {

         
            
            struct dirent *dp;
            DIR *dir = opendir(path);
            
            while ((dp = readdir(dir)) != NULL)
            {
               if (dp->d_name[0] != '.')
                  printf("%s  ", dp->d_name);
            }
            printf("\n");

         }
         
         if(count==2)
         {
            if(i_eqls(f_comm[i],ls[1],2)==0)
            {
               
               struct dirent *dp;
               DIR *dir = opendir(path);
               
               while ((dp = readdir(dir)) != NULL)
               {
                  printf("%s  ", dp->d_name);
               }
               printf("\n");
            }
           
         }
         // {
         //    int t = 0;
         //    int i = 1;
         //    while(t==0)
         //    {
         //       if(f_comm[i][0]=='\0')
         //       {
         //          i++;
         //       }
         //       else
         //       {
         //          t=1;
         //       }
         //    }
         //    if(f_comm[i])
         //    printf("  ls\n");
         
         //    struct dirent *dp;
         //    DIR *dir = opendir(path);
            
         //    while ((dp = readdir(dir)) != NULL)
         //    {
               
         //          printf("%s  ", dp->d_name);
         //    }
         //    printf("\n");

         // }
         else if(count>2){
            printf("  Pass valid arguements\n");
         }
         // else if(count>1)
         // {
         //    struct dirent *dp;
         //    DIR *dir = opendir(path);
            
         //    while ((dp = readdir(dir)) != NULL)
         //    {
         //       if (dp->d_name[0] != '.')
                  
         //          for(int i =0;i<strlen(dp->d_name);i++)
         //          {
         //             name[i]=dp->d_name[i];
                    
         //          }
         //    }
         //    // for(int i =0;i<strlen(dp->d_name);i++)
         //    // {
         //    //    printf("%c ",name[i]);
         //    //    j++;
         //    // }
         //    int a =0;
         //    int j=0;
         //    for(int i =it;i<=(strlen(dp->d_name));i++)
         //    {
         //       // if space or NULL found, assign NULL into f_comm[k]
         //       if(dp->d_name[i]==' '||dp->d_name[i]=='\0')
         //       {
         //          name[a][j]='\0';
         //          a++;  //for next word
         //          j=0;    //for next word, init index to 0
         //       }
         //       else
         //       {
         //          name[a][j]=dp->d_name[i];
         //          j++;
         //       }
         //    }
         //    for(int i =0;i<a;i++)
         //    {
         //       printf("%s ",name[i]);
               
         //    }
         // }
      }
      else if(i_eql(f_comm[0],external_commands[1],3,count)==0)
      {
         printf("  cat\n");
      }
      else if(i_eql(f_comm[0],external_commands[2],5,count)==0)
      {
         printf("  mkdir\n");
      }
      else if(i_eql(f_comm[0],external_commands[3],4,count)==0)
      {
         
         time_t currenttime;
         currenttime = time(NULL);
         struct tm *timeinfo;
         timeinfo = localtime(&currenttime);
         struct timeval tv;
         char timebuffer[64];
         gettimeofday(&tv, NULL);
         currenttime = tv.tv_sec;
         int t = 0;
            int i = 1;
            while(t==0)
            {
               if(f_comm[i][0]=='\0')
               {
                  i++;
               }
               else
               {
                  t=1;
               }
            }
           
      
         if(count==1)
         {
            timeinfo=localtime(&currenttime);
            strftime (timebuffer, sizeof timebuffer,"%a %d %b %H:%M:%S %p IST ", timeinfo);
            printf("%s", timebuffer);
            printf("\n");
         }
         else if(count==2)
         {

            if(i_eqls(f_comm[i],date[0],2)==0)
            {
               timeinfo=localtime(&currenttime);
               strftime (timebuffer, sizeof timebuffer,"%a, %d %b %Y %H:%M:%S %p +0530 ", timeinfo);
               printf("%s", timebuffer);
            }
            else if(i_eqls(f_comm[i],date[1],2)==0)
            {
               timeinfo = gmtime(&currenttime);
               strftime (timebuffer, sizeof timebuffer,"%a %d %b %Y %H:%M:%S %p UTC ", timeinfo);
               printf("%s", timebuffer);
            }
            else
            {
               printf("date: invalid option -- '%s'",f_comm[i]);
            }
            printf("\n");  
               
         }
      }
      else if(i_eql(f_comm[0],external_commands[4],2,count)==0)
      {
         printf("  rm\n");
      }
      // else if(f_comm[0][0]=='\0')
      // {
      //    continue;
      // }
      else
      {
         printf("  %s: command not found\n",f_comm[0]);
      }
      
      
      memset(f_comm, 0, sizeof(f_comm));
      memset(r_comm, 0, sizeof r_comm);
   }
   

}
