/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.39
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.doubango.tinyWRAP;

public class XcapStack {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected XcapStack(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(XcapStack obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      tinyWRAPJNI.delete_XcapStack(swigCPtr);
    }
    swigCPtr = 0;
  }

  public XcapStack(XcapCallback callback, String xui, String password, String xcap_root) {
    this(tinyWRAPJNI.new_XcapStack(XcapCallback.getCPtr(callback), callback, xui, password, xcap_root), true);
  }

  public boolean start() {
    return tinyWRAPJNI.XcapStack_start(swigCPtr, this);
  }

  public boolean setCredentials(String xui, String password) {
    return tinyWRAPJNI.XcapStack_setCredentials(swigCPtr, this, xui, password);
  }

  public boolean setXcapRoot(String xcap_root) {
    return tinyWRAPJNI.XcapStack_setXcapRoot(swigCPtr, this, xcap_root);
  }

  public boolean setLocalIP(String ip) {
    return tinyWRAPJNI.XcapStack_setLocalIP(swigCPtr, this, ip);
  }

  public boolean setLocalPort(long port) {
    return tinyWRAPJNI.XcapStack_setLocalPort(swigCPtr, this, port);
  }

  public boolean addHeader(String name, String value) {
    return tinyWRAPJNI.XcapStack_addHeader(swigCPtr, this, name, value);
  }

  public boolean removeHeader(String name) {
    return tinyWRAPJNI.XcapStack_removeHeader(swigCPtr, this, name);
  }

  public boolean setTimeout(long timeout) {
    return tinyWRAPJNI.XcapStack_setTimeout(swigCPtr, this, timeout);
  }

  public boolean getDocument(String url) {
    return tinyWRAPJNI.XcapStack_getDocument(swigCPtr, this, url);
  }

  public boolean getElement(String url) {
    return tinyWRAPJNI.XcapStack_getElement(swigCPtr, this, url);
  }

  public boolean getAttribute(String url) {
    return tinyWRAPJNI.XcapStack_getAttribute(swigCPtr, this, url);
  }

  public boolean deleteDocument(String url) {
    return tinyWRAPJNI.XcapStack_deleteDocument(swigCPtr, this, url);
  }

  public boolean deleteElement(String url) {
    return tinyWRAPJNI.XcapStack_deleteElement(swigCPtr, this, url);
  }

  public boolean deleteAttribute(String url) {
    return tinyWRAPJNI.XcapStack_deleteAttribute(swigCPtr, this, url);
  }

  public boolean putDocument(String url, java.nio.ByteBuffer payload, long len) {
    return tinyWRAPJNI.XcapStack_putDocument(swigCPtr, this, url, payload, len);
  }

  public boolean putElement(String url, java.nio.ByteBuffer payload, long len) {
    return tinyWRAPJNI.XcapStack_putElement(swigCPtr, this, url, payload, len);
  }

  public boolean putAttribute(String url, java.nio.ByteBuffer payload, long len) {
    return tinyWRAPJNI.XcapStack_putAttribute(swigCPtr, this, url, payload, len);
  }

  public boolean stop() {
    return tinyWRAPJNI.XcapStack_stop(swigCPtr, this);
  }

}
