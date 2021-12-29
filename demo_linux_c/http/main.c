//
// Created by Administrator on 2021/8/7 0007.
//

#include "service.h"

Service server ={
        .ip="0.0.0.0",
        .port=9501,
        .backlog=1024,
        .thread_num=2,
        .ix=0,
        .InitSocket=initSocket,
        .Bind=Bind,
        .Listen=Listen,
        .Run=Run,
        .Stop=Stop,
        .onRequest=onRequest

};
void onRequest(connection *client)
{

    //printf("method:%s\r\n",client->data->method);
    //printf("uri:%s\r\n",client->data->uri);

    //printf("version:%s\r\n",client->data->version);


    //printf("Host:%s\r\n",getHeader(client,"Host"));
    //printf("name:%s\r\n",getPost(client,"name"));
    //printf("age:%s\r\n",getQuery(client,"age"));


    //路由判断
    if(strcmp("/hello",client->data->uri)==0){
        //开始进行http协议 解析处理
        http_response(client,"hello,china",0);
    }else{


        //类似于nginx 静态服务
        char *fileName = (char*)malloc(sizeof(char)*strlen(client->data->uri)+strlen("./www")+1);

        strcat(fileName,"./www");
        strcat(fileName,client->data->uri);
        printf("fileName=%s\r\n",fileName);
        int fd = open(fileName,O_RDONLY);
        struct stat statbuf;

        if(fstat(fd,&statbuf)){
            http_response(client,"文件大小获取失败",0);
            return;
        }

        char *file_content = (char*)malloc(sizeof(char)*statbuf.st_size);
        read(fd,file_content,statbuf.st_size);


        int type=0;
        char *file_type = splitStr(client->data->uri,".",NULL);
        if(strcmp("jpg",file_type)==0){
            type=1;
        }
        printf("file_type=%s\r\n",file_type);
        printf("file_size=%d\r\n",statbuf.st_size);
        http_response_file(client,file_content,type,statbuf.st_size);

        close(fd);

        free(fileName);
    }


}
int main()
{

    signal(SIGUSR1,SIG_IGN);
    signal(SIGPIPE,SIG_IGN);

    printf("http server start,pid=%d\r\n",getpid());

    server.InitSocket();
    server.Bind();
    server.Listen();
    server.Run();

    while (1){

        char cmd[125]={0};

        scanf("%s",cmd);

        if (strcmp("exit",cmd)==0){
            server.Stop();
            break;
        }
    }
    printf("http server stop\r\n");
    return 0;

}
