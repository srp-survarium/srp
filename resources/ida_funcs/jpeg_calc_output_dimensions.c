char __cdecl jpeg_calc_output_dimensions(int a1)
{
  int v2; // ecx
  int v3; // ebx
  int *v4; // ebx
  int v5; // edi
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  bool v10; // cc
  int v11; // ebx
  _DWORD *v12; // edi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v18; // [esp+8h] [ebp+4h]

  if ( *(_DWORD *)(a1 + 20) != 202 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 21;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 20);
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  jpeg_core_output_dimensions();
  v3 = *(_DWORD *)(a1 + 196);
  v18 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v4 = (int *)(v3 + 36);
    do
    {
      v5 = *(_DWORD *)(a1 + 280);
      v6 = 1;
      if ( v5 <= 4 * (*(_BYTE *)(a1 + 72) != 0) + 4 )
      {
        do
        {
          if ( *(_DWORD *)(a1 + 272) % (2 * v6 * *(v4 - 7)) )
            break;
          v6 *= 2;
        }
        while ( v6 * v5 <= 4 * (*(_BYTE *)(a1 + 72) != 0) + 4 );
      }
      *v4 = v6 * v5;
      v7 = *(_DWORD *)(a1 + 284);
      v8 = 1;
      if ( v7 <= 4 * (*(_BYTE *)(a1 + 72) != 0) + 4 )
      {
        do
        {
          if ( *(_DWORD *)(a1 + 276) % (2 * v8 * *(v4 - 6)) )
            break;
          v8 *= 2;
        }
        while ( v8 * v7 <= 4 * (*(_BYTE *)(a1 + 72) != 0) + 4 );
      }
      v9 = v8 * v7;
      v2 = *v4;
      v10 = *v4 <= 2 * v9;
      v4[1] = v9;
      if ( v10 )
      {
        v2 *= 2;
        if ( v9 > v2 )
          v4[1] = v2;
      }
      else
      {
        *v4 = 2 * v9;
      }
      v4 += 22;
      ++v18;
    }
    while ( v18 < *(_DWORD *)(a1 + 36) );
  }
  v11 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v12 = (_DWORD *)(*(_DWORD *)(a1 + 196) + 8);
    do
    {
      v13 = jdiv_round_up(*(_DWORD *)(a1 + 28) * *v12 * v12[7], *(_DWORD *)(a1 + 384) * *(_DWORD *)(a1 + 272));
      v14 = v12[1] * v12[8];
      v12[9] = v13;
      v12[10] = jdiv_round_up(*(_DWORD *)(a1 + 32) * v14, *(_DWORD *)(a1 + 384) * *(_DWORD *)(a1 + 276));
      ++v11;
      v12 += 22;
    }
    while ( v11 < *(_DWORD *)(a1 + 36) );
  }
  switch ( *(_DWORD *)(a1 + 44) )
  {
    case 1:
      *(_DWORD *)(a1 + 100) = 1;
      break;
    case 2:
    case 3:
      *(_DWORD *)(a1 + 100) = 3;
      break;
    case 4:
    case 5:
      *(_DWORD *)(a1 + 100) = 4;
      break;
    default:
      *(_DWORD *)(a1 + 100) = *(_DWORD *)(a1 + 36);
      break;
  }
  v15 = 1;
  if ( !*(_BYTE *)(a1 + 74) )
    v15 = *(_DWORD *)(a1 + 100);
  *(_DWORD *)(a1 + 104) = v15;
  LOBYTE(v16) = sub_373200(v2, a1);
  if ( (_BYTE)v16 )
  {
    v16 = *(_DWORD *)(a1 + 276);
    *(_DWORD *)(a1 + 108) = v16;
  }
  else
  {
    *(_DWORD *)(a1 + 108) = 1;
  }
  return v16;
}
