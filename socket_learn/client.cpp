/*
 * =====================================================================================
 *
 *       Filename:  client.cpp
 *
 *    Description:  学习 socket 编程，客户端
 *
 *        Version:  1.0
 *        Created:  2017年06月26日 17时22分12秒
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

int main(int argc, char *argv[])
{
  init_addr();
  //if( argc != 2 ){
    //fprintf(stdout, "usage: ./client <ipaddress>\n");
    //exit(0);
  //}

  int clientfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  // bind();
  //struct sockaddr_in server;
  //memset(&server, 0, sizeof(server));
  //server.sin_family = AF_INET;
//  server.sin_addr.s_addr = htonl();
  //if (inet_pton(AF_INET, argv[1], &server.sin_addr) < 0)
  //{
    //fprintf(stderr, "inet_pton error for %s\n", argv[1]);
    //exit(0);
  //}
  //server.sin_port = htonl(6666);
  int ret = connect(clientfd, (struct sockaddr*)&g_server, sizeof(g_server));
  if (ret == -1)
  {
    fprintf(stderr, "connect socket error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
  }

  fprintf(stdout, "send msg to server: \n");
  char buff[4096] = "i love lyw.";
  int n = send(clientfd, buff, sizeof(buff), 0);
  if (n < 0)
  {
    fprintf(stderr, "send msg error: %s(errno: %d)\n", strerror(errno), errno);
    exit(0);
  }

  close(clientfd);
  exit(0);
  return 0;
}
