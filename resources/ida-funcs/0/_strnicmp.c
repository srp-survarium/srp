void __usercall _strnicmp(unsigned int a1@<ebx>, const char *a2@<edi>, char *dst, char *src, unsigned int count)
{
  if ( __locale_changed )
  {
    _strnicmp_l(a2, 0, dst, src, count, 0);
  }
  else if ( dst && src && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp((unsigned __int8 *)dst, (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, (unsigned int)a2, 0);
  }
}
