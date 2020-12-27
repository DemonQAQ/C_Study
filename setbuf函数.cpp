#include <stdio.h>
char outbuf[BUFSIZ];//必须是BUFSIZ，否则存在缓冲溢出可能
int main(void)
{
	/* 将outbuf与stdout输出流相连接 */
	setbuf(stdout, outbuf);
	/* 向stdout中放入一些字符串 */
	puts("This is a test of buffered output.");//体现stdout的行缓冲性质
	fprintf(stdout, "hello world.");
	fprintf(stdout, "test");
	fprintf(stdout, "test2");
	/*刷新流*/
	fflush(stdout);
	/* 以下是outbuf中的内容 */
	puts(outbuf);
	return 0;
}