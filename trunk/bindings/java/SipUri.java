/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.39
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.doubango.tinyWRAP;

public class SipUri {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected SipUri(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(SipUri obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      tinyWRAPJNI.delete_SipUri(swigCPtr);
    }
    swigCPtr = 0;
  }

  public SipUri(String arg0) {
    this(tinyWRAPJNI.new_SipUri(arg0), true);
  }

  public static boolean isValid(String arg0) {
    return tinyWRAPJNI.SipUri_isValid__SWIG_0(arg0);
  }

  public boolean isValid() {
    return tinyWRAPJNI.SipUri_isValid__SWIG_1(swigCPtr, this);
  }

}
