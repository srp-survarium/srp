unsigned int __usercall _mbsicmp@<eax>(int a1@<ebx>, int a2@<edi>, char *s1, char *s2)
{
  return _mbsicmp_l(a1, a2, s1, s2, 0);
}
