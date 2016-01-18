#include <jni.h>

#include <memory>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include "engine/Game.h"

#include "Logging.h"

extern "C" {
JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_init(JNIEnv *env, jclass type);
JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_initViewport(JNIEnv * env, jobject obj,  jint width, jint height);
JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_update(JNIEnv *env, jclass type);
JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_onTouch(JNIEnv *env, jclass type);

JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_pause(JNIEnv *env, jclass type);
JNIEXPORT void JNICALL Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_resume(JNIEnv *env, jclass type);
};

namespace {
std::unique_ptr<engine::Game> game;
}

void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_init(JNIEnv *env, jclass type) {
    LOGI("init");
    game.reset(new engine::Game);
}

void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_initViewport(JNIEnv *env, jobject obj, jint width,
                                                         jint height) {
    LOGI("initViewport");
    game->initViewport(width, height);
}

void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_update(JNIEnv *env, jclass type) {
    game->update();
}

void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_onTouch(JNIEnv *env, jclass type) {
    game->onTouch();
}

void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_pause(JNIEnv *env, jclass type) {
    LOGI("pause");
    if (game)
        game->pause();
}

void Java_com_gmail_aereminmsu_zeptodemo_GameJNILib_resume(JNIEnv *env, jclass type) {
    LOGI("resume");
    if (game)
        game->resume();
}


