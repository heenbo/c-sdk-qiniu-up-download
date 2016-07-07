#include "io.h"
#include "resumable_io.h"
#include "rs.h"
#include "base.h"

#include <stdio.h>

int main(int argc, char * argv[])
{
	Qiniu_Client client;
	Qiniu_Mac    mac;

	char * bucketName = "test";
	char * file_path = "./local.txt";

	mac.accessKey = "Hw_2_emX0FV5fe26brBCemk3Yhdzd5l86UwfI9_n";
	mac.secretKey = "V09N6hmt3Z4vieC7Ps3g6HAyQ136cGSmAj7UtjWv";

	Qiniu_Servend_Init(-1);
	Qiniu_Client_InitNoAuth(&client, 1024);

#if 0 //upload
	Qiniu_RS_PutPolicy putPolicy;
	Qiniu_Zero(putPolicy);
	putPolicy.scope = "test";
	char * uploadtoken = Qiniu_RS_PutPolicy_Token(&putPolicy, &mac);
	
	Qiniu_Io_PutRet putRet;
	Qiniu_Error error = Qiniu_Io_PutFile(&client, &putRet, uploadtoken, "local.txt", "./local.txt", NULL);
	if (error.code != 200) 
	{
		printf("!200 ERROR\n");
	}
	else
    	{
		printf("200  OK\n");
    	}

    	Qiniu_Free(uploadtoken);
#endif

#if 1 //download
	Qiniu_RS_GetPolicy getPolicy;
	Qiniu_Zero(getPolicy);

	//char* domain = Qiniu_String_Concat2("heenbo-test", "o9mmpvxgk.bkt.clouddn.com");
	char* domain = Qiniu_String_Concat2("", "o9mmpvxgk.bkt.clouddn.com");
	printf("domain:%s\n", domain);

	char * baseUrl = Qiniu_RS_MakeBaseUrl(domain, "a.txt");
	printf("baseUrl: %s\n", baseUrl);

	char * url = Qiniu_RS_GetPolicy_MakeRequest(&getPolicy, baseUrl, &mac);
	printf("url:%s\n", url);
	
	Qiniu_Free(baseUrl);
	Qiniu_Free(url);
	Qiniu_Free(domain);





#endif

	Qiniu_Client_Cleanup(&client);
	Qiniu_Servend_Cleanup();

	return 0;
}


