void __usercall _mbsnbicmp(const char *a1@<edi>, int a2@<esi>, char *s1, char *s2, unsigned int n)
{
  _mbsnbicmp_l(a1, a2, s1, s2, n, 0);
}
