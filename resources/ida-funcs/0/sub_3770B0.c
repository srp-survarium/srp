char __cdecl sub_3770B0(_DWORD *a1, int a2)
{
  _DWORD *v2; // esi
  int v3; // ebx
  char result; // al
  bool v5; // cc
  int v6; // edi
  int v7; // eax
  unsigned __int8 *v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  int *v16; // ebp
  int v17; // esi
  int v18; // edx
  int v19; // edx
  int v20; // ecx
  int v21; // ebx
  int v22; // ebp
  int v23; // esi
  int v24; // esi
  int v25; // edx
  int v26; // ecx
  int v27; // edx
  int v28; // edx
  int v29; // ecx
  int v30; // ebx
  int v31; // ecx
  int v32; // ebx
  int v33; // esi
  int v34; // edx
  int v35; // esi
  int v36; // edx
  int v37; // edx
  int v38; // ecx
  int v39; // ebx
  int v40; // ecx
  int v41; // ebx
  int v42; // esi
  int v43; // ecx
  int v44; // edx
  int v45; // eax
  int v46; // ecx
  int v47; // [esp+8h] [ebp-4Ch]
  int *i; // [esp+Ch] [ebp-48h]
  int v49; // [esp+10h] [ebp-44h]
  int *v50; // [esp+14h] [ebp-40h]
  _WORD *v51; // [esp+18h] [ebp-3Ch]
  int v52; // [esp+1Ch] [ebp-38h]
  int v53; // [esp+20h] [ebp-34h]
  int v54; // [esp+24h] [ebp-30h]
  int v55; // [esp+28h] [ebp-2Ch]
  unsigned __int8 *v56; // [esp+2Ch] [ebp-28h] BYREF
  int v57; // [esp+30h] [ebp-24h]
  int v58; // [esp+34h] [ebp-20h]
  int v59; // [esp+38h] [ebp-1Ch]
  _DWORD *v60; // [esp+3Ch] [ebp-18h]
  int v61; // [esp+40h] [ebp-14h]
  int v62; // [esp+44h] [ebp-10h]
  int v63; // [esp+48h] [ebp-Ch]
  int v64; // [esp+4Ch] [ebp-8h]
  int v65; // [esp+50h] [ebp-4h]

  v2 = a1;
  v3 = a1[106];
  v55 = v3;
  if ( !a1[63] || *(_DWORD *)(v3 + 40) || (result = sub_376710(a1)) != 0 )
  {
    if ( !*(_BYTE *)(v3 + 36) )
    {
      v5 = a1[81] <= 0;
      v6 = *(_DWORD *)(v3 + 12);
      v54 = a1[97];
      v7 = a1[6];
      v8 = *(unsigned __int8 **)v7;
      v9 = *(_DWORD *)(v7 + 4);
      v53 = a1[98];
      v10 = *(_DWORD *)(v3 + 16);
      v56 = v8;
      v11 = *(_DWORD *)(v3 + 20);
      v61 = v10;
      v12 = *(_DWORD *)(v3 + 24);
      v62 = v11;
      v13 = *(_DWORD *)(v3 + 28);
      v63 = v12;
      v14 = *(_DWORD *)(v3 + 32);
      v57 = v9;
      v15 = *(_DWORD *)(v3 + 8);
      v60 = a1;
      v64 = v13;
      v65 = v14;
      v49 = 0;
      if ( !v5 )
      {
        v16 = (int *)(v3 + 136);
        v50 = a1 + 82;
        for ( i = (int *)(v3 + 136); ; v16 = i )
        {
          v17 = *(v16 - 10);
          v51 = *(_WORD **)(a2 + 4 * v49);
          if ( v6 >= 8 )
            goto LABEL_12;
          if ( !sub_376530(&v56, v15, v6, 0) )
            return 0;
          v6 = v59;
          v15 = v58;
          if ( v59 >= 8 )
          {
LABEL_12:
            v19 = (unsigned __int8)(v15 >> (v6 - 8));
            v20 = *(_DWORD *)(v17 + 4 * v19 + 144);
            if ( v20 )
            {
              v21 = *(unsigned __int8 *)(v19 + v17 + 1168);
              v6 -= v20;
              goto LABEL_17;
            }
            v18 = 9;
          }
          else
          {
            v18 = 1;
          }
          v21 = sub_376650(v15, v18, v6, (int)&v56, v17);
          if ( v21 < 0 )
            return 0;
          v15 = v58;
          v6 = v59;
LABEL_17:
          v22 = *v16;
          v23 = 1;
          v52 = i[10];
          if ( v52 )
          {
            if ( v21 )
            {
              if ( v6 < v21 )
              {
                if ( !sub_376530(&v56, v15, v6, v21) )
                  return 0;
                v15 = v58;
                v6 = v59;
              }
              v24 = dword_862950[v21];
              v6 -= v21;
              v25 = v24 & (v15 >> v6);
              if ( v25 <= dword_86294C[v21] )
                v25 -= v24;
              v23 = 1;
              v21 = v25;
            }
            v26 = *v50;
            *(&v62 + v26) += v21;
            *v51 = *(&v62 + v26);
            if ( v52 > 1 )
            {
              while ( 1 )
              {
                if ( v6 < 8 )
                {
                  if ( !sub_376530(&v56, v15, v6, 0) )
                    return 0;
                  v6 = v59;
                  v15 = v58;
                  if ( v59 < 8 )
                    break;
                }
                v28 = (unsigned __int8)(v15 >> (v6 - 8));
                v29 = *(_DWORD *)(v22 + 4 * v28 + 144);
                if ( !v29 )
                {
                  v27 = 9;
                  goto LABEL_33;
                }
                v30 = *(unsigned __int8 *)(v28 + v22 + 1168);
                v6 -= v29;
LABEL_35:
                v31 = v30 >> 4;
                v32 = v30 & 0xF;
                if ( v32 )
                {
                  v47 = v31 + v23;
                  if ( v6 < v32 )
                  {
                    if ( !sub_376530(&v56, v15, v6, v32) )
                      return 0;
                    v15 = v58;
                    v6 = v59;
                  }
                  v33 = dword_862950[v32];
                  v6 -= v32;
                  v34 = v33 & (v15 >> v6);
                  if ( v34 <= dword_86294C[v32] )
                    LOWORD(v34) = v34 - v33;
                  v51[*(_DWORD *)(v54 + 4 * v47)] = v34;
                  v35 = v47;
                }
                else
                {
                  if ( v31 != 15 )
                    goto LABEL_69;
                  v35 = v23 + 15;
                }
                v23 = v35 + 1;
                if ( v23 >= v52 )
                  goto LABEL_51;
              }
              v27 = 1;
LABEL_33:
              v30 = sub_376650(v15, v27, v6, (int)&v56, v22);
              if ( v30 < 0 )
                return 0;
              v15 = v58;
              v6 = v59;
              goto LABEL_35;
            }
          }
          else if ( v21 )
          {
            if ( v6 < v21 )
            {
              if ( !sub_376530(&v56, v15, v6, v21) )
                return 0;
              v15 = v58;
              v6 = v59;
            }
            v6 -= v21;
          }
LABEL_51:
          if ( v23 <= v53 )
          {
            while ( 1 )
            {
              if ( v6 < 8 )
              {
                if ( !sub_376530(&v56, v15, v6, 0) )
                  return 0;
                v6 = v59;
                v15 = v58;
                if ( v59 < 8 )
                  break;
              }
              v37 = (unsigned __int8)(v15 >> (v6 - 8));
              v38 = *(_DWORD *)(v22 + 4 * v37 + 144);
              if ( !v38 )
              {
                v36 = 9;
                goto LABEL_59;
              }
              v39 = *(unsigned __int8 *)(v37 + v22 + 1168);
              v6 -= v38;
LABEL_61:
              v40 = v39 >> 4;
              v41 = v39 & 0xF;
              if ( v41 )
              {
                v42 = v40 + v23;
                if ( v6 < v41 )
                {
                  if ( !sub_376530(&v56, v15, v6, v41) )
                    return 0;
                  v15 = v58;
                  v6 = v59;
                }
                v6 -= v41;
              }
              else
              {
                if ( v40 != 15 )
                  goto LABEL_69;
                v42 = v23 + 15;
              }
              v23 = v42 + 1;
              if ( v23 > v53 )
                goto LABEL_69;
            }
            v36 = 1;
LABEL_59:
            v39 = sub_376650(v15, v36, v6, (int)&v56, v22);
            if ( v39 < 0 )
              return 0;
            v15 = v58;
            v6 = v59;
            goto LABEL_61;
          }
LABEL_69:
          ++i;
          ++v50;
          if ( ++v49 >= a1[81] )
          {
            v3 = v55;
            v2 = a1;
            break;
          }
        }
      }
      *(_DWORD *)v2[6] = v56;
      *(_DWORD *)(v2[6] + 4) = v57;
      v43 = v62;
      v44 = v63;
      *(_DWORD *)(v3 + 8) = v15;
      *(_DWORD *)(v3 + 16) = v61;
      v45 = v64;
      *(_DWORD *)(v3 + 20) = v43;
      v46 = v65;
      *(_DWORD *)(v3 + 24) = v44;
      *(_DWORD *)(v3 + 28) = v45;
      *(_DWORD *)(v3 + 12) = v6;
      *(_DWORD *)(v3 + 32) = v46;
    }
    --*(_DWORD *)(v3 + 40);
    return 1;
  }
  return result;
}
