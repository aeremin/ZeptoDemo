#include <jni.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include "engine/Game.h"

extern "C" {
JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_initViewport(JNIEnv * env, jobject obj,  jint width, jint height);
JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_update(JNIEnv *env, jclass type);
JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_onTouch(JNIEnv *env, jclass type);
};

namespace {
engine::Game game;
}

void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_initViewport(JNIEnv *env, jobject obj, jint width,
                                                         jint height) {
    game.initViewport(width, height);
}


void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_update(JNIEnv *env, jclass type) {
    game.update();
}

void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_onTouch(JNIEnv *env, jclass type) {
    game.onTouch();
}


