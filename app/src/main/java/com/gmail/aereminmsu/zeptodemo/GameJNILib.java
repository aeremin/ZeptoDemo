package com.gmail.aereminmsu.zeptodemo;

public class GameJNILib {
    static {
        System.loadLibrary("zeptodemo");
    }

    public static native void initViewport(int width, int height);
    public static native void update();
}
