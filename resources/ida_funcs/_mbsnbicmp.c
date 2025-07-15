int __usercall _mbsnbicmp@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n)
{
  return _mbsnbicmp_l(a1, a2, s1, s2, n, 0);
}
