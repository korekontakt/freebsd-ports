--- env.lua.orig	2015-09-07 16:23:57 UTC
+++ env.lua
@@ -1,3 +1,4 @@
+pcall(require,'pl.compat') -- package.searchpath
 local ffi = require 'ffi'
 
 local sundown = {}
