#include<syslog.h>
#include<stdio.h>

int main(int argc , char * argv[])
{
    openlog(NULL, 0, LOG_USER);
    if(argc < 3)
    {
        syslog(LOG_ERR, "Invalid number of arguments : %d", argc - 1);
        closelog();
        return 1;
    } 
    if(argv[1] == NULL)
    {
        syslog(LOG_ERR, "Filename cannot be empty");
        closelog();
        return 1;
    }
    if (argv[2] == NULL)
    {
        syslog(LOG_ERR, "Write argument cannot be empty");
        closelog();
        return 1;
    }
    FILE * fd = fopen(argv[1], "w");
    if(fd == NULL)
    {
        syslog(LOG_ERR, "Unable to open file %s", argv[1]);
        closelog();
    }
    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
    fputs(argv[2], fd);
    fclose(fd);
    return 0;

}