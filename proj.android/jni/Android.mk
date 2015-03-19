LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := cri_ware_cocos2dx
LOCAL_SRC_FILES := ../../adx2/libs/android/armeabi-v7a/libcri_ware_android_LE.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

FILE_LIST := $(wildcard $(LOCAL_PATH)/../../Classes/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Draw/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Blend/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Light/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Particle/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Ripple/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Ripple/Base/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Ripple/Support/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Ripple/Util/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Wave/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/Character/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/Character/Enemy/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/Character/Player/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/Character/SeaFireFly/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/Stage/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Direction/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Main/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Result/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Result/Animation/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Result/Layer/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Result/Support/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/StageSelect/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Sub/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Title/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Sound/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Sound/BGM/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Sound/SE/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Util/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Util/Animation/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Util/Collision/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Util/Creater/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Util/FileIO/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Util/Release/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Util/Scene/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Util/Sound/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/System/*.cpp)

LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Draw
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Draw/Effect
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Blend
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Light
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Particle
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Ripple
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Ripple/Base
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Ripple/Support
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Ripple/Util
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Draw/Effect/Wave
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/Character
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/Character/Enemy
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/Character/Player
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/Character/SeaFireFly
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/Stage
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Direction
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Main
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Result
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Result/Animation
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Result/Layer
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Result/Support
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/StageSelect
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Sub
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Title
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Sound
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Sound/BGM
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Sound/SE
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Util
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Util/Collision
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Util/FileIO
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Util/Release
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Util/Scene
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/System
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../adx2/include/android

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static

# LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static
# LOCAL_WHOLE_STATIC_LIBRARIES += spine_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocostudio_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

LOCAL_SHARED_LIBRARIES := libcri_ware_cocos2dx

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,audio/android)

# $(call import-module,Box2D)
# $(call import-module,editor-support/cocosbuilder)
# $(call import-module,editor-support/spine)
# $(call import-module,editor-support/cocostudio)
# $(call import-module,network)
# $(call import-module,extensions)
