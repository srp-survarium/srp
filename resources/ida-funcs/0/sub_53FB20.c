int __cdecl sub_53FB20(int a1, int a2)
{
  int v3; // [esp+4h] [ebp-4h]

  while ( 1 )
  {
    v3 = *(_BYTE *)a2
       ? sub_534A50(*(_BYTE *)a2, *(_BYTE *)(a2 + 1))
       : *(unsigned __int8 *)(a1 + *(unsigned __int8 *)(a2 + 1) + 76);
    if ( v3 < 9 || v3 > 10 && v3 != 21 )
      break;
    a2 += 2;
  }
  return a2;
}
