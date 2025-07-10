int __usercall _mbsnbcmp@<eax>(
        unsigned int a1@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n)
{
  return _mbsnbcmp_l(a1, s1, s2, n, 0);
}
