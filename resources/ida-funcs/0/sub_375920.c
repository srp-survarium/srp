char __usercall sub_375920@<al>(int a1@<edi>)
{
  int v1; // esi
  _DWORD *v2; // edx
  int v3; // esi
  int v4; // ebp
  _WORD **v5; // eax
  _WORD *v6; // eax
  int *v7; // eax
  char v9; // [esp+7h] [ebp-5h]
  _WORD **i; // [esp+8h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 408);
  v9 = 0;
  if ( !*(_BYTE *)(a1 + 201) || !*(_DWORD *)(a1 + 140) )
    return 0;
  if ( !*(_DWORD *)(v1 + 112) )
    *(_DWORD *)(v1 + 112) = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 24 * *(_DWORD *)(a1 + 36));
  v2 = *(_DWORD **)(v1 + 112);
  v3 = 0;
  if ( *(int *)(a1 + 36) <= 0 )
    return v9;
  v4 = 0;
  v5 = (_WORD **)(*(_DWORD *)(a1 + 196) + 80);
  for ( i = v5; ; i += 22 )
  {
    v6 = *v5;
    if ( !v6 )
      break;
    if ( !*v6 )
      break;
    if ( !v6[1] )
      break;
    if ( !v6[8] )
      break;
    if ( !v6[16] )
      break;
    if ( !v6[9] )
      break;
    if ( !v6[2] )
      break;
    v7 = (int *)(v4 + *(_DWORD *)(a1 + 140));
    if ( *v7 < 0 )
      break;
    v2[1] = v7[1];
    if ( v7[1] )
      v9 = 1;
    v2[2] = v7[2];
    if ( v7[2] )
      v9 = 1;
    v2[3] = v7[3];
    if ( v7[3] )
      v9 = 1;
    v2[4] = v7[4];
    if ( v7[4] )
      v9 = 1;
    v2[5] = v7[5];
    if ( v7[5] )
      v9 = 1;
    ++v3;
    v5 = i + 22;
    v2 += 6;
    v4 += 256;
    if ( v3 >= *(_DWORD *)(a1 + 36) )
      return v9;
  }
  return 0;
}
