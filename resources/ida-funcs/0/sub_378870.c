char __cdecl sub_378870(_DWORD *a1, int a2)
{
  int v3; // ebx
  int v4; // ebp
  _BYTE *v5; // edi
  int v6; // eax
  _BYTE *v7; // edi
  int v8; // ebp
  int v9; // ecx
  int v10; // eax
  _BYTE *v11; // edi
  int v12; // ebp
  int v13; // eax
  _BYTE *v14; // edi
  int v15; // ebp
  _BYTE *v16; // edi
  int v17; // ebx
  int v18; // eax
  _BYTE *v19; // edi
  int v20; // ebx
  int v21; // eax
  int v23; // [esp+8h] [ebp-24h]
  int v24; // [esp+Ch] [ebp-20h]
  int v25; // [esp+Ch] [ebp-20h]
  int v26; // [esp+10h] [ebp-1Ch]
  int v27; // [esp+10h] [ebp-1Ch]
  int v28; // [esp+14h] [ebp-18h]
  int v29; // [esp+18h] [ebp-14h]
  int *i; // [esp+1Ch] [ebp-10h]
  _WORD *v31; // [esp+20h] [ebp-Ch]
  int v32; // [esp+24h] [ebp-8h]
  int v33; // [esp+28h] [ebp-4h]
  int v34; // [esp+30h] [ebp+4h]
  int v35; // [esp+30h] [ebp+4h]

  v3 = a1[106];
  v28 = v3;
  if ( a1[63] )
  {
    if ( !*(_DWORD *)(v3 + 52) )
      sub_378100((int)a1);
    --*(_DWORD *)(v3 + 52);
  }
  if ( *(_DWORD *)(v3 + 16) == -1 )
    return 1;
  v33 = a1[97];
  v29 = 0;
  if ( (int)a1[81] <= 0 )
    return 1;
  for ( i = a1 + 82; ; ++i )
  {
    v4 = *i;
    v32 = a1[*i + 75];
    v5 = (_BYTE *)(*(_DWORD *)(v3 + 4 * *i + 36) + *(_DWORD *)(v3 + 4 * *(_DWORD *)(v32 + 20) + 56));
    v26 = *(_DWORD *)(v32 + 20);
    v31 = *(_WORD **)(a2 + 4 * v29);
    v23 = *i;
    if ( !sub_377FD0(a1, v5) )
    {
      *(_DWORD *)(v3 + 4 * v4 + 36) = 0;
      goto LABEL_27;
    }
    v6 = sub_377FD0(a1, v5 + 1);
    v7 = &v5[v6 + 2];
    v24 = v6;
    v8 = sub_377FD0(a1, v7);
    if ( v8 )
    {
      v7 = (_BYTE *)(*(_DWORD *)(v3 + 4 * v26 + 56) + 20);
      if ( sub_377FD0(a1, v7) )
        break;
    }
LABEL_14:
    if ( v8 >= 1 << *((_BYTE *)a1 + v26 + 203) >> 1 )
    {
      v9 = 4 * v24 + 12;
      if ( v8 <= 1 << *((_BYTE *)a1 + v26 + 219) >> 1 )
        v9 = 4 * v24 + 4;
      *(_DWORD *)(v3 + 4 * v23 + 36) = v9;
    }
    else
    {
      *(_DWORD *)(v3 + 4 * v23 + 36) = 0;
    }
    v10 = v8;
    v11 = v7 + 14;
    v12 = v8 >> 1;
    v34 = v10;
    if ( v12 )
    {
      do
      {
        if ( sub_377FD0(a1, v11) )
          v34 |= v12;
        v12 >>= 1;
      }
      while ( v12 );
      v10 = v34;
    }
    v13 = v10 + 1;
    if ( v24 )
      v13 = -v13;
    *(_DWORD *)(v3 + 4 * v23 + 20) += v13;
    v4 = v23;
LABEL_27:
    *v31 = *(_WORD *)(v3 + 4 * v4 + 20);
    if ( a1[98] )
    {
      v14 = *(_BYTE **)(v3 + 4 * *(_DWORD *)(v32 + 24) + 120);
      v27 = *(_DWORD *)(v32 + 24);
      v15 = 0;
      if ( !sub_377FD0(a1, v14) )
      {
        while ( 1 )
        {
          ++v15;
          if ( !sub_377FD0(a1, v14 + 1) )
            break;
LABEL_34:
          v25 = sub_377FD0(a1, (_BYTE *)(v3 + 184));
          v16 = v14 + 2;
          v17 = sub_377FD0(a1, v16);
          if ( v17 )
          {
            if ( sub_377FD0(a1, v16) )
            {
              v17 *= 2;
              v16 = (_BYTE *)(*(_DWORD *)(v28 + 4 * v27 + 120) + (v15 > *((unsigned __int8 *)a1 + v27 + 235) ? 217 : 189));
              if ( sub_377FD0(a1, v16) )
              {
                while ( 1 )
                {
                  v17 *= 2;
                  if ( v17 == 0x8000 )
                    break;
                  if ( !sub_377FD0(a1, ++v16) )
                    goto LABEL_39;
                }
                *(_DWORD *)(*a1 + 20) = 117;
                (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
                *(_DWORD *)(v28 + 16) = -1;
                return 1;
              }
            }
          }
LABEL_39:
          v18 = v17;
          v19 = v16 + 14;
          v20 = v17 >> 1;
          v35 = v18;
          if ( v20 )
          {
            do
            {
              if ( sub_377FD0(a1, v19) )
                v35 |= v20;
              v20 >>= 1;
            }
            while ( v20 );
            v18 = v35;
          }
          v21 = v18 + 1;
          if ( v25 )
            v21 = -v21;
          v31[*(_DWORD *)(v33 + 4 * v15)] = v21;
          if ( v15 >= a1[98] || (v14 = (_BYTE *)(*(_DWORD *)(v28 + 4 * v27 + 120) + 3 * v15), sub_377FD0(a1, v14)) )
          {
            v3 = v28;
            goto LABEL_49;
          }
          v3 = v28;
        }
        while ( 1 )
        {
          v14 += 3;
          if ( v15 >= a1[98] )
            break;
          ++v15;
          if ( sub_377FD0(a1, v14 + 1) )
            goto LABEL_34;
        }
        *(_DWORD *)(*a1 + 20) = 117;
        (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
        *(_DWORD *)(v3 + 16) = -1;
        return 1;
      }
    }
LABEL_49:
    if ( ++v29 >= a1[81] )
      return 1;
  }
  while ( 1 )
  {
    v8 *= 2;
    if ( v8 == 0x8000 )
      break;
    if ( !sub_377FD0(a1, ++v7) )
      goto LABEL_14;
  }
  *(_DWORD *)(*a1 + 20) = 117;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
  *(_DWORD *)(v3 + 16) = -1;
  return 1;
}
