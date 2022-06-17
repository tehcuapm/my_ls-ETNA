#include "../include/structs/llist.h"
#include "../include/pools_functions.h"
#include "../include/sort_files.h"
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>   

#include <stdio.h>

int alphabetical_sort(char *string, char *string2)
{
    int i = 0;
    int a;
    char *tempStr = string;
    char *tempStr2 = string2;
    tempStr = my_strlowcase(tempStr);
    tempStr2 = my_strlowcase(tempStr2);

    while (tempStr[i] != '\0' || tempStr2[i] != '\0' )
    {
        if(tempStr[i] < tempStr2[i])
        {
            a=0;
            break;
        }
        else if (tempStr[i] == tempStr2[i])
        {
            i++;
        }
        else{
            a=1;
            break;
        }
        
    }
    free(tempStr);
    free(tempStr2);
    return a;
}
struct userFile* addToEmpty(char *data){
    
    struct userFile* temp = malloc(sizeof(struct userFile));
    temp->file = data;
    temp->link = NULL;
    return temp;
}
struct userFile* addToEmptyTime(char *data, struct stat stat){
    
    struct userFile* temp = malloc(sizeof(struct userFile));
    temp->file = data;
    temp->stat = stat;
    temp->link = NULL;
    return temp;
}
void print_userFiles(struct userFile* head){
    struct userFile* temp = head;
    while (temp !=NULL)
            {
        
                my_putchr(' ');
                my_putstr(temp->file);
                my_putchr('\n');

            temp = temp->link;
            }
    
}
void let_it_be_userFiles(struct userFile** head){
    struct userFile* temp = *head;
    struct userFile* link;
    while (temp !=NULL)
    {
        link = temp->link;
        free(temp);
        temp = link;
    }
    *head = NULL;
    
}
struct userFile* addFile(struct userFile* head, char *data){
    struct userFile* newFile = malloc(sizeof(struct userFile));
    newFile->file = data;
    newFile->link = NULL;
        
    struct userFile* temp = head;
    while ( temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newFile;
    return head;
}

struct userFile* insert_date(struct userFile* head,char* data,struct stat buf){
    struct userFile* temp = head;
    struct userFile* newFile = malloc(sizeof(struct userFile));
    newFile->file = data;
    newFile->stat = buf;
    newFile->link = NULL;
    long long int key = buf.st_mtim.tv_sec*1000000000 + buf.st_mtim.tv_nsec;
  
    if(head == NULL || key < (long long int)head->stat.st_mtim.tv_sec *1000000000 + head->stat.st_mtim.tv_nsec){
         
        newFile->link = head;
        head = newFile;
    } 


    else{

        while ( (temp->link != NULL && temp->link->stat.st_mtim.tv_sec*1000000000 + temp->link->stat.st_mtim.tv_nsec > key))
        {
            temp = temp->link;
            
        }
    newFile->link =temp->link;
    temp->link = newFile;
    
    }
    return head;
    
} 
struct userFile* insert_date_reversed(struct userFile* head,char* data,struct stat buf){
    struct userFile* temp = head;
    struct userFile* newFile = malloc(sizeof(struct userFile));
    newFile->file = data;
    newFile->stat = buf;
    newFile->link = NULL;
    long int key = buf.st_mtim.tv_sec;
    if(head == NULL || key < (long int)head->stat.st_mtim.tv_sec){
         
        newFile->link = head;
        head = newFile;
    } 


    else{
        while ( (temp->link != NULL && (long int)temp->link->stat.st_mtim.tv_sec > key))
        {
            temp = temp->link;
          
        }
    newFile->link =temp->link;
    temp->link = newFile;
    
    }
    return head;
    
} 

struct userFile* insert(struct userFile* head, char *data){
    struct userFile* temp = head;
    struct userFile* newFile = malloc(sizeof(struct userFile));
    newFile->file = data;
    newFile->link = NULL;
    char *key = data;
    if(head == NULL || alphabetical_sort(key,head->file)==0){
         
        newFile->link = head;
        head = newFile;
    }
    else{
        while (temp->link != NULL && alphabetical_sort(temp->link->file,key)==0)
        {
            temp = temp->link;
          
        }
    newFile->link =temp->link;
    temp->link = newFile;
    
    }
    return head;
    
} 

struct userFile* insert_reversed(struct userFile* head, char *data){
    struct userFile* temp = head;
    struct userFile* newFile = malloc(sizeof(struct userFile));
    newFile->file = data;
    newFile->link = NULL;
    char *key = data;
    if(head == NULL || alphabetical_sort(key,head->file)==1){
         
        newFile->link = head;
        head = newFile;
    }
    else{
        while (temp->link != NULL && alphabetical_sort(temp->link->file,key)==1)
        {
            temp = temp->link;
          
        }
    newFile->link =temp->link;
    temp->link = newFile;
    
    }
    return head;
}