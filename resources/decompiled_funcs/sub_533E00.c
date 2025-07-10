_DWORD *__cdecl sub_533E00(int a1, _DWORD *a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *result; // eax

  while ( 1 )
  {
    result = a2;
    if ( *a2 == a3 )
      break;
    result = (_DWORD *)*a4;
    if ( *a4 == a5 )
      break;
    *(_BYTE *)(*a4)++ = *(_BYTE *)(*a2)++;
  }
  return result;
}
