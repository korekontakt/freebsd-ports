https://github.com/torch/torch7/issues/355

--- generic/THTensorMath.c.orig	2015-08-19 14:44:08 UTC
+++ generic/THTensorMath.c
@@ -4,6 +4,11 @@
 
 #define TH_OMP_OVERHEAD_THRESHOLD 100000
 
+#if !defined(TH_REAL_IS_FLOAT) && !defined(TH_REAL_IS_DOUBLE)
+#undef isnan
+#define isnan(x) 0
+#endif
+
 void THTensor_(fill)(THTensor *r_, real value)
 {
   TH_TENSOR_APPLY(real, r_, 
