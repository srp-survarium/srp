unsigned int __usercall _stricmp@<eax>(int a1@<ebx>, int a2@<edi>, char *dst, char *src)
{
  if ( __locale_changed )
    return _stricmp_l(a2, 0, dst, src, 0);
  if ( dst && src )
    return __ascii_stricmp(dst, src);
  *_errno() = 22;
  _invalid_parameter(a1, a2, 0);
  return 0x7FFFFFFF;
}
