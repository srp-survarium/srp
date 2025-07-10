int __usercall _wcsnicmp@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int16 *a2@<edi>,
        wchar_t *first,
        wchar_t *last,
        unsigned int count)
{
  int result; // eax
  wchar_t *v6; // edi
  wchar_t *v7; // edx
  wchar_t v8; // ax
  wchar_t v9; // cx
  wchar_t v10; // ax

  if ( __locale_changed )
    return _wcsnicmp_l(a2, first, last, count, 0);
  result = 0;
  if ( count )
  {
    v6 = first;
    if ( first && (v7 = last) != 0 )
    {
      do
      {
        v8 = *v6;
        if ( *v6 >= 0x41u && v8 <= 0x5Au )
          v8 += 32;
        v9 = v8;
        v10 = *v7;
        if ( *v7 >= 0x41u && v10 <= 0x5Au )
          v10 += 32;
        ++v6;
        ++v7;
        --count;
      }
      while ( count && v9 && v9 == v10 );
      return v9 - v10;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(a1, (unsigned int)first, 0);
      return 0x7FFFFFFF;
    }
  }
  return result;
}
