This test code addresses two cases in which the gcc 8.2 lto will fail to link
1) The first case is when using the lto while calling a C function from an assembly function. 
   As we call the my_main in the main.c file from the startup assembly code crt.s
   
2) The second case is when using reverse patching the gcc code related to FSF GCC bug 81968 https://gcc.gnu.org/bugzilla/show_bug.cgi?id=81968
   The first test case will pass but when adding much code to the test and using the -g option the lto will fail to link again

To run the build please perform the following in the bld.py script:

1) lines 3-5 ar windows commands (comment if use LINUX)
2) lines 9-11 are linux commands (comment if use WINDOWS)
3) change the string COMPILER_PATH to match the base path of the gcc folder
4) the test case has two options, running the bld.py without arguments or using the big_code arguments
   > bld.py 
   will build only the main.c and the crt.s and will address the c and asm file combination lto linkage
   > bld.py big_code
   will buils the main.c, crt.s and the foo.c which will address the size code lto linkage using the -g option 
4) run the bld.py from the same directory
5) keep the output folder (it should be empty at first)
