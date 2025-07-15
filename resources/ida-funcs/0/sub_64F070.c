_DWORD *__cdecl sub_64F070(__int16 a1, _BYTE **a2, _BYTE *a3, _DWORD *a4, int a5)
{
  _DWORD *result; // eax
  unsigned __int8 v6; // [esp+1h] [ebp-1h]

  while ( 1 )
  {
    result = a2;
    if ( *a2 == a3 )
      break;
    v6 = **a2;
    if ( (v6 & 0x80) != 0 )
    {
      result = a4;
      if ( a5 - *a4 < 2 )
        return result;
      *(_BYTE *)(*a4)++ = ((int)v6 >> 6) | 0xC0;
      *(_BYTE *)(*a4)++ = v6 & 0x3F | 0x80;
      ++*a2;
    }
    else
    {
      result = (_DWORD *)*a4;
      if ( *a4 == a5 )
        return result;
      *(_BYTE *)(*a4)++ = *(*a2)++;
    }
  }
  return result;
}
