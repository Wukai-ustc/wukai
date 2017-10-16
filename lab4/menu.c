#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

int help();
int quit();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

typedef struct DataNode
{
    tLinkTableNode *pNext;
    char* cmd;
    char* desc;
    int   (*handler)();
    struct DataNode *next;

}tDataNode;

tDataNode *FindCmd(tLinkTable *head, char *cmd)
{
    tDataNode* pNode=(tDataNode*)GetLinkTableHead(head);
     while(pNode !=NULL)
    {
    if(!strcmp(pNode->cmd,cmd))
    {
        return pNode;
    }
    pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return NULL;
}   

int ShowAllCmd(tLinkTable* head)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode !=NULL)
    {
    printf("%s - %s\n",pNode->cmd,pNode->desc);
    pNode =(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return 0;
}  

int InitMenuData(tLinkTable ** ppLinkTable)
{
    *ppLinkTable=CreateLinkTable();
    tDataNode* pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="help";
    pNode->desc="help command:";
    pNode->handler=help;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="version";
    pNode->desc="menu program v1.1 beta";
    pNode->handler=NULL;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="quit";
    pNode->desc="quit this software";
    pNode->handler=quit;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    return 0;

}

tLinkTable* head=NULL;

int main()
{
    InitMenuData(&head);
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Please Input Command >");
        scanf("%s",cmd);
        tDataNode *p = FindCmd(head,cmd);
        if(p == NULL)
        {
             printf("wrong cmd!\n");
             continue;
         }
         printf("%s - %s\n",p->cmd,p->desc);
         if(p -> handler != NULL)
        {
            p -> handler();
        }
     }
}

int help()
{
    printf("Menu List:\n");
    ShowAllCmd(head);
    return 0;
}

int quit()
{
    exit(0);
    return 0;
}


