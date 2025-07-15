void __cdecl __noreturn sub_355DF0(int a1, const char *a2)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  const char *v4; // [esp+0h] [ebp-4h]

  if ( a2 )
    v4 = a2;
  else
    v4 = "undefined";
  v2 = __iob_func();
  fprintf(v2 + 2, "libpng error: %s", v4);
  v3 = __iob_func();
  fprintf(v3 + 2, "\n");
  png_longjmp(a1, 1);
}
