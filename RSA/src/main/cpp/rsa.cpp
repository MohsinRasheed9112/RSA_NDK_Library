#include <jni.h>
#include <string>

//extern "C" JNIEXPORT jstring JNICALL
//Java_com_example_rsa_NativeLib_stringFromJNI(
//        JNIEnv* env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}

#include <jni.h>
#include <string>
//extern "C" JNIEXPORT jstring JNICALL
//Java_com_example_rsa_1ndk_1library_MainActivity_stringFromJNI(
//        JNIEnv* env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}

#include <jni.h>
#include <string>
#include <sstream>
#include "./RsaCPP/Rsa/Rsa.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_rsa_NativeLib_EncodeJNI(
        JNIEnv* env,
        jclass clazz,
        jstring textToEncode,
        jlong n,
        jlong e
){
    Rsa::RsaKey* rsaKey = new Rsa::RsaKey(Dodecahedron::Bigint(n),Dodecahedron::Bigint(0),Dodecahedron::Bigint(e));
    Rsa::Rsa* rsaC = new Rsa::Rsa();
    return env->NewStringUTF(rsaC->Encode(env->GetStringUTFChars(textToEncode,NULL),rsaKey).c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_rsa_NativeLib_DecodeJNI(
        JNIEnv* env,
        jclass clazz,
        jstring textToDecode,
        jlong n,
        jlong d
){
    Rsa::RsaKey* rsaKey = new Rsa::RsaKey(Dodecahedron::Bigint(n),Dodecahedron::Bigint(d),Dodecahedron::Bigint(0));
    Rsa::Rsa* rsaC = new Rsa::Rsa();
    return env->NewStringUTF(rsaC->Decode(env->GetStringUTFChars(textToDecode,NULL),rsaKey).c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_rsa_NativeLib_CreateKeys(
        JNIEnv* env,
        jclass clazz){
    Rsa::Rsa* rsaC = new Rsa::Rsa();
    Rsa::RsaKey* key = rsaC->CreateKeys(1);
    std::stringstream ss;
    ss << "n: " << key->n <<" d: " << key->d << " e: " << key->e;
    return env-> NewStringUTF(ss.str().c_str());
}