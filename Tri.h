struct _TRI {                                                                                                                          
    char* name;
    void(*Free)(struct TRI*);
    void (*sort)(int tab[], int sizeOfTab);
} TRI;

