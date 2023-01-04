package com.example.rsa;

public class NativeLib {

    // Used to load the 'rsa' library on application startup.
    static {
        System.loadLibrary("rsa");
    }

    /**
     * A native method that is implemented by the 'rsa' native library,
     * which is packaged with this application.
     */
    public static native String EncodeJNI(String in, long n, long e);
    public static native String DecodeJNI(String in,long n, long d);
    public static native String CreateKeys();
}