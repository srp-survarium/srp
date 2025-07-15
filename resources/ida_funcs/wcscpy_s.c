unsigned int __usercall wcscpy_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int16 *_Dst,
        unsigned int _SizeInWords,
        const wchar_t *_Src)
{
  unsigned int v4; // esi
  unsigned int result; // eax
  const wchar_t *v6; // esi
  unsigned __int16 *v7; // ecx
  wchar_t v8; // ax

  if ( !_Dst )
    goto LABEL_3;
  a1 = _SizeInWords;
  if ( !_SizeInWords )
    goto LABEL_3;
  v6 = _Src;
  if ( !_Src )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter(a1, 0, v4);
    return v4;
  }
  v7 = _Dst;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( !v8 )
      break;
    --a1;
  }
  while ( a1 );
  result = 0;
  if ( !a1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return result;
}
