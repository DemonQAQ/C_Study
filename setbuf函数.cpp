#include <stdio.h>
char outbuf[BUFSIZ];//������BUFSIZ��������ڻ����������
int main(void)
{
	/* ��outbuf��stdout����������� */
	setbuf(stdout, outbuf);
	/* ��stdout�з���һЩ�ַ��� */
	puts("This is a test of buffered output.");//����stdout���л�������
	fprintf(stdout, "hello world.");
	fprintf(stdout, "test");
	fprintf(stdout, "test2");
	/*ˢ����*/
	fflush(stdout);
	/* ������outbuf�е����� */
	puts(outbuf);
	return 0;
}