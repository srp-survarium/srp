int __usercall strncpy_s@<eax>(int a1@<edi>, char *_Dst, int _SizeInBytes, const char *_Src, unsigned int _Count)
{
  int v6; // esi
  const char *v7; // edx
  char *v8; // eax
  char v9; // cl
  char v10; // cl

  if ( _Count )
  {
    if ( !_Dst )
    {
LABEL_7:
      v6 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter(0, a1, v6);
      return v6;
    }
  }
  else if ( !_Dst )
  {
    if ( !_SizeInBytes )
      return 0;
    goto LABEL_7;
  }
  a1 = _SizeInBytes;
  if ( !_SizeInBytes )
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
  _Dst[_SizeInBytes - 1] = 0;
  return 80;
}
