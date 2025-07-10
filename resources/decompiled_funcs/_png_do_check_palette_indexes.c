int __cdecl png_do_check_palette_indexes(int a1, int a2)
{
  int result; // eax
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-Ch]
  char v9; // [esp+Ch] [ebp-8h]
  unsigned __int8 *v10; // [esp+10h] [ebp-4h]

  result = 1 << *(_BYTE *)(a2 + 9);
  if ( *(unsigned __int16 *)(a1 + 300) < result && *(_WORD *)(a1 + 300) )
  {
    v9 = (*(_BYTE *)a2 * -*(_BYTE *)(a2 + 11)) & 7;
    v10 = (unsigned __int8 *)(*(_DWORD *)(a2 + 4) + *(_DWORD *)(a1 + 264));
    switch ( *(_BYTE *)(a2 + 9) )
    {
      case 1:
        while ( 1 )
        {
          result = (int)v10;
          if ( (unsigned int)v10 <= *(_DWORD *)(a1 + 264) )
            break;
          if ( (int)*v10 >> v9 )
            *(_DWORD *)(a1 + 304) = 1;
          v9 = 0;
          --v10;
        }
        break;
      case 2:
        while ( 1 )
        {
          result = (int)v10;
          if ( (unsigned int)v10 <= *(_DWORD *)(a1 + 264) )
            break;
          v5 = ((int)*v10 >> v9) & 3;
          if ( v5 > *(_DWORD *)(a1 + 304) )
            *(_DWORD *)(a1 + 304) = v5;
          v6 = ((int)*v10 >> v9 >> 2) & 3;
          if ( v6 > *(_DWORD *)(a1 + 304) )
            *(_DWORD *)(a1 + 304) = v6;
          v7 = ((int)*v10 >> v9 >> 4) & 3;
          if ( v7 > *(_DWORD *)(a1 + 304) )
            *(_DWORD *)(a1 + 304) = v7;
          v8 = ((int)*v10 >> v9 >> 6) & 3;
          if ( v8 > *(_DWORD *)(a1 + 304) )
            *(_DWORD *)(a1 + 304) = v8;
          v9 = 0;
          --v10;
        }
        break;
      case 4:
        while ( 1 )
        {
          result = (int)v10;
          if ( (unsigned int)v10 <= *(_DWORD *)(a1 + 264) )
            break;
          v3 = ((int)*v10 >> v9) & 0xF;
          if ( v3 > *(_DWORD *)(a1 + 304) )
            *(_DWORD *)(a1 + 304) = v3;
          v4 = ((int)*v10 >> v9 >> 4) & 0xF;
          if ( v4 > *(_DWORD *)(a1 + 304) )
            *(_DWORD *)(a1 + 304) = v4;
          v9 = 0;
          --v10;
        }
        break;
      case 8:
        while ( 1 )
        {
          result = (int)v10;
          if ( (unsigned int)v10 <= *(_DWORD *)(a1 + 264) )
            break;
          if ( *v10 > *(int *)(a1 + 304) )
            *(_DWORD *)(a1 + 304) = *v10;
          --v10;
        }
        break;
      default:
        result = a2;
        break;
    }
  }
  return result;
}
