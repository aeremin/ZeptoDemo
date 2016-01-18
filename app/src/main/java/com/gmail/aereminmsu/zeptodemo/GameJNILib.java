package com.gmail.aereminmsu.zeptodemo;

public class GameJNILib {
    static {
        System.loadLibrary("zeptodemo");
    }

    public static native void init();

    public static native void initViewport(int width, int height);
    public static native void update();
    public static native void onTouch();

    public static native void pause();
    public static native void resume();
}
