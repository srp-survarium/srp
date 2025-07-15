void __usercall _mbschr(int a1@<edi>, int a2@<esi>, char *string, unsigned int c)
{
  _mbschr_l(a1, a2, string, c, 0);
}
