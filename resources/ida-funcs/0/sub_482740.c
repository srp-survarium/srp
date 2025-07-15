int __cdecl sub_482740(_DWORD *a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  unsigned int v4; // esi
  unsigned int v5; // ecx
  int v6; // eax
  _DWORD *v8; // esi
  int v9; // eax
  unsigned __int16 *v10; // eax
  __int16 *v11; // ecx
  __int16 *v12; // eax
  int v13; // esi
  int v14; // edi
  int v15; // ebp
  int v16; // ecx
  int v17; // eax
  int v18; // ebx
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // ebx
  int v25; // edx
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // eax
  int v31; // ebx
  int v32; // eax
  int v33; // eax
  int v34; // ecx
  int v35; // edx
  int v36; // eax
  int v37; // edi
  int v38; // eax
  int v39; // eax
  int v40; // ecx
  int v41; // edx
  int v42; // eax
  int v43; // edi
  int v44; // eax
  int v45; // eax
  bool v46; // cc
  int v47; // [esp-18h] [ebp-128h]
  char v48; // [esp+6h] [ebp-10Ah]
  char v49; // [esp+7h] [ebp-109h]
  unsigned __int8 *src; // [esp+Ch] [ebp-104h]
  _DWORD *v51; // [esp+10h] [ebp-100h]
  int v52; // [esp+14h] [ebp-FCh]
  int v53; // [esp+18h] [ebp-F8h]
  int v54; // [esp+1Ch] [ebp-F4h]
  int v55; // [esp+20h] [ebp-F0h]
  _DWORD *v56; // [esp+24h] [ebp-ECh]
  int v57; // [esp+28h] [ebp-E8h]
  int v58; // [esp+2Ch] [ebp-E4h]
  int v59; // [esp+30h] [ebp-E0h]
  int v60; // [esp+34h] [ebp-DCh]
  unsigned int v61; // [esp+38h] [ebp-D8h]
  int v62; // [esp+3Ch] [ebp-D4h]
  int v63; // [esp+40h] [ebp-D0h]
  __int16 *v64; // [esp+44h] [ebp-CCh]
  int v65; // [esp+48h] [ebp-C8h]
  __int16 *v66; // [esp+4Ch] [ebp-C4h]
  int v67; // [esp+50h] [ebp-C0h]
  int v68; // [esp+54h] [ebp-BCh]
  int v69; // [esp+58h] [ebp-B8h]
  int v70; // [esp+5Ch] [ebp-B4h]
  int v71; // [esp+60h] [ebp-B0h]
  unsigned int v72; // [esp+64h] [ebp-ACh]
  int v73; // [esp+68h] [ebp-A8h]
  int v74; // [esp+6Ch] [ebp-A4h]
  int v75; // [esp+70h] [ebp-A0h]
  int v76; // [esp+74h] [ebp-9Ch]
  int v77; // [esp+78h] [ebp-98h]
  unsigned int v78; // [esp+7Ch] [ebp-94h]
  void (__cdecl *v79)(_DWORD *, int, unsigned __int8 *, int, int); // [esp+84h] [ebp-8Ch]
  unsigned __int8 dst[2]; // [esp+8Ch] [ebp-84h] BYREF
  __int16 v81; // [esp+8Eh] [ebp-82h]
  __int16 v82; // [esp+90h] [ebp-80h]
  __int16 v83; // [esp+9Ch] [ebp-74h]
  __int16 v84; // [esp+9Eh] [ebp-72h]
  __int16 v85; // [esp+ACh] [ebp-64h]

  v75 = a1[102];
  v78 = a1[72] - 1;
  while ( a1[31] <= a1[33] )
  {
    v2 = a1[104];
    if ( *(_BYTE *)(v2 + 17)
      || a1[31] == a1[33] && __PAIR64__(a1[32], a1[92]) >= __PAIR64__(a1[34], 1) && a1[32] != a1[34] + (a1[92] == 0) )
    {
      break;
    }
    if ( !(*(int (__cdecl **)(_DWORD *))v2)(a1) )
      return 0;
  }
  v3 = a1[49];
  v67 = 0;
  v58 = v3;
  if ( (int)a1[9] > 0 )
  {
    v69 = 0;
    v56 = (_DWORD *)(v75 + 72);
    do
    {
      if ( *(_BYTE *)(v3 + 52) )
      {
        v4 = a1[34];
        v5 = *(_DWORD *)(v3 + 12);
        if ( v4 >= v78 )
        {
          v6 = *(_DWORD *)(v3 + 32) % v5;
          v53 = v6;
          if ( !v6 )
          {
            v6 = *(_DWORD *)(v3 + 12);
            v53 = v6;
          }
          v48 = 1;
        }
        else
        {
          v53 = *(_DWORD *)(v3 + 12);
          v6 = 2 * v5;
          v48 = 0;
        }
        if ( v4 )
        {
          v47 = v5 * (v4 - 1);
          v8 = v56;
          v9 = (*(int (__cdecl **)(_DWORD *, _DWORD, int, unsigned int, _DWORD))(a1[1] + 32))(a1, *v56, v47, v5 + v6, 0)
             + 4 * *(_DWORD *)(v3 + 12);
          v49 = 0;
        }
        else
        {
          v8 = v56;
          v9 = (*(int (__cdecl **)(_DWORD *, _DWORD, _DWORD, int, _DWORD))(a1[1] + 32))(a1, *v56, 0, v6, 0);
          v49 = 1;
        }
        v70 = v9;
        v51 = (_DWORD *)(v69 + *(_DWORD *)(v75 + 112));
        v10 = *(unsigned __int16 **)(v3 + 80);
        v52 = *v10;
        v73 = v10[1];
        v77 = v10[8];
        v76 = v10[16];
        v74 = v10[9];
        v71 = v10[2];
        v79 = *(void (__cdecl **)(_DWORD *, int, unsigned __int8 *, int, int))((char *)v8 + -72 - v75 + a1[107] + 4);
        v63 = *(_DWORD *)(a2 + 4 * v67);
        v65 = 0;
        if ( v53 > 0 )
        {
          do
          {
            src = *(unsigned __int8 **)(v70 + 4 * v65);
            if ( !v49 || (v11 = *(__int16 **)(v70 + 4 * v65), v65) )
              v11 = *(__int16 **)(v70 + 4 * v65 - 4);
            if ( !v48 || (v12 = *(__int16 **)(v70 + 4 * v65), v65 != v53 - 1) )
              v12 = *(__int16 **)(v70 + 4 * v65 + 4);
            v13 = *(__int16 *)src;
            v14 = *v11;
            v15 = *v12;
            v60 = v14;
            v54 = v14;
            v57 = v13;
            v68 = v13;
            v62 = v15;
            v55 = v15;
            v59 = 0;
            v72 = *(_DWORD *)(v3 + 28) - 1;
            v61 = 0;
            v64 = v12 + 64;
            v66 = v11 + 64;
            do
            {
              jcopy_block_row(src, dst, 1);
              if ( v61 < v72 )
              {
                v13 = *((__int16 *)src + 64);
                v60 = *v66;
                v62 = *v64;
              }
              v16 = v51[1];
              if ( v16 && !v81 )
              {
                v17 = v73 << 7;
                v18 = v73 << 8;
                v19 = 36 * v52 * (v68 - v13);
                if ( ((18 * v52 * (v68 - v13)) & 0x40000000) != 0 )
                {
                  v21 = (v17 - v19) / v18;
                  if ( v16 > 0 && v21 >= 1 << v16 )
                    v21 = (1 << v16) - 1;
                  v20 = -v21;
                }
                else
                {
                  v20 = (v19 + v17) / v18;
                  if ( v16 > 0 && v20 >= 1 << v16 )
                    v20 = (1 << v16) - 1;
                }
                v3 = v58;
                v81 = v20;
              }
              v22 = v51[2];
              if ( v22 && !v83 )
              {
                v23 = v77 << 7;
                v24 = v77 << 8;
                v25 = 36 * v52 * (v54 - v55);
                if ( ((18 * v52 * (v54 - v55)) & 0x40000000) != 0 )
                {
                  v27 = (v23 - v25) / v24;
                  if ( v22 > 0 && v27 >= 1 << v22 )
                    v27 = (1 << v22) - 1;
                  v26 = -v27;
                }
                else
                {
                  v26 = (v25 + v23) / v24;
                  if ( v22 > 0 && v26 >= 1 << v22 )
                    v26 = (1 << v22) - 1;
                }
                v3 = v58;
                v83 = v26;
              }
              v28 = v51[3];
              if ( v28 && !v85 )
              {
                v29 = 9 * v52 * (v54 + v55 - 2 * v57);
                v30 = v76 << 7;
                v31 = v76 << 8;
                if ( v29 < 0 )
                {
                  v33 = (v30 - v29) / v31;
                  if ( v28 > 0 && v33 >= 1 << v28 )
                    v33 = (1 << v28) - 1;
                  v32 = -v33;
                }
                else
                {
                  v32 = (v29 + v30) / v31;
                  if ( v28 > 0 && v32 >= 1 << v28 )
                    v32 = (1 << v28) - 1;
                }
                v3 = v58;
                v85 = v32;
              }
              v34 = v51[4];
              if ( v34 && !v84 )
              {
                v35 = 5 * v52 * (v14 + v62 - v15 - v60);
                v36 = v74 << 7;
                v37 = v74 << 8;
                if ( v35 < 0 )
                {
                  v39 = (v36 - v35) / v37;
                  if ( v34 > 0 && v39 >= 1 << v34 )
                    v39 = (1 << v34) - 1;
                  v38 = -v39;
                }
                else
                {
                  v38 = (v35 + v36) / v37;
                  if ( v34 > 0 && v38 >= 1 << v34 )
                    v38 = (1 << v34) - 1;
                }
                v84 = v38;
              }
              v40 = v51[5];
              if ( v40 && !v82 )
              {
                v41 = 9 * v52 * (v68 + v13 - 2 * v57);
                v42 = v71 << 7;
                v43 = v71 << 8;
                if ( v41 < 0 )
                {
                  v45 = (v42 - v41) / v43;
                  if ( v40 > 0 && v45 >= 1 << v40 )
                    v45 = (1 << v40) - 1;
                  v44 = -v45;
                }
                else
                {
                  v44 = (v41 + v42) / v43;
                  if ( v40 > 0 && v44 >= 1 << v40 )
                    v44 = (1 << v40) - 1;
                }
                v82 = v44;
              }
              v79(a1, v3, dst, v63, v59);
              v15 = v55;
              v14 = v54;
              v55 = v62;
              src += 128;
              v66 += 64;
              v64 += 64;
              v54 = v60;
              v59 += *(_DWORD *)(v3 + 36);
              v68 = v57;
              v57 = v13;
              ++v61;
            }
            while ( v61 <= v72 );
            v46 = v65 + 1 < v53;
            v63 += 4 * *(_DWORD *)(v3 + 40);
            ++v65;
          }
          while ( v46 );
        }
      }
      v69 += 24;
      ++v56;
      v3 += 88;
      v46 = ++v67 < a1[9];
      v58 = v3;
    }
    while ( v46 );
  }
  return 4 - (++a1[34] < a1[72]);
}
