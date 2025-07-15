int __cdecl sub_532FD0(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v8; // [esp+1Ch] [ebp+Ch]

  v5 = 1;
  v6 = 0;
  v7 = 0;
  v8 = (unsigned __int8 *)(a2 + 1);
  while ( 1 )
  {
    switch ( *(_BYTE *)(a1 + *v8 + 76) )
    {
      case 3:
        if ( v6 < a3 )
          *(_BYTE *)(a4 + 16 * v6 + 12) = 0;
        goto LABEL_2;
      case 5:
        if ( !v5 )
        {
          if ( v6 < a3 )
          {
            *(_DWORD *)(a4 + 16 * v6) = v8;
            *(_BYTE *)(a4 + 16 * v6 + 12) = 1;
          }
          v5 = 1;
        }
        ++v8;
        goto LABEL_2;
      case 6:
        if ( !v5 )
        {
          if ( v6 < a3 )
          {
            *(_DWORD *)(a4 + 16 * v6) = v8;
            *(_BYTE *)(a4 + 16 * v6 + 12) = 1;
          }
          v5 = 1;
        }
        v8 += 2;
        goto LABEL_2;
      case 7:
        if ( !v5 )
        {
          if ( v6 < a3 )
          {
            *(_DWORD *)(a4 + 16 * v6) = v8;
            *(_BYTE *)(a4 + 16 * v6 + 12) = 1;
          }
          v5 = 1;
        }
        v8 += 3;
        goto LABEL_2;
      case 9:
      case 0xA:
        if ( v5 == 1 )
        {
          v5 = 0;
        }
        else if ( v5 == 2 && v6 < a3 )
        {
          *(_BYTE *)(a4 + 16 * v6 + 12) = 0;
        }
        goto LABEL_2;
      case 0xB:
      case 0x11:
        if ( v5 == 2 )
          goto LABEL_2;
        return v6;
      case 0xC:
        if ( v5 == 2 )
        {
          if ( v7 == 12 )
          {
            v5 = 0;
            if ( v6 < a3 )
              *(_DWORD *)(a4 + 16 * v6 + 8) = v8;
            ++v6;
          }
        }
        else
        {
          if ( v6 < a3 )
            *(_DWORD *)(a4 + 16 * v6 + 4) = v8 + 1;
          v5 = 2;
          v7 = 12;
        }
        goto LABEL_2;
      case 0xD:
        if ( v5 == 2 )
        {
          if ( v7 == 13 )
          {
            v5 = 0;
            if ( v6 < a3 )
              *(_DWORD *)(a4 + 16 * v6 + 8) = v8;
            ++v6;
          }
        }
        else
        {
          if ( v6 < a3 )
            *(_DWORD *)(a4 + 16 * v6 + 4) = v8 + 1;
          v5 = 2;
          v7 = 13;
        }
        goto LABEL_2;
      case 0x15:
        if ( v5 == 1 )
        {
          v5 = 0;
        }
        else if ( v5 == 2
               && v6 < a3
               && *(_BYTE *)(a4 + 16 * v6 + 12)
               && (v8 == *(unsigned __int8 **)(a4 + 16 * v6 + 4)
                || *v8 != 32
                || v8[1] == 32
                || *(unsigned __int8 *)(a1 + v8[1] + 76) == v7) )
        {
          *(_BYTE *)(a4 + 16 * v6 + 12) = 0;
        }
        goto LABEL_2;
      case 0x16:
      case 0x18:
      case 0x1D:
        if ( !v5 )
        {
          if ( v6 < a3 )
          {
            *(_DWORD *)(a4 + 16 * v6) = v8;
            *(_BYTE *)(a4 + 16 * v6 + 12) = 1;
          }
          v5 = 1;
        }
        goto LABEL_2;
      default:
LABEL_2:
        ++v8;
        break;
    }
  }
}
