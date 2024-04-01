#undef TARGET_ROSCO
#define TARGET_ROSCO 1

#undef ROSCO_M68K
#define ROSCO_M68K 1
 
/* Default arguments for the m68k-elf-rosco-gcc toolchain 
   - link newlib BSP, GDB support optionally, and use our link script... */
#undef LIB_SPEC
#define LIB_SPEC "%{!g:-lc -lrosco -lc} %{g:-lg -lrosco %{mgdb:-lrosco_gdb} -lg} %{bin:--oformat=binary} %{!T*:-T hugerom_rosco_m68k_program.ld%s}" 
 
/* Files that are linked before user code.
   The %s tells GCC to look for these files in the library directory. */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "%{g:%{!mgdb:crt0.o%s} %{mgdb:gcrt0.o%s}} %{!g:crt0.o%s} crti.o%s crtbegin.o%s"
 
/* Files that are linked after user code. */
#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"
 
/* Additional predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()             \
  do {                                       \
    builtin_define ("__rosco_m68k__");       \
    builtin_define ("ROSCO_M68K");           \
    builtin_assert ("system=rosco_m68k");    \
  } while(0);

