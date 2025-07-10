int __cdecl isupper(int c)
{
  if ( __locale_changed )
    return _isupper_l(c, 0);
  else
    return __initiallocinfo.pctype[c] & 1;
}
