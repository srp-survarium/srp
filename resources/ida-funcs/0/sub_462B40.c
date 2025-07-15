int __usercall sub_462B40@<eax>(int a1@<edi>, int a2, const char *a3)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax

  v3 = __iob_func();
  fprintf(a1, v3 + 2, "libpng warning: %s", a3);
  v4 = __iob_func();
  return fprintf(a1, v4 + 2, "\n");
}
