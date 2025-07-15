void __usercall _mbsrchr(int a1@<edi>, int a2@<esi>, const char *str, unsigned int c)
{
  _mbsrchr_l(a1, a2, str, c, 0);
}
