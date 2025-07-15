int __cdecl sub_5110D0(unsigned int a1, __int16 a2, int a3, int a4, unsigned __int8 *a5)
{
  int result; // eax
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+0h] [ebp-Ch]
  unsigned __int8 *j; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = a1; ; i = result + 3 )
  {
    result = sub_5111D0(i, a3);
    if ( !result )
      break;
    for ( j = a5; (unsigned int)j < *(_DWORD *)(a4 + 36); j += 2 )
    {
      v6 = j[1] | (*j << 8);
      if ( v6 + *(_DWORD *)(a4 + 20) == result + 1 )
      {
        *j = (unsigned __int16)(a2 + _byteswap_ushort(*(_WORD *)j)) >> 8;
        j[1] = a2 + v6;
        break;
      }
    }
    if ( (unsigned int)j >= *(_DWORD *)(a4 + 36) )
    {
      v7 = *(unsigned __int8 *)(result + 2) | (*(unsigned __int8 *)(result + 1) << 8);
      if ( v7 + *(_DWORD *)(a4 + 20) >= a1 )
      {
        *(_BYTE *)(result + 1) = (unsigned __int16)(a2 + _byteswap_ushort(*(_WORD *)(result + 1))) >> 8;
        *(_BYTE *)(result + 2) = a2 + v7;
      }
    }
  }
  return result;
}
