#ifndef _MENU_H_
#define _MENU_H_

int MenuConfig(char *cmd ,char *desc, int (*handler)(int argc ,char *agrv[]));

int ExecuteMenu();

#endif
