int __cdecl sub_648EA0(int **a1)
{
  int v2; // [esp+0h] [ebp-4h]

  while ( *a1 != a1[1] )
  {
    v2 = *(*a1)++;
    if ( v2 )
      return v2;
  }
  return 0;
}
