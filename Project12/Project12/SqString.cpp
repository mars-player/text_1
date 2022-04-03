#include "标头.h"
#include <stdio.h>
void Assign(SqString& s, char str[]) //串赋值运算算法
{
	int i = 0;
	while (str[i] != '\0')
	{
		s.data[i] = str[i];
		i++;
	}
	s.length = i;
}

void DestroyStr(SqString s) //销毁串运算
{}

void StrCopy(SqString& s, SqString t) //串复制运算
{
	int i;
	for (i = 0; i < t.length; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
}

int StrLength(SqString s) //求串长运算
{
	return(s.length);
}

int StrEqual(SqString s, SqString t) //判断串相等元素
{
	int i = 0;
	if (s.length != t.length)
		return 0;                    //串长不同时返回0
	else
	{
		for (i = 0; i < s.length; i++)
			if (s.data[i] != t.data[i]) //有一个对应字符不同时返回0
				return 0;
		return 1;
	}
}

SqString Concat(SqString s, SqString t) //串连接运算
{
	SqString r;
	int i, j;
	for (i = 0; i < s.length; i++)  //将s复制到r
		r.data[i] = s.data[i];
	for (j = 0; j < t.length; j++)  //将t复制到r
		r.data[s.length + j] = t.data[j];
	r.length = i + j; 
	return r;                       //复制r
}

SqString SubStr(SqString s, int i, int j) //求子串运算
{
	SqString t;
	int k;
	if (i < 1 || i > s.length || j < 1 || i + j > s.length + 1)
		t.length = 0;                     //参数错误时返回空串
	else
	{
		for (k = i - 1; k < i + j - 1; k++)
			t.data[k - i + 1] = s.data[k];
		t.length = j;
	}
	return t;
}
 
int Index(SqString s, SqString t) //查找子串位置运算算法
{
	int i = 0, j = 0;  //i和j分别扫描主串s和子串t
	while (i < s.length && j < t.length) //两个串都没有扫描完
	{
		if (s.data[i] == t.data[j])  //对应字符相同时，继续比较下一对字符
		{
			i++;
			j++;
		}
		else   //否则，主串指针回溯重新开始下一次匹配
		{
			i = i - j + 1;  //i回退到原i的下一个位置
			j = 0;          //j从t的第一个字符开始
		}
	}
	if (j >= t.length)  //t的字符扫描完，表示t是s的子串
		return i - t.length + 1;  //返回t的第一个字符在s中的位置
	else
		return 0;  //返回0
}

int InsStr(SqString& s, int i, SqString t) //子串插入运算
{
	int j;
	if (i < 1 || i > s.length + 1)
		return 0;   //位置参数错误返回0
	else
	{
		for (j = s.length - 1; j >= i - 1; j--) //将s.data[i-1]..s.length-1]
			s.data[j + t.length] = s.data[j];  //后移t.length个位置
	 	for (j = 0; j < t.length; j++) //插入子串t
			s.data[i + j - 1] = t.data[j]; 
		s.length = s.length + t.length; //修改s串长度
		return 1;  //成功插入返回1
	}
}

int DelStr(SqString& s, int i, int j) //子串删除运算算法
{
	int k;
	if (i < 1 || i > s.length || j < 1 || i + j > s.length + 1)
		return 0;  //位置参数错误
	else
	{
		for (k = i + j - 1; k < s.length; k++) //将s的第i+j位置之后的字符前移j位
			s.data[k - j] = s.data[k];
		s.length = s.length - j; //修改s的长度
		return 1; //成功删除返回1
	}
}

SqString RepStrAll(SqString s, SqString s1, SqString s2) //子串替换运算
{
	int i;
	i = Index(s, s1);
	while (i > 0)
	{
		DelStr(s, i, s1.length); //从s中删除子串s1
		InsStr(s, i, s2); //在s中插入子串s2
		i = Index(s, s1);
	}
	return s;
}

void DispStr(SqString s)
{
	int i;
	for (i = 0; i < s.length; i++)
		printf("%c", s.data[i]);
	printf("\n");
}

int Strcmp(SqString s, SqString t) //以字典顺序比较两个英文字母串s和t的大小，两个串均以顺序串存储
{
	int i, comlen;
	if (s.length < t.length)
		comlen = s.length;  //求s和t的共同长度
	else comlen = t.length;
	for (i = 0; i < comlen; i++)  //在共同长度内逐个字符比较
		if (s.data[i] > t.data[i]
		    return 1;
		else if (s.data[i] < t.data[i]
	            return -1;
	if (s.length == t.length)  //s == t
	        return 0;
	else if(s.length > t.length)  //s > t
		return 1;
	else return -1;  //s < t
}
			 
int Count(SqString s, SqString t){ //求串t在串s中出现的次数
	int num = 0, i, j, k;      //i和j分别扫描主串s和子串t
	i = 0;
	while (i <= s.length - t.length)
	{
		for (k = i, j = 0; j < t.length && s.data[k] == t.data[j]; k++, j++);
		if (j == t.length)    //j等于子串t的长度
		{
			num++;        //找到一个子串
			i += t.length; //i跳过t.length个字符
		}
		else i++;             //i后移一个字符
	}
	return(num);
}
			 
			 
