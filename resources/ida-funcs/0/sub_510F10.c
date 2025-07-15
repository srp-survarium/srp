int __cdecl sub_510F10(unsigned int a1, unsigned int a2, int **a3, int a4, _DWORD *a5)
{
  while ( a3 && (unsigned int)a3[1] >= a1 )
  {
    if ( !sub_510830((unsigned __int8 *)a3[1], a2, a4, a5) )
      return 0;
    a3 = (int **)*a3;
  }
  return 1;
}
