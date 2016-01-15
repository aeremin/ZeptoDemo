package com.gmail.aereminmsu.zeptodemo;

import android.opengl.GLES20;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class JavaRenderer implements GLSurfaceView.Renderer {
    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        GameJNILib.initViewport(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        GameJNILib.update();
    }
}
