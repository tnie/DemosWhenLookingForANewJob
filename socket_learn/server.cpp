/*
 * =====================================================================================
 *
 *       Filename:  server.cpp
 *
 *    Description:  学习 socket 编程，服务端
 *
 *        Version:  1.0
 *        Created:  2017年06月26日 17时14分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  niel (), nie7ng@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "common.h"

extern struct sockaddr_in g_server;

int main(void)
{
  init_addr();
  int listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (listenfd == -1)
  {
    fprintf(stderr, "create socket error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
  }

  int ret = bind(listenfd, (struct sockaddr*)&g_server, sizeof(g_server));
  if (ret == -1)
  {
    fprintf(stderr, "bind socket error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
  }

  ret = listen(listenfd, 10);
  if (ret == -1)
  {
    fprintf(stderr, "listen socket error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
  }

  fprintf(stdout, "=========waiting for client's request=====\n");
  while (1)
  {
    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    socklen_t addrlen = sizeof(client);
    int connfd = accept(listenfd, (struct sockaddr*)&client, &addrlen );
    if (connfd == -1)
    {
      fprintf(stderr, "accept socket error: %s(errno: %d)\n", strerror(errno), errno);
      continue;
    }
    // 读写
    const unsigned MAXLINE = 4096;
    char buff[MAXLINE];
    int n = recv(connfd, buff, MAXLINE -1, 0);
    buff[n] = 0;
    fprintf(stdout, "recv msg from client: %s\n", buff);
    close(connfd);
  }
  close(listenfd);
  return 0;
}
