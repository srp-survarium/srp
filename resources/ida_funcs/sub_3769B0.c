char __cdecl sub_3769B0(_DWORD *a1, int *a2)
{
  _DWORD *v2; // esi
  int v3; // ebx
  char result; // al
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  unsigned __int8 *v8; // edi
  int v9; // eax
  int v10; // ebp
  int v11; // edi
  int v12; // eax
  int v13; // esi
  int v14; // edx
  int v15; // edx
  int v16; // ecx
  int v17; // ebx
  int v18; // esi
  int v19; // ebx
  int v20; // ebp
  int v21; // esi
  int v22; // edx
  int v23; // ebx
  int v24; // [esp+8h] [ebp-30h]
  int v25; // [esp+Ch] [ebp-2Ch]
  int v26; // [esp+10h] [ebp-28h]
  int v27; // [esp+14h] [ebp-24h]
  int v28; // [esp+18h] [ebp-20h]
  int v29; // [esp+1Ch] [ebp-1Ch]
  int v30; // [esp+20h] [ebp-18h]
  unsigned __int8 *v31; // [esp+24h] [ebp-14h] BYREF
  int v32; // [esp+28h] [ebp-10h]
  int v33; // [esp+2Ch] [ebp-Ch]
  int v34; // [esp+30h] [ebp-8h]
  _DWORD *v35; // [esp+34h] [ebp-4h]

  v2 = a1;
  v3 = a1[106];
  v26 = v3;
  if ( a1[63] )
  {
    if ( !*(_DWORD *)(v3 + 40) )
    {
      result = sub_376710(a1);
      if ( !result )
        return result;
    }
  }
  if ( *(_BYTE *)(v3 + 36) )
    goto LABEL_37;
  v5 = a1[93];
  v28 = a1[97];
  v6 = *(_DWORD *)(v3 + 16);
  v30 = v5;
  v27 = a1[95];
  v24 = v6;
  if ( v6 )
  {
    --*(_DWORD *)(v3 + 40);
    *(_DWORD *)(v3 + 16) = v6 - 1;
    return 1;
  }
  v7 = a1[6];
  v8 = *(unsigned __int8 **)v7;
  v9 = *(_DWORD *)(v7 + 4);
  v29 = *a2;
  v25 = *(_DWORD *)(v3 + 60);
  v10 = a1[92];
  v31 = v8;
  v11 = *(_DWORD *)(v3 + 12);
  v32 = v9;
  v12 = *(_DWORD *)(v3 + 8);
  v35 = a1;
  if ( v10 > v5 )
    goto LABEL_36;
  while ( 1 )
  {
    if ( v11 >= 8 )
      goto LABEL_12;
    if ( !sub_376530(&v31, v12, v11, 0) )
      return 0;
    v11 = v34;
    v12 = v33;
    if ( v34 >= 8 )
    {
LABEL_12:
      v13 = v25;
      v15 = (unsigned __int8)(v12 >> (v11 - 8));
      v16 = *(_DWORD *)(v25 + 4 * v15 + 144);
      if ( v16 )
      {
        v17 = *(unsigned __int8 *)(v15 + v25 + 1168);
        v11 -= v16;
        goto LABEL_17;
      }
      v14 = 9;
    }
    else
    {
      v13 = v25;
      v14 = 1;
    }
    v17 = sub_376650(v12, v14, v11, (int)&v31, v13);
    if ( v17 < 0 )
      return 0;
    v12 = v33;
    v11 = v34;
LABEL_17:
    v18 = v17 >> 4;
    v19 = v17 & 0xF;
    if ( v19 )
    {
      v20 = v18 + v10;
      if ( v11 < v19 )
      {
        if ( !sub_376530(&v31, v12, v11, v19) )
          return 0;
        v12 = v33;
        v11 = v34;
      }
      v21 = dword_862950[v19];
      v11 -= v19;
      v22 = v21 & (v12 >> v11);
      if ( v22 <= dword_86294C[v19] )
        v22 -= v21;
      *(_WORD *)(v29 + 2 * *(_DWORD *)(v28 + 4 * v20)) = v22 << v27;
      goto LABEL_26;
    }
    if ( v18 != 15 )
      break;
    v20 = v10 + 15;
LABEL_26:
    v10 = v20 + 1;
    if ( v10 > v30 )
      goto LABEL_35;
  }
  v23 = 1 << v18;
  if ( v18 )
  {
    if ( v11 < v18 )
    {
      if ( !sub_376530(&v31, v12, v11, v18) )
        return 0;
      v12 = v33;
      v11 = v34;
    }
    v11 -= v18;
    v23 += dword_862950[v18] & (v12 >> v11);
  }
  v24 = v23 - 1;
LABEL_35:
  v6 = v24;
  v2 = a1;
  v3 = v26;
LABEL_36:
  *(_DWORD *)v2[6] = v31;
  *(_DWORD *)(v2[6] + 4) = v32;
  *(_DWORD *)(v3 + 8) = v12;
  *(_DWORD *)(v3 + 12) = v11;
  *(_DWORD *)(v3 + 16) = v6;
LABEL_37:
  --*(_DWORD *)(v3 + 40);
  return 1;
}
