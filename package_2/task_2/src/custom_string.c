#include <stdlib.h>
#include "custom_string.h"

#if defined(__linux__)
const char* linux_error_messages[ERRMSG_ARRAY_SIZE] = {
    "Success",
    "Operation not permitted",    
    "No such file or directory",  
    "No such process",            
    "Interrupted system call",    
    "Input/output error",         
    "No such device or address",  
    "Argument list too long",     
    "Exec format error",          
    "Bad file descriptor",        
    "No child processes",         
    "Resource temporarily unavailable", 
    "Cannot allocate memory",     
    "Permission denied",          
    "Bad address",                
    "Block device required",      
    "Device or resource busy",    
    "File exists",                
    "Invalid cross-device link",  
    "No such device",             
    "Not a directory",            
    "Is a directory",             
    "Invalid argument",           
    "Too many open files in system", 
    "Too many open files",        
    "Inappropriate ioctl for device", 
    "Text file busy",             
    "File too large",             
    "No space left on device",    
    "Illegal seek",               
    "Read-only file system",      
    "Too many links",             
    "Broken pipe",                
    "Numerical argument out of domain", 
    "Numerical result out of range", 
    "Resource deadlock avoided",  
    "File name too long",         
    "No locks available",         
    "Function not implemented",   
    "Directory not empty",        
    "Too many levels of symbolic links", 
    "Unknown error 41",           
    "No message of desired type", 
    "Identifier removed",         
    "Channel number out of range", 
    "Level 2 not synchronized",   
    "Level 3 halted",             
    "Level 3 reset",              
    "Link number out of range",   
    "Protocol driver not attached", 
    "No CSI structure available", 
    "Level 2 halted",             
    "Invalid exchange",           
    "Invalid request descriptor", 
    "Exchange full",              
    "No anode",                   
    "Invalid request code",       
    "Invalid slot",               
    "Unknown error 58",           
    "Bad font file format",       
    "Device not a stream",        
    "No data available",          
    "Timer expired",              
    "Out of streams resources",   
    "Machine is not on the network", 
    "Package not installed",      
    "Object is remote",           
    "Link has been severed",      
    "Advertise error",            
    "Srmount error",              
    "Communication error on send", 
    "Protocol error",             
    "Multihop attempted",         
    "RFS specific error",         
    "Bad message",                
    "Value too large for defined data type", 
    "Name not unique on network", 
    "File descriptor in bad state", 
    "Remote address changed",     
    "Can not access a needed shared library", 
    "Accessing a corrupted shared library", 
    ".lib section in a.out corrupted", 
    "Attempting to link in too many shared libraries", 
    "Cannot exec a shared library directly", 
    "Invalid or incomplete multibyte or wide character", 
    "Interrupted system call should be restarted", 
    "Streams pipe error",         
    "Too many users",             
    "Socket operation on non-socket", 
    "Destination address required", 
    "Message too long",           
    "Protocol wrong type for socket", 
    "Protocol not available",     
    "Protocol not supported",     
    "Socket type not supported",  
    "Operation not supported",    
    "Protocol family not supported", 
    "Address family not supported by protocol", 
    "Address already in use",     
    "Cannot assign requested address", 
    "Network is down",            
    "Network is unreachable",     
    "Network dropped connection on reset", 
    "Software caused connection abort", 
    "Connection reset by peer",   
    "No buffer space available",  
    "Transport endpoint is already connected", 
    "Transport endpoint is not connected", 
    "Cannot send after transport endpoint shutdown", 
    "Too many references: cannot splice", 
    "Connection timed out",       
    "Connection refused",         
    "Host is down",               
    "No route to host",           
    "Operation already in progress", 
    "Operation now in progress",  
    "Stale file handle",          
    "Structure needs cleaning",   
    "Not a XENIX named type file", 
    "No XENIX semaphores available", 
    "Is a named type file",       
    "Remote I/O error",           
    "Disk quota exceeded",        
    "No medium found",            
    "Wrong medium type",          
    "Operation canceled",         
    "Required key not available", 
    "Key has expired",            
    "Key has been revoked",       
    "Key was rejected by service", 
    "Owner died",                 
    "State not recoverable",      
    "Operation not possible due to RF-kill", 
    "Memory page has hardware error" 
};
#else
const char* macos_error_messages[ERRMSG_ARRAY_SIZE] = {
    "Undefined error: 0",         
    "Operation not permitted",    
    "No such file or directory",  
    "No such process",            
    "Interrupted system call",    
    "Input/output error",         
    "Device not configured",      
    "Argument list too long",     
    "Exec format error",          
    "Bad file descriptor",        
    "No child processes",         
    "Resource deadlock avoided",  
    "Cannot allocate memory",     
    "Permission denied",          
    "Bad address",                
    "Block device required",      
    "Resource busy",              
    "File exists",                
    "Cross-device link",          
    "Operation not supported by device", 
    "Not a directory",            
    "Is a directory",             
    "Invalid argument",           
    "Too many open files in system", 
    "Too many open files",        
    "Inappropriate ioctl for device", 
    "Text file busy",             
    "File too large",             
    "No space left on device",    
    "Illegal seek",               
    "Read-only file system",      
    "Too many links",             
    "Broken pipe",                
    "Numerical argument out of domain", 
    "Result too large",           
    "Resource temporarily unavailable", 
    "Operation now in progress",  
    "Operation already in progress", 
    "Socket operation on non-socket", 
    "Destination address required", 
    "Message too long",           
    "Protocol wrong type for socket", 
    "Protocol not available",     
    "Protocol not supported",     
    "Socket type not supported",  
    "Operation not supported",    
    "Protocol family not supported", 
    "Address family not supported by protocol family", 
    "Address already in use",     
    "Can't assign requested address", 
    "Network is down",            
    "Network is unreachable",     
    "Network dropped connection on reset", 
    "Software caused connection abort", 
    "Connection reset by peer",   
    "No buffer space available",  
    "Socket is already connected", 
    "Socket is not connected",    
    "Can't send after socket shutdown", 
    "Too many references: can't splice", 
    "Connection timed out",       
    "Too many levels of symbolic links", 
    "Connection refused",         
    "File name too long",         
    "Host is down",               
    "No route to host",           
    "Directory not empty",        
    "Too many processes",         
    "Too many users",             
    "Disc quota exceeded",        
    "Stale NFS file handle",      
    "Too many levels of remote in path", 
    "RPC struct is bad",          
    "RPC version wrong",          
    "RPC prog. not avail",        
    "Program version wrong",      
    "Bad procedure for program",  
    "No locks available",         
    "Function not implemented",   
    "Inappropriate file type or format", 
    "Authentication error",       
    "Need authenticator",         
    "Device power is off",        
    "Device error",               
    "Value too large to be stored in data type", 
    "Bad executable (or shared library)", 
    "Bad CPU type in executable", 
    "Shared library version mismatch", 
    "Malformed Mach-o file",      
    "Operation canceled",         
    "Identifier removed",         
    "No message of desired type", 
    "Illegal byte sequence",      
    "Attribute not found",        
    "Bad message",                
    "EMULTIHOP (Reserved)",       
    "No message available on STREAM", 
    "ENOLINK (Reserved)",         
    "No STREAM resources",        
    "Not a STREAM",               
    "Protocol error",             
    "STREAM ioctl timeout",       
    "Operation not supported on socket", 
    "Policy not found",           
    "State not recoverable",      
    "Previous owner died",        
    "Interface output queue is full", 
};
#endif

void *custom_memchr(const void *str, int c, size_t n) {
    if (str == NULL) {
        return NULL;
    }

    unsigned char *s = (unsigned char *)str;
    c = (unsigned char)c;

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == c) {
            return (void *)(s + i);
        }
    }

    return NULL;
}

int custom_memcmp(const void *str1, const void *str2, size_t n) {
    if (str1 == NULL || str2 == NULL) {
        return -2;
    }

    unsigned char *s1 = (unsigned char *)str1;
    unsigned char *s2 = (unsigned char *)str2;

    for (size_t i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            return ((int)s1[i] < (int)s2[i]) ? -1 : 1;
        }
    }

    return 0;
}

void *custom_memcpy(void *dest, const void *src, size_t n) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }

    char *d = (char *)dest;
    char *s = (char *)src;

    for (size_t i = 0; i < n; ++i) {
        d[i] = s[i];
    }

    return dest;
}

void *custom_memset(void *str, int c, size_t n) {
    if (str == NULL) {
        return NULL;
    }

    unsigned char *s = (unsigned char *)str;

    for (size_t i = 0; i < n; ++i) {
        s[i] = (unsigned char)c;
    }

    return str;
}

char *custom_strncat(char *dest, const char *src, size_t n) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }

    char *start = dest;

    while (*dest != '\0') {
        dest++;
    }

    size_t copied = 0;

    while (copied < n && *src != '\0') {
        *dest = *src;
        dest++;
        src++;
        copied++;
    }

    *dest = '\0';
    
    return start;
}

char *custom_strchr(const char *str, int c) {
    if (str == NULL) {
        return NULL;
    }

    char ch = (char)c;

    while (*str != '\0') {
        if (ch == *str) {
            return (char *)str;
        }

        str++;
    }

    return NULL;
}

int custom_strncmp(const char *str1, const char *str2, size_t n) {
    if (str1 == NULL || str2 == NULL) {
        return -2;
    }

    size_t compered = 0;
    while (*str1 != '\0' && *str2 != '\0' && compered < n) {
        if (*str1 != *str2) {
            return (*str1 < *str2) ? -1 : 1;
        }

        str1++;
        str2++;
        compered++;
    }

    if (compered == n) {
        return 0;
    } else {
        return -2;
    }
}

char *custom_strncpy(char *dest, const char *src, size_t n) {
    if (dest == NULL || src == NULL) {
        return dest;
    }
    size_t i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}

size_t custom_strcspn(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }
    
    size_t len = 0;

    while (*str1 != '\0') {
        const char *current = str2;
        int flag = 0;
        while (*current != '\0') {
            if (*str1 == *current) {
                flag = 1;
                break;
            }
            current++;
        }

        if (flag) {
            return len;
        }

        len++;
        str1++;
    }

    return len;
}

char *custom_strerror(int errnum) {
    if (errnum < 0 || errnum >= ERRMSG_ARRAY_SZ) {
        return "Unknown error";
    }
    return (char *)ERRMSG_ARRAY[errnum];
}

size_t custom_strlen(const char *str) {
    if (str == NULL) {
        return 0;
    }

    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }

    return len;
}

char *custom_strpbrk(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    const char *s1 = str1;
    int flag = 0;
    while (*s1 != '\0') {
        const char *s2 = str2;

        while (*s2 != '\0') {
            if (*s1 == *s2) {
                flag = 1;
                break;
            }

            s2++;
        }
        
        if (flag) {
            return (char *)s1;
        }
        
        s1++;
    }

    return NULL;
}

char *custom_strrchr(const char *str, int c) {
    if (str == NULL) {
        return NULL;
    }

    unsigned char ch = (unsigned char)c;
    const char *s = str;
    const char *s_result = str;

    while (*s != '\0') {
        if (*s == ch) {
            s_result = s;
        }

        s++;
    }

    if ((unsigned char)c == '\0') {
        return (char *)s;  
    }

    return (char *)s_result;
}

char *custom_strstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) {
        return NULL;
    }
    
    if (*needle == '\0') {
        return (char *)haystack;
    }
    
    const char *stack = haystack;
    while (*stack != '\0') {
        const char *internal_stack = stack;
        const char *internal_needle = needle;

        while (*internal_stack != '\0' && *internal_stack == *internal_needle) {
            internal_needle++;
            internal_stack++;
        }

        if (*internal_needle == '\0') {
            return (char *)stack;
        } 

        stack++;
    }

    return NULL;
}

char *custom_strtok(char *str, const char *delim) {
    if (delim == NULL) {
        return NULL;
    }

    static char *next_token = NULL;

    char *token_start = str ? str : next_token;

    if (token_start == NULL) {
        return NULL;
    }

    while (*token_start != '\0') {
        const char *d = delim;
        int is_delim = 0;

        while (*d != '\0') {
            if (*token_start == *d) {
                is_delim = 1;
                break;
            }

            d++;
        }

        if (!is_delim) {
            break;
        }
        token_start++;
    }

    if (*token_start == '\0') {
        next_token = NULL;
        return NULL;
    }

    char *token_end = token_start;

    while (*token_end != '\0') {
        const char *d = delim;
        int is_delim = 0;

        while (*d != '\0') {
            if (*token_end == *d) {
                is_delim = 1;
                break;
            }
            d++;
        }

        if (is_delim) {
            break;
        }

        token_end++;
    }

    if (*token_end != '\0') {
        *token_end = '\0';
        next_token = token_end + 1;
    } else {
        next_token = NULL;
    }

    return token_start;
}
