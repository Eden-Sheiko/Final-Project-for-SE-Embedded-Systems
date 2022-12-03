

#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUF_SIZE 60
#define IP_ADDRESS "192.168.1.2"
#define FLAG_ZERO 0
#define EQUAL_ZERO 0
#define TRUE 1
#define FALSE 0
#define PORT 7
#define LEN 30
#define SLEEP_TIME 3
#define ERROR -1
#define MSG_BUFFER 256

static unsigned int test_id = 0;

typedef struct data_packet {
    uint32_t Test_id;
    uint8_t Peripheral;
    uint8_t Iterations;
    uint8_t length;
    char msg[MSG_BUFFER];
} data_packet_t;

typedef struct res {
    uint32_t Test_id;
    uint8_t Test_result;
} res_t;


void udp_menu(uint8_t *per, uint8_t *it, uint8_t *leng, char *ms, uint32_t *test);

void print_menu();

void print_sub_menu();

int main(int argc, char *argv[]) {
    while(1) {


        /*************************************** Vars ***************************************************/
        struct sockaddr_in dest; // Holds Destination socket (IP+PORT)
        int socket_fd;           // Holds socket file descriptor
        unsigned int ssize;      // Holds size of dest
        struct hostent *hostptr; // Holds host information
        char buf[BUF_SIZE + 1];  // Used for writing/ Reading from buffer
        int retVal = EQUAL_ZERO;          // Holds return Value for recvfrom() / sendto()
        char *cRetVal = NULL;    // Holds return Value for fgets()
        data_packet_t data_packet;
        res_t data_packet_answer;
        udp_menu(&data_packet.Peripheral, &data_packet.Iterations, &data_packet.length, data_packet.msg,
                 &data_packet.Test_id);


        /************************************* Initialization ******************************************/

        int i_size_of_struct = sizeof(data_packet);
        int i_size_of_new_struct = sizeof(data_packet_answer);
        char buffer_to_send[i_size_of_struct];

        char new_buffer[i_size_of_new_struct];

        memset(buffer_to_send, EQUAL_ZERO, i_size_of_struct);
        memset(new_buffer, EQUAL_ZERO, i_size_of_new_struct);

        memcpy(buffer_to_send, &data_packet, i_size_of_struct);


        /************************************* Initialization ******************************************/

        socket_fd = socket(AF_INET, SOCK_DGRAM, FLAG_ZERO); // Create socket
        if (socket_fd == ERROR) {
            perror("Create socket");
            exit(TRUE);
        } // Validate the socket

        bzero((char *) &dest, sizeof(dest));           // Clearing the struct
        dest.sin_family = (short) AF_INET;             // Setting IPv4
        dest.sin_port = htons(PORT);                  // Setting port
        dest.sin_addr.s_addr = inet_addr(IP_ADDRESS); // Setting IP address

        ssize = sizeof(dest); // Get dest size

        /************************************* Code *****************************************************/



            retVal = sendto(socket_fd, &buffer_to_send, i_size_of_struct, FLAG_ZERO, (struct sockaddr *) &dest,
                            ssize); // Send Ping
            if (retVal < 0)
                break;

            retVal = recvfrom(socket_fd, &new_buffer, i_size_of_new_struct, FLAG_ZERO, (struct sockaddr *) &dest,
                              &ssize); // Get answer
            if (retVal < 0)
                break;


            printf("------------------------------------\n");
            printf("             massage sent:      \n");
            printf("Test_id : %d\n", data_packet.Test_id);
            printf("Peripheral : %d\n", data_packet.Peripheral);
            printf("length : %d\n", data_packet.length);
            printf("Iterations : %d\n", data_packet.Iterations);
            printf("massage sent : %s\n", data_packet.msg);
            printf("------------------------------------\n");
            printf("\n");

            data_packet_answer.Test_id = *(uint32_t *) (new_buffer + EQUAL_ZERO);
            data_packet_answer.Test_result = *(uint8_t *) (new_buffer + 4);

            printf("------------------------------------\n");
            printf("              massage received:      \n");
            printf("Test id : %d\n", data_packet_answer.Test_id);
            printf("Test result (1 = passed 0 = failed)  : %d\n", data_packet_answer.Test_result);
            printf("------------------------------------\n");
            printf("\n");

            sleep(3);

    }

}

void udp_menu(uint8_t *per, uint8_t *it, uint8_t *leng, char *ms, uint32_t *test) {
    char c;
    uint8_t peripheral = EQUAL_ZERO;
    uint8_t iter = EQUAL_ZERO;
    char msg[MSG_BUFFER] = {EQUAL_ZERO};
    char *b = msg; // new
    size_t bufsize = MSG_BUFFER; // new
    size_t tmp = EQUAL_ZERO; // new
    int k; // new
    uint8_t len = EQUAL_ZERO;


   print_menu();

    while (1) {
        fflush(stdin);
        fflush(stdout);
        scanf(" %c", &c);
        print_sub_menu();
        switch (c) {
            case 'a':
                printf("please enter an Peripheral \n");
                scanf("%hhu", &peripheral);
                *per = peripheral;
                break;
            case 'b':
                printf("please enter number of Iterations \n");
                scanf("%hhu", &iter);
                *it = iter;
                break;
            case 'c':
                printf("please enter a string to send \n");
                while ((k = getchar()) != '\n' && k != EOF);
                tmp = getline(&b,&bufsize,stdin);

                strcpy(ms, b);
                len = tmp+1;
                *leng = len;
                break;
            case 'd':
                printf("sending.. \n");
                ++test_id;
                *test = test_id;
                return;
            case 'e':
                exit(EQUAL_ZERO);
            default:
                printf("Try again\n");
        }
    }
}

void print_menu(){
    printf("***********************************\n");
    printf("************* MENU **************\n");
    printf("        Enter your packet structure  \n");
    printf("***********************************\n");
    printf("\ta- Peripheral to be tested (1 –Timer, 2 – UART, SPI – 4, I2C – 8, ADC – 16)\n");
    printf("\tb- number of Iterations \n");
    printf("\tc- massage to be sent \n");
    printf("\td- send!!! \n");
    printf("\te- Exit program\n");
    printf("***********************************\n\n\n");
}

void print_sub_menu(){
    printf("\ta- Peripheral to be tested (1 –Timer, 2 – UART, SPI – 4, I2C – 8, ADC – 16)\n");
    printf("\tb- number of Iterations \n");
    printf("\tc- massage to be sent \n");
    printf("\td- send!!! \n");
    printf("\te- Exit program\n");
}
