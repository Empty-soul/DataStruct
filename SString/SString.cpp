#include"SString.h"

int Index_BF(SString S, SString T, int pos)
{//����ģʽT������S�е�pos���ַ���ʼ��һ�γ��ֵ�λ�á��������ڣ��򷵻�ֵΪ0
	//���У�T�ǿգ�1<=pos<=S.length
	int i = pos; int j = 1;	//��ʼ��
	while (i <= S.length && j <= T.length)//��������δ�Ƚϴ�β
	{
		if (S.ch[i] == T.ch[j]) { ++i; ++j; }	//�����ȽϺ���ַ�
		else { i = i - j + 2; j = 1; }	//ָ��������¿�ʼƥ��
	}
	if (j > T.length) return i - T.length;//ƥ��ɹ�
	else return 0;	//ƥ��ʧ��
}
