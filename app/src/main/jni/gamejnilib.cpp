#include <jni.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include "render/RectangleRenderer.h"

extern "C" {
JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_initViewport(JNIEnv * env, jobject obj,  jint width, jint height);
JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_update(JNIEnv *env, jclass type);
};

void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_initViewport(JNIEnv *env, jobject obj, jint width,
                                                         jint height) {
    glViewport(0, 0, width, height);
    glDisable(GL_CULL_FACE);
}

render::RectangleRenderer rr;

void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_update(JNIEnv *env, jclass type) {
    glClearColor(0.0f, 1.0f, 1.0, 1.0f);
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    rr.render({{{0.8, 0.8}, {0.3, 0.3}}});
}

