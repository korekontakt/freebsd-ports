--- THGeneral.c.orig	2015-08-19 14:44:08 UTC
+++ THGeneral.c
@@ -5,8 +5,11 @@
 #define __thread
 #endif
 
-#if (defined(__unix) || defined(_WIN32))
+/* malloc_usable_size() is often N/A on non-GNU systems */
+#if (defined(__GLIBC__) || defined(_WIN32))
 #include <malloc.h>
+#elif defined(__FreeBSD__)
+#include <malloc_np.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
 #endif
@@ -123,7 +126,7 @@ void THSetGCHandler( void (*torchGCFunct
 }
 
 static long getAllocSize(void *ptr) {
-#if defined(__unix)
+#if defined(__GLIBC__) || defined(__FreeBSD__)
   return malloc_usable_size(ptr);
 #elif defined(__APPLE__)
   return malloc_size(ptr);
