int __cdecl isxdigit(int c)
{
  if ( __locale_changed )
    return _isxdigit_l(c, 0);
  else
    return __initiallocinfo.pctype[c] & 0x80;
}
