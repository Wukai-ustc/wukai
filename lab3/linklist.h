/*data struct and its operations*/
typedef struct DataNode
{
	char* cmd;
	char* desc;
	int (*handler)();
	struct DataNode *next;
}tDataNode;

/*find a cmd in th linklist and return the datanode*/
tDataNode* FindCmd(tDataNode *head,char *cmd);

/*show all cmd in list*/
int ShowAllCmd(tDataNode *head);




