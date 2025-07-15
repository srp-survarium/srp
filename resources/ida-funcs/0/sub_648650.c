_BYTE *__cdecl sub_648650(_BYTE *a1)
{
  _BYTE *result; // eax
  char v2; // [esp+0h] [ebp-Ch]
  _BYTE *i; // [esp+4h] [ebp-8h]
  _BYTE *v4; // [esp+8h] [ebp-4h]

  v4 = a1;
  for ( i = a1; ; ++i )
  {
    result = i;
    if ( !*i )
      break;
    v2 = *i;
    if ( *i == 10 || v2 == 13 || v2 == 32 )
    {
      if ( v4 != a1 && *(v4 - 1) != 32 )
        *v4++ = 32;
    }
    else
    {
      *v4++ = *i;
    }
  }
  if ( v4 != a1 )
  {
    result = (_BYTE *)(char)*(v4 - 1);
    if ( result == (_BYTE *)32 )
      --v4;
  }
  *v4 = 0;
  return result;
}
