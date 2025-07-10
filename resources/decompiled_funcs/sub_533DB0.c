_WORD *__cdecl sub_533DB0(int a1, _DWORD *a2, int a3, _DWORD *a4, int a5)
{
  _WORD *result; // eax

  while ( 1 )
  {
    result = a2;
    if ( *a2 == a3 )
      break;
    result = (_WORD *)*a4;
    if ( *a4 == a5 )
      break;
    *(_WORD *)*a4 = *(unsigned __int8 *)*a2;
    *a4 += 2;
    ++*a2;
  }
  return result;
}
