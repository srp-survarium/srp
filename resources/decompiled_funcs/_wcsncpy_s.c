unsigned int __usercall wcsncpy_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int16 *_Dst,
        unsigned int _SizeInWords,
        const wchar_t *_Src,
        unsigned int _Count)
{
  unsigned int v6; // esi
  const wchar_t *v7; // edx
  unsigned __int16 *v8; // eax
  wchar_t v9; // cx
  wchar_t v10; // cx

  if ( _Count )
  {
    if ( !_Dst )
    {
LABEL_7:
      v6 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter(a1, 0, v6);
      return v6;
    }
  }
  else if ( !_Dst )
  {
    if ( !_SizeInWords )
      return 0;
    goto LABEL_7;
  }
  a1 = _SizeInWords;
  if ( !_SizeInWords )
    goto LABEL_7;
  if ( !_Count )
  {
    *_Dst = 0;
    return 0;
  }
  v7 = _Src;
  if ( !_Src )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v8 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v9 = *v7;
      *v8++ = *v7++;
      if ( !v9 )
        break;
      --a1;
    }
    while ( a1 );
  }
  else
  {
    do
    {
      v10 = *v7;
      *v8++ = *v7++;
      if ( !v10 )
        break;
      if ( !--a1 )
        break;
      --_Count;
    }
    while ( _Count );
    if ( !_Count )
      *v8 = 0;
  }
  if ( a1 )
    return 0;
  if ( _Count != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v6 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInWords - 1] = 0;
  return 80;
}
