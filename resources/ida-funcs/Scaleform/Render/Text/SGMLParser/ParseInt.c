char __cdecl Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(
        int *pdestVal,
        const wchar_t *pstr,
        unsigned int len)
{
  unsigned int v3; // ebp
  const wchar_t *v5; // esi
  int v6; // edi
  int v7; // ecx
  unsigned int v8; // ebx
  int v9; // ecx
  int v10; // [esp+10h] [ebp+Ch]

  v3 = len;
  if ( !len )
    return 0;
  v5 = pstr;
  v6 = 0;
  v7 = 1;
  v10 = 1;
  if ( *pstr == 45 )
  {
    v10 = -1;
    v7 = -1;
  }
  else if ( *pstr != 43 )
  {
    goto LABEL_7;
  }
  v5 = pstr + 1;
  --v3;
LABEL_7:
  v8 = 0;
  if ( v3 )
  {
    while ( isdigit(*v5) )
    {
      v9 = *v5;
      ++v8;
      ++v5;
      v6 = v9 + 10 * v6 - 48;
      if ( v8 >= v3 )
      {
        v7 = v10;
        goto LABEL_11;
      }
    }
    return 0;
  }
  else
  {
LABEL_11:
    *pdestVal = v6 * v7;
    return 1;
  }
}
