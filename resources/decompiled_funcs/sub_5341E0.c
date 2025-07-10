int __cdecl sub_5341E0(int a1, char **a2, char *a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = 2 * ((a5 - *a4) >> 1);
  if ( a3 - *a2 > result && (*(a3 - 1) & 0xF8) == 0xD8 )
  {
    result = (int)(a3 - 2);
    a3 -= 2;
  }
  while ( *a2 != a3 )
  {
    result = (int)a4;
    if ( *a4 == a5 )
      break;
    *(_WORD *)*a4 = *(_WORD *)*a2;
    *a4 += 2;
    result = (int)a2;
    *a2 += 2;
  }
  return result;
}
