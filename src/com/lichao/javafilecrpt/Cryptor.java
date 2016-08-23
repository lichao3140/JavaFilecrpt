package com.lichao.javafilecrpt;

public class Cryptor {

	/**
	 * 加密
	 * @param path
	 */
	public native static void crypt(String normal_path, String crypt_path);
	
	/**
	 * 解密
	 * @param path
	 */
	public native static void drypt(String crypt_path, String decrypt_path);
	
	static{
		System.loadLibrary("JavaFilecrpt");
	}
}
