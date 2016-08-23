LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := JavaFilecrpt
LOCAL_SRC_FILES := JavaFilecrpt.c

include $(BUILD_SHARED_LIBRARY)
