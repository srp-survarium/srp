void __usercall _mbsrchr(unsigned int a1@<edi>, unsigned int a2@<esi>, unsigned __int8 *str, unsigned int c)
{
  _mbsrchr_l(a1, a2, str, c, 0);
}
