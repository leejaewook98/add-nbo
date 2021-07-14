#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) // 명령줄 인수를 받는 main() 함수
{
    if(argc <= 2){
        printf("syntax : add-nbo <file1> <file2> \n");
        printf("sample : add-nbo a.bin c.bin \n");
        return 0;
    }
    uint32_t n1, n2, a1, a2;
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");
    fread(&n1, sizeof(uint32_t), 1, fp1);
    fread(&n2, sizeof(uint32_t), 1, fp2);
    //fread:한번에 일정한 크기의 데이터를 파일에 읽거나 쓰기 위한 입출력 함수
    a1 = ntohl(n1);
    a2 = ntohl(n2);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a1, a1, a2, a2, a1+a2, a1+a2);
    fclose(fp1);
    fclose(fp2);
}



