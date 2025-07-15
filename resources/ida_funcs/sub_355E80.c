int __cdecl sub_355E80(int a1, const char *a2)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax

  v2 = __iob_func();
  fprintf(v2 + 2, "libpng warning: %s", a2);
  v3 = __iob_func();
  return fprintf(v3 + 2, "\n");
}
