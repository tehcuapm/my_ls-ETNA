#include <time.h>

struct userFile* insert(struct userFile* head, char *data);

struct userFile* insert_reversed(struct userFile* head, char *data);

struct userFile* addToEmpty(char *data);

struct userFile* addToEmptyTime(char *data,struct stat date);

void print_userFiles(struct userFile* head);
struct userFile* addFile(struct userFile* head, char *data);

struct userFile* insert_date(struct userFile* head,char* data, struct stat  date);

struct userFile* insert_date_reversed(struct userFile* head,char* data, struct stat  date);

void let_it_be_userFiles(struct userFile** head);