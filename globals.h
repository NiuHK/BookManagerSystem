#pragma once
#ifndef globals_H
#define globals_H
#include"Struct.h"
extern int numBooks;//���ĵ�����
extern User currentUser;// ȫ�ֱ���,��ǰ�û�
extern Book* books;//ͼ��ݽṹ������ͷָ��
extern string DATA_BASE_PATH;//ͼ��ݵ�ַ
extern string BOAED_PATH;//�����ַ
extern int  borrowedBooks[100];//���ĵ�id
extern int bookNumber;//��������	����100����
//library������Ϊ0
#endif 