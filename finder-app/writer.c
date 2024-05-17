/* author_name: Myriam Youssef*/ 

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc < 3)
    {
        fprintf(stderr, "ERROR: Command shall be used as follow: %s <file> <string>",argv[0]);
        return 1;
    }

    const char * writefile = argv[1];
    const char * writestr = argv[2];
    ssize_t err;

    /* Oplen syslog to start logging */
    openlog("Writer App Logs", 0, LOG_USER);
    
    syslog(LOG_DEBUG,"Writing string: %s to file: %s \n", writestr, writefile);

    /*Open file */
    int fd = open(writefile, O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
    if (fd == -1)
    {
        syslog(LOG_ERR,"Error: Couldn't open the file \n");
        return 1;
    }

    /* Start writing the string into the file*/
    ssize_t count =  strlen(writestr);
    err = write (fd, writestr, strlen(writestr));

    /*check for error and partial write*/
    if (err == -1)
    syslog(LOG_ERR,"Error: error, check errno \n");
    else if (err != count)
    syslog(LOG_ERR,"Error: possible error, but 'errno' not set  \n");
    else
    syslog(LOG_DEBUG,"Writer.c: Succesfully wrote string to file \n");
    
    close(fd);
    closelog();

    return 0;
}