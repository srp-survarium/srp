int __cdecl isdigit(int c)
{
  if ( __locale_changed )
    return _isdigit_l(c, 0);
  else
    return __initiallocinfo.pctype[c] & 4;
}
