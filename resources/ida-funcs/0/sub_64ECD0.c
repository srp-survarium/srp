unsigned __int8 *__cdecl sub_64ECD0(int a1, unsigned __int8 *a2)
{
  unsigned __int8 v3; // [esp+0h] [ebp-4h]

  while ( 1 )
  {
    v3 = *(_BYTE *)(a1 + *a2 + 76);
    if ( v3 < 9u || v3 > 0xAu && v3 != 21 )
      break;
    ++a2;
  }
  return a2;
}
