#pragma once
typedef int AtomType;
typedef enum { ATOM, LIST } ElemTag;//ATOM==0;ԭ��;LIST==1;�ӱ�
typedef struct GLNode {
	ElemTag tag;//�������֣���������ԭ�ӽ��ͱ����
	union //ԭ�ӽ��ͱ��������ϲ���
	{
		AtomType atom;//atom��ԭ�ӽ���ֵ��
		struct {
			struct GLNode* hp, * tp;
		}ptr;//ptr�Ǳ�����ָ����ptr.hp��ptr.tp�ֱ�ָ���ͷ�ͱ�β
	};
}*GList;