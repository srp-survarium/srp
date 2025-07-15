int __cdecl _fptostr(char *buf, unsigned int sizeInBytes, int digits, _strflt *pflt)
{
  _strflt *v4; // ecx
  char *mantissa; // edi
  int v6; // esi
  int v8; // edx
  int v9; // eax
  char *v10; // eax
  char v11; // cl
  int v12; // eax

  v4 = pflt;
  mantissa = pflt->mantissa;
  if ( !buf || !sizeInBytes )
  {
    v6 = 22;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter(0, (int)mantissa, v6);
    return v6;
  }
  v8 = digits;
  *buf = 0;
  if ( digits <= 0 )
    v9 = 0;
  else
    v9 = digits;
  if ( sizeInBytes <= v9 + 1 )
  {
    *_errno() = 34;
    v6 = 34;
    goto LABEL_3;
  }
  *buf = 48;
  v10 = buf + 1;
  if ( digits > 0 )
  {
    do
    {
      v11 = *mantissa;
      if ( *mantissa )
        ++mantissa;
      else
        v11 = 48;
      *v10++ = v11;
      --v8;
    }
    while ( v8 > 0 );
    v4 = pflt;
  }
  *v10 = 0;
  if ( v8 >= 0 && *mantissa >= 53 )
  {
    while ( *--v10 == 57 )
      *v10 = 48;
    ++*v10;
  }
  if ( *buf == 49 )
  {
    ++v4->decpt;
  }
  else
  {
    strlen((unsigned __int8 *)buf + 1);
    memmove((int)buf, (const __m128i *)(buf + 1), v12 + 1);
  }
  return 0;
}
