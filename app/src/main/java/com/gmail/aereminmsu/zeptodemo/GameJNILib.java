package com.gmail.aereminmsu.zeptodemo;

public class GameJNILib {
    static {
        System.loadLibrary("zeptodemo");
    }

    public static native void init(int width, int height);
}
