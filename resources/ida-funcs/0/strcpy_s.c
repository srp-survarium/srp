int __usercall strcpy_s@<eax>(int a1@<edi>, char *_Dst, int _SizeInBytes, const char *_Src)
{
  int v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // al

  if ( !_Dst )
    goto LABEL_3;
  a1 = _SizeInBytes;
  if ( !_SizeInBytes )
    goto LABEL_3;
  v6 = _Src;
  if ( !_Src )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter(0, a1, v4);
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
  if ( !a1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}
