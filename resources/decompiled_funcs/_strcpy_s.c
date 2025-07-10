int __cdecl strcpy_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // al

  if ( !_Dst )
    goto LABEL_3;
  v3 = _SizeInBytes;
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
    _invalid_parameter(0, 0, 0, 0, 0);
    return v4;
  }
  v7 = _Dst;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( !v8 )
      break;
    --v3;
  }
  while ( v3 );
  if ( !v3 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}
