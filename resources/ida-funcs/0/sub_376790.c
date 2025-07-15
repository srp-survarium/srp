char __cdecl sub_376790(_DWORD *a1, int a2)
{
  int v3; // edi
  char result; // al
  bool v5; // cc
  int v6; // eax
  unsigned __int8 *v7; // ecx
  int v8; // edx
  int v9; // ebp
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // ebx
  int v17; // edx
  int v18; // edx
  int v19; // ecx
  int v20; // ebx
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  int v24; // edx
  int v25; // eax
  int *v26; // [esp+8h] [ebp-38h]
  int v27; // [esp+Ch] [ebp-34h]
  int v28; // [esp+10h] [ebp-30h]
  _WORD *v29; // [esp+14h] [ebp-2Ch]
  unsigned __int8 *v30; // [esp+18h] [ebp-28h] BYREF
  int v31; // [esp+1Ch] [ebp-24h]
  int v32; // [esp+20h] [ebp-20h]
  int v33; // [esp+24h] [ebp-1Ch]
  _DWORD *v34; // [esp+28h] [ebp-18h]
  int v35; // [esp+2Ch] [ebp-14h]
  int v36; // [esp+30h] [ebp-10h]
  int v37; // [esp+34h] [ebp-Ch]
  int v38; // [esp+38h] [ebp-8h]
  int v39; // [esp+3Ch] [ebp-4h]
  int v40; // [esp+44h] [ebp+4h]

  v3 = a1[106];
  v28 = a1[95];
  if ( !a1[63] || *(_DWORD *)(v3 + 40) || (result = sub_376710(a1)) != 0 )
  {
    if ( !*(_BYTE *)(v3 + 36) )
    {
      v5 = a1[81] <= 0;
      v6 = a1[6];
      v7 = *(unsigned __int8 **)v6;
      v8 = *(_DWORD *)(v6 + 4);
      v9 = *(_DWORD *)(v3 + 8);
      v10 = *(_DWORD *)(v3 + 12);
      v30 = v7;
      v11 = *(_DWORD *)(v3 + 16);
      v31 = v8;
      v12 = *(_DWORD *)(v3 + 20);
      v35 = v11;
      v13 = *(_DWORD *)(v3 + 24);
      v36 = v12;
      v14 = *(_DWORD *)(v3 + 28);
      v37 = v13;
      v15 = *(_DWORD *)(v3 + 32);
      v34 = a1;
      v38 = v14;
      v39 = v15;
      v40 = 0;
      if ( !v5 )
      {
        v26 = a1 + 82;
        do
        {
          v29 = *(_WORD **)(a2 + 4 * v40);
          v27 = *v26;
          v16 = *(_DWORD *)(v3 + 4 * *(_DWORD *)(a1[*v26 + 75] + 20) + 44);
          if ( v10 >= 8 )
            goto LABEL_11;
          if ( !sub_376530(&v30, v9, v10, 0) )
            return 0;
          v10 = v33;
          v9 = v32;
          if ( v33 >= 8 )
          {
LABEL_11:
            v18 = (unsigned __int8)(v9 >> (v10 - 8));
            v19 = *(_DWORD *)(v16 + 4 * v18 + 144);
            if ( v19 )
            {
              v20 = *(unsigned __int8 *)(v18 + v16 + 1168);
              v10 -= v19;
              goto LABEL_16;
            }
            v17 = 9;
          }
          else
          {
            v17 = 1;
          }
          v20 = sub_376650(v9, v17, v10, (int)&v30, v16);
          if ( v20 < 0 )
            return 0;
          v9 = v32;
          v10 = v33;
LABEL_16:
          if ( v20 )
          {
            if ( v10 < v20 )
            {
              if ( !sub_376530(&v30, v9, v10, v20) )
                return 0;
              v9 = v32;
              v10 = v33;
            }
            v10 -= v20;
            v21 = dword_862950[v20];
            v22 = v21 & (v9 >> v10);
            if ( v22 <= dword_86294C[v20] )
              v22 -= v21;
            v20 = v22;
          }
          *(&v36 + v27) += v20;
          ++v26;
          *v29 = *(&v36 + v27) << v28;
          ++v40;
        }
        while ( v40 < a1[81] );
      }
      *(_DWORD *)a1[6] = v30;
      *(_DWORD *)(a1[6] + 4) = v31;
      v23 = v37;
      *(_DWORD *)(v3 + 16) = v35;
      v24 = v38;
      *(_DWORD *)(v3 + 12) = v10;
      *(_DWORD *)(v3 + 20) = v36;
      v25 = v39;
      *(_DWORD *)(v3 + 24) = v23;
      *(_DWORD *)(v3 + 28) = v24;
      *(_DWORD *)(v3 + 8) = v9;
      *(_DWORD *)(v3 + 32) = v25;
    }
    --*(_DWORD *)(v3 + 40);
    return 1;
  }
  return result;
}
