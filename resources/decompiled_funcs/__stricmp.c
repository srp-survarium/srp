int __cdecl _stricmp(const char *dst, const char *src)
{
  if ( __locale_changed )
    return _stricmp_l(dst, src, 0);
  if ( dst && src )
    return __ascii_stricmp(dst, src);
  *_errno() = 22;
  _invalid_parameter(0, 0, 0, 0, 0);
  return 0x7FFFFFFF;
}
