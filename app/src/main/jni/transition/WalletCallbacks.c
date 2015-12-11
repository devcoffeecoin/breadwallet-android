//
// Created by Mihail Gutan on 12/4/15.
//
#include "WalletCallbacks.h"

JNIEnv *globalEnv;

void Java_com_breadwallet_wallet_BRTestWallet_setCallbacks(JNIEnv *env,
                                                           jobject thiz,
                                                           jbyteArray walletBuff) {
    globalEnv = env;
    jbyte *byteWallet= (*env)->GetByteArrayElements(env, walletBuff, 0);
    BRWallet *wallet = byteWallet;
    //set the Wallet callbacks
    BRWalletSetCallbacks(wallet, NULL, &balanceChanged, &txAdded, &txUpdated, &txDeleted);

    int a = 10;
    int balance = 480000;
    balanceChanged(a, balance);
}

void balanceChanged(void *info, uint64_t balance) {
    //create class
    jclass clazz = (*globalEnv)->FindClass(globalEnv, "com/breadwallet/wallet/BRTestWallet");
    jobject entity = (*globalEnv)->AllocObject(globalEnv, clazz);
    jmethodID mid = (*globalEnv)->GetMethodID(globalEnv, clazz, "onBalanceChanged", "(J)V");
    //call java methods
    (*globalEnv)->CallVoidMethod(globalEnv, entity, mid, balance);
}

void txAdded(void *info, BRTransaction *tx) {
    //create class
    jclass clazz = (*globalEnv)->FindClass(globalEnv, "com/breadwallet/wallet/BRTestWallet");
    jobject entity = (*globalEnv)->AllocObject(globalEnv, clazz);
    jmethodID mid = (*globalEnv)->GetMethodID(globalEnv, clazz, "onTxAdded", "([B)V");
    //call java methods
//    (*globalEnv)->CallVoidMethod(globalEnv, entity, mid, balance);
}

void txUpdated(void *info, const UInt256 txHashes[], size_t count, uint32_t blockHeight,
               uint32_t timestamp) {
    //create class
    jclass clazz = (*globalEnv)->FindClass(globalEnv, "com/breadwallet/wallet/BRTestWallet");
    jobject entity = (*globalEnv)->AllocObject(globalEnv, clazz);
    jmethodID mid = (*globalEnv)->GetMethodID(globalEnv, clazz, "onTxUpdated", "([B)V");
    //call java methods
//    (*globalEnv)->CallVoidMethod(globalEnv, entity, mid, balance);

}

void txDeleted(void *info, UInt256 txHash) {
    //create class
    jclass clazz = (*globalEnv)->FindClass(globalEnv, "com/breadwallet/wallet/BRTestWallet");
    jobject entity = (*globalEnv)->AllocObject(globalEnv, clazz);
    jmethodID mid = (*globalEnv)->GetMethodID(globalEnv, clazz, "onTxDeleted", "([B)V");
    //call java methods
//    (*globalEnv)->CallVoidMethod(globalEnv, entity, mid, balance);

}
