package com.lichao.javafilecrpt;

import java.io.File;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

/**
 * 文件加密解密
 * @author dell
 *
 */
public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    //加密
    public void mCrypt(View view){
    	String normal_path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "love.jpg";
    	String crypt_path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "love_e.jpg";
    	Cryptor.crypt(normal_path, crypt_path);
    	Log.d("lichao", "加密完成");
    	Log.d("lichao", "normal_path"+normal_path);
    }
    
    //解密
    public void mDrypt(View view){
    	String crypt_path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "love_e.jpg";
    	String decrypt_path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "love_new.jpg";
    	Cryptor.drypt(crypt_path, decrypt_path);
    	Log.d("lichao", "解密完成");
    }
}
