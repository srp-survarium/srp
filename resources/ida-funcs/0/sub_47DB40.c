int __usercall sub_47DB40@<eax>(int a1@<esi>)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edx
  int v4; // edi
  _DWORD *v5; // eax
  int result; // eax

  switch ( *(_DWORD *)(a1 + 36) )
  {
    case 1:
      *(_DWORD *)(a1 + 40) = 1;
      *(_DWORD *)(a1 + 44) = 1;
      break;
    case 3:
      if ( !*(_BYTE *)(a1 + 256) )
      {
        if ( *(_BYTE *)(a1 + 264) )
        {
          if ( *(_BYTE *)(a1 + 265) )
          {
            if ( *(_BYTE *)(a1 + 265) != 1 )
            {
              *(_DWORD *)(*(_DWORD *)a1 + 20) = 116;
              *(_DWORD *)(*(_DWORD *)a1 + 24) = *(unsigned __int8 *)(a1 + 265);
              (*(void (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, -1);
            }
            goto LABEL_20;
          }
LABEL_24:
          *(_DWORD *)(a1 + 40) = 2;
          *(_DWORD *)(a1 + 44) = 2;
          break;
        }
        v1 = *(int **)(a1 + 196);
        v2 = *v1;
        v3 = v1[22];
        v4 = v1[44];
        if ( *v1 == 1 )
        {
          if ( v3 == 2 && v4 == 3 )
            goto LABEL_20;
        }
        else if ( v2 == 82 && v3 == 71 && v4 == 66 )
        {
          goto LABEL_24;
        }
        v5 = (_DWORD *)(*(_DWORD *)a1 + 24);
        *v5 = v2;
        v5[1] = v3;
        v5[2] = v4;
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 113;
        (*(void (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, 1);
      }
LABEL_20:
      *(_DWORD *)(a1 + 40) = 3;
      *(_DWORD *)(a1 + 44) = 2;
      break;
    case 4:
      if ( *(_BYTE *)(a1 + 264) && *(_BYTE *)(a1 + 265) )
      {
        if ( *(_BYTE *)(a1 + 265) != 2 )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 116;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = *(unsigned __int8 *)(a1 + 265);
          (*(void (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, -1);
        }
        *(_DWORD *)(a1 + 40) = 5;
        *(_DWORD *)(a1 + 44) = 4;
      }
      else
      {
        *(_DWORD *)(a1 + 40) = 4;
        *(_DWORD *)(a1 + 44) = 4;
      }
      break;
    default:
      *(_DWORD *)(a1 + 40) = 0;
      *(_DWORD *)(a1 + 44) = 0;
      break;
  }
  result = *(_DWORD *)(a1 + 384);
  *(double *)(a1 + 56) = 1.0;
  *(_BYTE *)(a1 + 64) = 0;
  *(_BYTE *)(a1 + 65) = 0;
  *(_DWORD *)(a1 + 68) = 0;
  *(_BYTE *)(a1 + 74) = 0;
  *(_DWORD *)(a1 + 116) = 0;
  *(_BYTE *)(a1 + 88) = 0;
  *(_BYTE *)(a1 + 89) = 0;
  *(_BYTE *)(a1 + 90) = 0;
  *(_DWORD *)(a1 + 48) = result;
  *(_DWORD *)(a1 + 52) = result;
  *(_BYTE *)(a1 + 72) = 1;
  *(_BYTE *)(a1 + 73) = 1;
  *(_DWORD *)(a1 + 76) = 2;
  *(_BYTE *)(a1 + 80) = 1;
  *(_DWORD *)(a1 + 84) = 256;
  return result;
}
