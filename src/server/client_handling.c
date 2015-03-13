/*
** client_handling.c for JEFFTP in /home/ganesha/projets/PSU_2014_myftp
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Tue Mar 10 16:08:42 2015 Ambroise Coutarel
** Last update Fri Mar 13 17:24:52 2015 Ambroise Coutarel
*/

#include "../../include/jefftp.h"

void	subinit(t_command *cmd, char *name,
		int (*func)(char **, t_client *, t_server *))
{
  cmd->ftp_command = strdup(name);
  cmd->func = func;
}

void	init_commands(t_command commands[16])
{
  subinit(&(commands[0]), "user", &user);
  subinit(&(commands[1]), "pass", &pass);
  subinit(&(commands[2]), "cwd", &cwd);
  subinit(&(commands[3]), "cdup", &cdup);
  subinit(&(commands[4]), "quit", &quit);
  subinit(&(commands[5]), "retr", &retr);
  subinit(&(commands[6]), "stor", &stor);
  subinit(&(commands[7]), "dele", &dele);
  subinit(&(commands[8]), "pwd", &pwd);
  subinit(&(commands[9]), "list", &list);
  subinit(&(commands[10]), "help", &help);
  subinit(&(commands[11]), "noop", &noop);
  subinit(&(commands[12]), "ls", &list);
  subinit(&(commands[13]), "cd", &cwd);
  subinit(&(commands[14]), "get", &retr);
  subinit(&(commands[15]), "put", &stor);
}

void	init_server(t_server *server)
{
  server->root = getcwd(NULL, 0);
  server->sys_cwd = getcwd(NULL, 0);
  server->ftp_cwd = strdup("/root");
}
