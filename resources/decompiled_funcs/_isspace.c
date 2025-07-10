int __cdecl isspace(int c)
{
  if ( __locale_changed )
    return _isspace_l(c, 0);
  else
    return __initiallocinfo.pctype[c] & 8;
}
