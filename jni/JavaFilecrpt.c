#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "com_lichao_javafilecrpt_Cryptor.h"

char password[] ="lichao3140";
//加密
JNIEXPORT void JNICALL Java_com_lichao_javafilecrpt_Cryptor_crypt
  (JNIEnv *env, jclass jcls, jstring normal_path_jstr, jstring crypt_paht_jstr){
	//jstring 转成 char*
	const char* normal_path = (*env)->GetStringUTFChars(env, normal_path_jstr, JNI_FALSE);
	const char* crypt_path = (*env)->GetStringUTFChars(env, crypt_paht_jstr, JNI_FALSE);

	//打开文件
	FILE *normal_fp = fopen(normal_path, "rb");
	FILE *crypt_fp = fopen(crypt_path, "wb");
	//一次读取一个字符
	int ch;
	int i = 0;//循环使用密码中的字母进行异或运算
	int pwd_len = strlen(password);//密码的长度
	while ((ch = fgetc(normal_fp)) != EOF){
			//写入（异或运算）
			fputc(ch ^ password[i % pwd_len], crypt_fp);
			i++;
		}
		//关闭
		fclose(normal_fp);
		fclose(crypt_fp);
}

//解密
JNIEXPORT void JNICALL Java_com_lichao_javafilecrpt_Cryptor_drypt
  (JNIEnv *env, jclass jcls, jstring crypt_path_jstr, jstring decrypt_path_jstr){
	const char* crypt_path = (*env)->GetStringUTFChars(env, crypt_path_jstr, JNI_FALSE);
	const char* decrypt_path = (*env)->GetStringUTFChars(env, decrypt_path_jstr, JNI_FALSE);

	//打开文件
	FILE *normal_fp = fopen(crypt_path, "rb");
	FILE *crypt_fp = fopen(decrypt_path, "wb");
	//一次读取一个字符
	int ch;
	int i = 0;//循环使用密码中的字母进行异或运算
	int pwd_len = strlen(password);//密码的长度
	while ((ch = fgetc(normal_fp)) != EOF){
		//写入（异或运算）
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	//关闭
	fclose(normal_fp);
	fclose(crypt_fp);
}
