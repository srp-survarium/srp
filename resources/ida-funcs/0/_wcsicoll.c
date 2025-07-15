int __usercall _wcsicoll@<eax>(int a1@<ebx>, int a2@<edi>, const wchar_t *_string1, const wchar_t *_string2)
{
  const wchar_t *v4; // edi
  const wchar_t *v6; // edx
  wchar_t v7; // ax
  wchar_t v8; // cx
  wchar_t v9; // ax

  if ( __locale_changed )
    return _wcsicoll_l(a2, _string1, _string2, 0);
  v4 = _string1;
  if ( _string1 && (v6 = _string2) != 0 )
  {
    do
    {
      v7 = *v4;
      if ( *v4 >= 0x41u && v7 <= 0x5Au )
        v7 += 32;
      v8 = v7;
      v9 = *v6;
      if ( *v6 >= 0x41u && v9 <= 0x5Au )
        v9 += 32;
      ++v4;
      ++v6;
    }
    while ( v8 && v8 == v9 );
    return v8 - v9;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, (int)_string1, 0);
    return 0x7FFFFFFF;
  }
}
