int __usercall _mbsnbcmp@<eax>(int a1@<esi>, char *s1, char *s2, unsigned int n)
{
  return _mbsnbcmp_l(a1, s1, s2, n, 0);
}
