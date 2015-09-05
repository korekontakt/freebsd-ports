https://github.com/torch/torch7/issues/355

--- lib/TH/generic/THTensorMath.c.orig	2015-08-19 14:44:08 UTC
+++ lib/TH/generic/THTensorMath.c
@@ -300,7 +300,7 @@ real THTensor_(minall)(THTensor *tensor)
                   if(!(value >= theMin))
                   {
                     theMin = value;
-                    if (isnan(value))
+                    if (isnan((double)value))
                       break;
                   });
   return theMin;
@@ -319,7 +319,7 @@ real THTensor_(maxall)(THTensor *tensor)
                   if(!(value <= theMax))
                   {
                     theMax = value;
-                    if (isnan(value))
+                    if (isnan((double)value))
                       break;
                   });
   return theMax;
@@ -900,7 +900,7 @@ void THTensor_(max)(THTensor *values_, T
                          {
                            theIndex = i;
                            theMax = value;
-                           if (isnan(value))
+                           if (isnan((double)value))
                              break;
                          }
                        }
@@ -937,7 +937,7 @@ void THTensor_(min)(THTensor *values_, T
                          {
                            theIndex = i;
                            theMin = value;
-                           if (isnan(value))
+                           if (isnan((double)value))
                              break;
                          }
                        }
