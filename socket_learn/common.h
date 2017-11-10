/*
 * =====================================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  学习 socket 编程，头文件
 *
 *        Version:  1.0
 *        Created:  2017年06月26日 18时23分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  niel (), nie7ng@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <arpa/inet.h>

struct sockaddr_in g_server;

void init_addr ()
{
  memset(&g_server, 0, sizeof(g_server));
  g_server.sin_family = AF_INET;
//  g_server.sin_addr.s_addr = htonl(INADDR_ANY);
  g_server.sin_addr.s_addr = inet_addr("127.0.0.1");
  g_server.sin_port = htons(6666);
}
