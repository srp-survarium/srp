int __cdecl sub_35B140(int a1)
{
  int result; // eax
  int v2; // [esp+0h] [ebp-14h]
  int j; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  v5 = 0;
  v6 = 0;
  result = a1;
  if ( *(_WORD *)(a1 + 308) )
  {
    for ( i = 0; ; ++i )
    {
      result = a1;
      if ( i >= *(unsigned __int16 *)(a1 + 308) )
        break;
      if ( *(unsigned __int8 *)(*(_DWORD *)(a1 + 420) + i) != 255 )
      {
        if ( *(_BYTE *)(*(_DWORD *)(a1 + 420) + i) )
          v5 = 1;
        else
          v6 = 1;
      }
    }
  }
  if ( !v5 )
  {
    *(_DWORD *)(a1 + 116) &= ~0x800000u;
    result = a1;
    *(_DWORD *)(a1 + 112) &= ~0x2000u;
    if ( !v6 )
    {
      result = a1;
      *(_DWORD *)(a1 + 116) &= 0xFFFFFE7F;
    }
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x100) != 0 )
  {
    result = a1;
    if ( (*(_DWORD *)(a1 + 116) & 0x1000) != 0 )
    {
      *(_WORD *)(a1 + 342) = *(unsigned __int8 *)(*(_DWORD *)(a1 + 296) + 3 * *(unsigned __int8 *)(a1 + 340));
      *(_WORD *)(a1 + 344) = *(unsigned __int8 *)(*(_DWORD *)(a1 + 296) + 3 * *(unsigned __int8 *)(a1 + 340) + 1);
      *(_WORD *)(a1 + 346) = *(unsigned __int8 *)(*(_DWORD *)(a1 + 296) + 3 * *(unsigned __int8 *)(a1 + 340) + 2);
      result = *(_DWORD *)(a1 + 116) & 0x80000;
      if ( result )
      {
        if ( (*(_DWORD *)(a1 + 116) & 0x2000000) == 0 )
        {
          v2 = *(unsigned __int16 *)(a1 + 308);
          for ( j = 0; ; ++j )
          {
            result = j;
            if ( j >= v2 )
              break;
            *(_BYTE *)(*(_DWORD *)(a1 + 420) + j) = -1 - *(_BYTE *)(*(_DWORD *)(a1 + 420) + j);
          }
        }
      }
    }
  }
  return result;
}
