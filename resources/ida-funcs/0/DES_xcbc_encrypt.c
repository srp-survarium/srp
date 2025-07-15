void __cdecl DES_xcbc_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int length,
        DES_ks *schedule,
        unsigned __int8 (*ivec)[8],
        unsigned __int8 (*inw)[8],
        unsigned __int8 (*outw)[8],
        int enc)
{
  int v8; // ecx
  int v9; // edx
  const unsigned __int8 *v10; // edi
  int v11; // eax
  int v12; // ecx
  int v13; // ebp
  unsigned __int8 *v14; // esi
  int v15; // edx
  int v16; // ebx
  const unsigned __int8 *v17; // edi
  int v18; // edx
  int v19; // ebx
  int v20; // edx
  int v21; // ebx
  int v22; // edx
  int v23; // ebx
  int v24; // ebp
  int v25; // ebx
  int v26; // ebp
  int v27; // ebx
  int v28; // ebp
  _BYTE *v29; // esi
  int v30; // edi
  int v31; // ebx
  int v32; // edx
  int v33; // ebx
  int v34; // edx
  int v35; // edx
  int v36; // edx
  int v37; // edx
  int v38; // ebp
  int v39; // ebp
  _BYTE *v40; // esi
  unsigned __int8 *v41; // edi
  int v42; // ebx
  int v43; // edx
  const unsigned __int8 *v44; // esi
  int v45; // eax
  int v46; // ebp
  int v47; // eax
  unsigned __int8 *v48; // esi
  int v49; // edx
  int v50; // ebp
  int v51; // eax
  int v52; // ebp
  int v53; // eax
  int v54; // edx
  int v55; // ecx
  int v56; // edx
  int v57; // ecx
  int v58; // eax
  _BYTE *v59; // edi
  bool v60; // zf
  int v61; // ebp
  int v62; // edx
  unsigned __int8 *v63; // esi
  int v64; // eax
  int v65; // ebp
  int v66; // ebx
  int v67; // eax
  int v68; // edi
  int v69; // [esp+10h] [ebp-1Ch]
  int v70; // [esp+14h] [ebp-18h]
  int v71; // [esp+18h] [ebp-14h]
  unsigned int v72; // [esp+20h] [ebp-Ch]
  int v73; // [esp+24h] [ebp-8h] BYREF
  int v74; // [esp+28h] [ebp-4h]
  int v75; // [esp+38h] [ebp+Ch]
  unsigned int v76; // [esp+38h] [ebp+Ch]
  unsigned int v77; // [esp+44h] [ebp+18h]
  int v78; // [esp+44h] [ebp+18h]
  int v79; // [esp+48h] [ebp+1Ch]
  int v80; // [esp+4Ch] [ebp+20h]
  int v81; // [esp+4Ch] [ebp+20h]

  v70 = ((*inw)[3] << 24) | ((*inw)[2] << 16) | *(unsigned __int16 *)inw;
  v71 = (*(unsigned __int16 *)&(*inw)[6] << 16) | ((*inw)[5] << 8) | (*inw)[4];
  v8 = ((*outw)[3] << 24) | ((*outw)[2] << 16) | ((*outw)[1] << 8) | (*outw)[0];
  v9 = *(_DWORD *)&(*outw)[4];
  v79 = v8;
  v69 = v9;
  if ( enc )
  {
    v10 = in;
    v11 = ((*ivec)[3] << 24) | ((*ivec)[2] << 16) | *(unsigned __int16 *)ivec;
    v12 = *(_DWORD *)&(*ivec)[4];
    v13 = length - 8;
    v14 = out;
    if ( (int)(length - 8) >= 0 )
    {
      v77 = length >> 3;
      v75 = v13 - 8 * (length >> 3);
      do
      {
        v15 = *v10;
        v16 = v10[1];
        v17 = v10 + 1;
        v18 = (v16 << 8) | v15;
        v19 = *++v17;
        v20 = (v19 << 16) | v18;
        v21 = *++v17;
        v22 = (v21 << 24) | v20;
        v23 = *++v17;
        v24 = *++v17;
        v25 = (v24 << 8) | v23;
        v26 = *++v17;
        v27 = (v26 << 16) | v25;
        v28 = v17[1];
        v10 = v17 + 2;
        v73 = v70 ^ v11 ^ v22;
        v74 = v71 ^ v12 ^ ((v28 << 24) | v27);
        DES_encrypt1(&v73, schedule, 1);
        v11 = v79 ^ v73;
        v29 = v14 + 1;
        *(v29++ - 1) = v79 ^ v73;
        *(v29 - 1) = BYTE1(v11);
        *v29 = BYTE2(v11);
        v12 = v69 ^ v74;
        *++v29 = HIBYTE(v11);
        *++v29 = v12;
        *++v29 = BYTE1(v12);
        *++v29 = BYTE2(v12);
        *++v29 = HIBYTE(v12);
        v14 = v29 + 1;
        --v77;
      }
      while ( v77 );
      v13 = v75;
    }
    if ( v13 != -8 )
    {
      v30 = (int)&v10[v13 + 8];
      v31 = 0;
      v32 = 0;
      switch ( v13 )
      {
        case -7:
          goto $LN16_27;
        case -6:
          goto $LN17_35;
        case -5:
          goto $LN50_14;
        case -4:
          goto $LN49_13;
        case -3:
          goto $LN48_6;
        case -2:
          goto $LN47_7;
        case -1:
          goto $LN46_8;
        case 0:
          v33 = *(unsigned __int8 *)--v30;
          v31 = v33 << 24;
$LN46_8:
          v34 = *(unsigned __int8 *)--v30;
          v31 |= v34 << 16;
$LN47_7:
          v35 = *(unsigned __int8 *)--v30;
          v31 |= v35 << 8;
$LN48_6:
          v36 = *(unsigned __int8 *)--v30;
          v31 |= v36;
$LN49_13:
          v37 = *(unsigned __int8 *)--v30;
          v32 = v37 << 24;
$LN50_14:
          v38 = *(unsigned __int8 *)--v30;
          v32 |= v38 << 16;
$LN17_35:
          v39 = *(unsigned __int8 *)--v30;
          v32 |= v39 << 8;
$LN16_27:
          v32 |= *(unsigned __int8 *)(v30 - 1);
          break;
        default:
          break;
      }
      v73 = v70 ^ v11 ^ v32;
      v74 = v71 ^ v12 ^ v31;
      DES_encrypt1(&v73, schedule, 1);
      v11 = v79 ^ v73;
      v40 = v14 + 1;
      *(_WORD *)(v40++ - 1) = v79 ^ v73;
      *v40 = BYTE2(v11);
      v12 = v69 ^ v74;
      *++v40 = HIBYTE(v11);
      *++v40 = v12;
      *++v40 = BYTE1(v12);
      *++v40 = BYTE2(v12);
      v40[1] = HIBYTE(v12);
    }
    *(_DWORD *)ivec = v11;
    *(_DWORD *)&(*ivec)[4] = v12;
  }
  else
  {
    v41 = out;
    v42 = ((*ivec)[3] << 24) | ((*ivec)[2] << 16) | ((*ivec)[1] << 8) | (*ivec)[0];
    v43 = *(_DWORD *)&(*ivec)[4];
    v44 = in;
    v45 = length - 8;
    v78 = v43;
    v76 = v45;
    if ( v45 > 0 )
    {
      v72 = ((unsigned int)(v45 - 1) >> 3) + 1;
      v76 = v45 - 8 * v72;
      do
      {
        v46 = *v44;
        v47 = v44[1];
        v48 = (unsigned __int8 *)(v44 + 1);
        v49 = v48[1];
        v50 = (v47 << 8) | v46;
        v51 = (++v48)[1];
        ++v48;
        v52 = (v51 << 24) | (v49 << 16) | v50;
        v53 = v48[1];
        v48 += 2;
        v54 = v8 ^ v52;
        v55 = *v48;
        v73 = v54;
        v56 = *++v48;
        v80 = (v48[1] << 24) | (v56 << 16) | (v55 << 8) | v53;
        v74 = v69 ^ v80;
        v44 = v48 + 2;
        DES_encrypt1(&v73, schedule, 0);
        v57 = v71 ^ v74 ^ v78;
        v58 = v70 ^ v73 ^ v42;
        v59 = v41 + 1;
        *(_WORD *)(v59++ - 1) = v58;
        *v59++ = BYTE2(v58);
        *v59 = HIBYTE(v58);
        v59[1] = v57;
        v59 += 2;
        *v59++ = BYTE1(v57);
        *v59++ = BYTE2(v57);
        *v59 = HIBYTE(v57);
        v8 = v79;
        v41 = v59 + 1;
        v60 = v72-- == 1;
        v42 = v52;
        v78 = v80;
      }
      while ( !v60 );
      v43 = v80;
      v45 = v76;
    }
    if ( v45 != -8 )
    {
      v61 = *v44;
      v62 = v44[1];
      v63 = (unsigned __int8 *)(v44 + 1);
      v64 = *++v63;
      v65 = (v63[1] << 24) | (v64 << 16) | (v62 << 8) | v61;
      v73 = v8 ^ v65;
      v81 = ((v63[4] | (v63[5] << 8)) << 16) | (v63[3] << 8) | v63[2];
      v74 = v69 ^ v81;
      DES_encrypt1(&v73, schedule, 0);
      v66 = v70 ^ v73 ^ v42;
      v67 = v71 ^ v74 ^ v78;
      v68 = (int)&v41[v76 + 8];
      switch ( v76 )
      {
        case 0xFFFFFFF9:
          goto $LN1_11;
        case 0xFFFFFFFA:
          goto $LN45_5;
        case 0xFFFFFFFB:
          goto $LN44_8;
        case 0xFFFFFFFC:
          goto $LN43_10;
        case 0xFFFFFFFD:
          goto $LN42_8;
        case 0xFFFFFFFE:
          goto $LN41_5;
        case 0xFFFFFFFF:
          goto $LN40_5;
        case 0u:
          *(_BYTE *)--v68 = HIBYTE(v67);
$LN40_5:
          *(_BYTE *)--v68 = BYTE2(v67);
$LN41_5:
          *(_BYTE *)--v68 = BYTE1(v67);
$LN42_8:
          *(_BYTE *)--v68 = v67;
$LN43_10:
          *(_BYTE *)--v68 = HIBYTE(v66);
$LN44_8:
          *(_BYTE *)--v68 = BYTE2(v66);
$LN45_5:
          *(_BYTE *)--v68 = BYTE1(v66);
$LN1_11:
          *(_BYTE *)(v68 - 1) = v66;
          break;
        default:
          break;
      }
      v43 = v81;
      v42 = v65;
    }
    *(_DWORD *)ivec = v42;
    *(_DWORD *)&(*ivec)[4] = v43;
  }
}
