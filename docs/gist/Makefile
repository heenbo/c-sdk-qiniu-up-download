CLIENT_SOURCE_FILES=\
	../../b64/urlsafe_b64.c\
	../../cJSON/cJSON.c\
	../../qiniu/conf.c\
	../../qiniu/base.c\
	../../qiniu/base_io.c\
	../../qiniu/http.c\
	../../qiniu/auth_mac.c\
	../../qiniu/rs.c\
	../../qiniu/io.c\
	../../qiniu/resumable_io.c\
	client.c\

SERVER_SOURCE_FILES=\
	../../b64/urlsafe_b64.c\
	../../cJSON/cJSON.c\
	../../qiniu/conf.c\
	../../qiniu/base.c\
	../../qiniu/base_io.c\
	../../qiniu/http.c\
	../../qiniu/auth_mac.c\
	../../qiniu/rs.c\
	../../qiniu/io.c\
	server.c\

DEMO_SOURCE_FILES=\
	../../b64/urlsafe_b64.c\
	../../cJSON/cJSON.c\
	../../qiniu/conf.c\
	../../qiniu/base.c\
	../../qiniu/base_io.c\
	../../qiniu/http.c\
	../../qiniu/auth_mac.c\
	../../qiniu/rs.c\
	../../qiniu/io.c\
	demo.c\

MAIN_SOURCE_FILES=\
	../../b64/urlsafe_b64.c\
	../../cJSON/cJSON.c\
	../../qiniu/conf.c\
	../../qiniu/base.c\
	../../qiniu/base_io.c\
	../../qiniu/http.c\
	../../qiniu/auth_mac.c\
	../../qiniu/rs.c\
	../../qiniu/io.c\
	main.c\

all: main
#all: client server demo main
	@echo "OK"

client: $(CLIENT_SOURCE_FILES)
	gcc $^ -o qiniuclient.exe -lcurl -lssl -lcrypto -lm

server: $(SERVER_SOURCE_FILES)
	gcc $^ -o qiniuserver.exe -lcurl -lssl -lcrypto -lm

demo: $(DEMO_SOURCE_FILES)
	gcc $^ -o demo.exe -lcurl -lssl -lcrypto -lm -I ../../qiniu/

main: $(MAIN_SOURCE_FILES)
	gcc $^ -o main.exe -lcurl -lssl -lcrypto -lm -I ../../qiniu/

install: all
	@echo

clean:
	rm -f *.exe

test:
	@echo

