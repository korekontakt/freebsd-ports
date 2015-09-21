--- cmake/TorchExports.cmake.orig	2015-08-19 14:44:08 UTC
+++ cmake/TorchExports.cmake
@@ -1,7 +1,3 @@
-INSTALL(EXPORT TH-exports
-  DESTINATION "${Torch_INSTALL_CMAKE_SUBDIR}"
-  FILE "TorchExports.cmake")
-
 CONFIGURE_FILE("cmake/TorchConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/cmake-exports/TorchConfig.cmake" @ONLY)
 CONFIGURE_FILE("cmake/TorchWrap.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/cmake-exports/TorchWrap.cmake" @ONLY)
 
