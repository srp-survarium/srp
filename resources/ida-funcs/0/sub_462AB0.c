void __usercall __noreturn sub_462AB0(int a1@<edi>, int a2, const char *a3)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  const char *v5; // [esp+0h] [ebp-4h]

  if ( a3 )
    v5 = a3;
  else
    v5 = "undefined";
  v3 = __iob_func();
  fprintf(a1, v3 + 2, "libpng error: %s", v5);
  v4 = __iob_func();
  fprintf(a1, v4 + 2, "\n");
  png_longjmp(a2, 1);
}
