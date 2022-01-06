#include "pipe_networking.h"

int main() {

	int to_client;
	int from_client;

	to_client = server_setup();

	while(1) {
		from_client = server_connect(to_client);
		int f;
		f = fork();
		if(f) {
			close(from_client);
		}
    else {
			int r = 0;
			while(1) {
        char buffer[512] = {'\0'};
        read(from_client, buffer, sizeof(buffer));
        for (int i = 0; i < strlen(buffer); i++){
          if (buffer[i] == 'a' | buffer[i] == 'i'){
            buffer[i] = 'l';
          }
          if (buffer[i] == 'e' | buffer[i] == 'u'){
            buffer[i] = 'n';
          }
          if (buffer[i] == 'u'){
            buffer[i] = 'z';
          }
        }
        write(from_client, buffer, strlen(buffer));
			}
		}
	}
}
