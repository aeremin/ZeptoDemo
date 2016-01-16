#pragma once

#include <string>
#include <android/log.h>

#define  LOG_TAG    "ZeptoDemo"

inline void LOGI(const std::string& msg) {
    __android_log_print(ANDROID_LOG_INFO,LOG_TAG, msg.c_str());
}

inline void LOGE(const std::string& msg) {
    __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, msg.c_str());
}
