int __usercall _mbsicmp@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2)
{
  return _mbsicmp_l(a1, a2, s1, s2, 0);
}
