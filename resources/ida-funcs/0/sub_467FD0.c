__int16 __cdecl sub_467FD0(int a1)
{
  int v1; // eax
  char v3; // [esp+0h] [ebp-14h]
  __int16 v4; // [esp+4h] [ebp-10h]
  __int16 v5; // [esp+8h] [ebp-Ch]
  BOOL v6; // [esp+10h] [ebp-4h]

  v6 = *(unsigned __int16 *)(a1 + 308) != 0;
  if ( (*(_BYTE *)(a1 + 315) & 4) == 0 )
  {
    *(_DWORD *)(a1 + 116) &= ~0x800000u;
    *(_DWORD *)(a1 + 112) &= ~0x2000u;
    if ( !v6 )
      *(_DWORD *)(a1 + 116) &= 0xFFFFFE7F;
  }
  v1 = *(_DWORD *)(a1 + 116) & 0x100;
  if ( v1 )
  {
    if ( (*(_DWORD *)(a1 + 116) & 0x1000) != 0 )
    {
      LOWORD(v1) = a1;
      if ( (*(_BYTE *)(a1 + 315) & 2) == 0 )
      {
        v5 = *(_WORD *)(a1 + 348);
        v4 = *(_WORD *)(a1 + 432);
        v3 = *(_BYTE *)(a1 + 316);
        switch ( v3 )
        {
          case 1:
            v5 *= 255;
            v4 *= 255;
            break;
          case 2:
            v5 *= 85;
            v4 *= 85;
            break;
          case 4:
            v5 *= 17;
            v4 *= 17;
            break;
        }
        *(_WORD *)(a1 + 346) = v5;
        *(_WORD *)(a1 + 344) = v5;
        *(_WORD *)(a1 + 342) = v5;
        v1 = *(_DWORD *)(a1 + 116) & 0x2000000;
        if ( !v1 )
        {
          *(_WORD *)(a1 + 430) = v4;
          *(_WORD *)(a1 + 428) = v4;
          LOWORD(v1) = v4;
          *(_WORD *)(a1 + 426) = v4;
        }
      }
    }
  }
  return v1;
}
