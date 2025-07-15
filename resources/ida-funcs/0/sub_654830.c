int __cdecl sub_654830(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+0h] [ebp-20h]
  int v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-18h]
  int v8; // [esp+10h] [ebp-10h]
  int v9; // [esp+14h] [ebp-Ch]
  int v10; // [esp+18h] [ebp-8h]
  int v11; // [esp+1Ch] [ebp-4h]
  unsigned __int8 *v12; // [esp+2Ch] [ebp+Ch]

  v9 = 1;
  v10 = 0;
  v11 = 0;
  v12 = (unsigned __int8 *)(a2 + 2);
  while ( 1 )
  {
    if ( v12[1] )
      v8 = sub_64FDE0(v12[1], *v12);
    else
      v8 = *(unsigned __int8 *)(a1 + *v12 + 76);
    switch ( v8 )
    {
      case 3:
        if ( v10 < a3 )
          *(_BYTE *)(a4 + 16 * v10 + 12) = 0;
        goto LABEL_2;
      case 5:
        if ( !v9 )
        {
          if ( v10 < a3 )
          {
            *(_DWORD *)(a4 + 16 * v10) = v12;
            *(_BYTE *)(a4 + 16 * v10 + 12) = 1;
          }
          v9 = 1;
        }
        goto LABEL_2;
      case 6:
        if ( !v9 )
        {
          if ( v10 < a3 )
          {
            *(_DWORD *)(a4 + 16 * v10) = v12;
            *(_BYTE *)(a4 + 16 * v10 + 12) = 1;
          }
          v9 = 1;
        }
        ++v12;
        goto LABEL_2;
      case 7:
        if ( !v9 )
        {
          if ( v10 < a3 )
          {
            *(_DWORD *)(a4 + 16 * v10) = v12;
            *(_BYTE *)(a4 + 16 * v10 + 12) = 1;
          }
          v9 = 1;
        }
        v12 += 2;
        goto LABEL_2;
      case 9:
      case 10:
        if ( v9 == 1 )
        {
          v9 = 0;
        }
        else if ( v9 == 2 && v10 < a3 )
        {
          *(_BYTE *)(a4 + 16 * v10 + 12) = 0;
        }
        goto LABEL_2;
      case 11:
      case 17:
        if ( v9 == 2 )
          goto LABEL_2;
        return v10;
      case 12:
        if ( v9 == 2 )
        {
          if ( v11 == 12 )
          {
            v9 = 0;
            if ( v10 < a3 )
              *(_DWORD *)(a4 + 16 * v10 + 8) = v12;
            ++v10;
          }
        }
        else
        {
          if ( v10 < a3 )
            *(_DWORD *)(a4 + 16 * v10 + 4) = v12 + 2;
          v9 = 2;
          v11 = 12;
        }
        goto LABEL_2;
      case 13:
        if ( v9 == 2 )
        {
          if ( v11 == 13 )
          {
            v9 = 0;
            if ( v10 < a3 )
              *(_DWORD *)(a4 + 16 * v10 + 8) = v12;
            ++v10;
          }
        }
        else
        {
          if ( v10 < a3 )
            *(_DWORD *)(a4 + 16 * v10 + 4) = v12 + 2;
          v9 = 2;
          v11 = 13;
        }
        goto LABEL_2;
      case 21:
        if ( v9 == 1 )
        {
          v9 = 0;
        }
        else if ( v9 == 2 && v10 < a3 && *(_BYTE *)(a4 + 16 * v10 + 12) )
        {
          if ( v12 == *(unsigned __int8 **)(a4 + 16 * v10 + 4)
            || (v12[1] ? (v7 = -1) : (v7 = (char)*v12),
                v7 != 32
             || (v12[3] ? (v6 = -1) : (v6 = (char)v12[2]),
                 v6 == 32
              || (v12[3] ? (v5 = sub_64FDE0(v12[3], v12[2])) : (v5 = *(unsigned __int8 *)(a1 + v12[2] + 76)), v5 == v11))) )
          {
            *(_BYTE *)(a4 + 16 * v10 + 12) = 0;
          }
        }
        goto LABEL_2;
      case 22:
      case 24:
      case 29:
        if ( !v9 )
        {
          if ( v10 < a3 )
          {
            *(_DWORD *)(a4 + 16 * v10) = v12;
            *(_BYTE *)(a4 + 16 * v10 + 12) = 1;
          }
          v9 = 1;
        }
        goto LABEL_2;
      default:
LABEL_2:
        v12 += 2;
        break;
    }
  }
}
