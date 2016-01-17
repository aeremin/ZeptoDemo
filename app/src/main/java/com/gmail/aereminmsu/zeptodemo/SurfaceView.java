package com.gmail.aereminmsu.zeptodemo;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

public class SurfaceView extends GLSurfaceView{
    public SurfaceView(Context context) {
        super(context);
    }

    @Override
    public boolean onTouchEvent(MotionEvent e) {
        GameJNILib.onTouch();
        return true;
    }
}
