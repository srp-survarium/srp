unsigned __int8 *__cdecl sub_6553C0(int a1, unsigned __int8 *a2)
{
  int v3; // [esp+4h] [ebp-4h]

  while ( 1 )
  {
    v3 = a2[1] ? sub_64FDE0(a2[1], *a2) : *(unsigned __int8 *)(a1 + *a2 + 76);
    if ( v3 < 9 || v3 > 10 && v3 != 21 )
      break;
    a2 += 2;
  }
  return a2;
}
