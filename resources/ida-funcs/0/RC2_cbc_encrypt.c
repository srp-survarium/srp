void __cdecl RC2_cbc_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int length,
        rc2_key_st *ks,
        unsigned __int8 *iv,
        int encrypt)
{
  int v6; // ecx
  unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // edi
  int v9; // eax
  unsigned int v10; // edx
  int v11; // eax
  int v12; // edx
  const unsigned __int8 *v13; // edi
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // edx
  int v18; // ebp
  int v19; // eax
  int v20; // edx
  int v21; // ebp
  int v22; // edx
  int v23; // ebp
  int v24; // edx
  unsigned int v25; // eax
  _BYTE *v26; // esi
  int v27; // edi
  int v28; // ebp
  int v29; // eax
  int v30; // ebp
  int v31; // eax
  int v32; // edx
  int v33; // eax
  int v34; // eax
  int v35; // edx
  int v36; // edx
  unsigned int v37; // eax
  _BYTE *v38; // esi
  unsigned __int8 *v39; // edi
  const unsigned __int8 *v40; // esi
  int v41; // ebx
  int v42; // eax
  bool v43; // sf
  unsigned int v44; // ecx
  int v45; // eax
  int v46; // ecx
  unsigned __int8 *v47; // esi
  int v48; // edx
  int v49; // edx
  int v50; // eax
  int v51; // ecx
  int v52; // ecx
  unsigned int v53; // eax
  _BYTE *v54; // edi
  bool v55; // zf
  int v56; // eax
  int v57; // ecx
  unsigned __int8 *v58; // esi
  int v59; // edx
  unsigned int v60; // ebx
  int v61; // eax
  int v62; // edi
  unsigned int v63; // [esp+10h] [ebp-14h]
  unsigned int v64; // [esp+10h] [ebp-14h]
  unsigned int v65; // [esp+14h] [ebp-10h]
  int v66; // [esp+14h] [ebp-10h]
  int v67; // [esp+14h] [ebp-10h]
  unsigned int v68; // [esp+18h] [ebp-Ch]
  unsigned int d; // [esp+1Ch] [ebp-8h] BYREF
  int v70; // [esp+20h] [ebp-4h]
  unsigned int v71; // [esp+30h] [ebp+Ch]
  unsigned int v72; // [esp+30h] [ebp+Ch]
  int v73; // [esp+3Ch] [ebp+18h]
  int v74; // [esp+3Ch] [ebp+18h]

  if ( encrypt )
  {
    v6 = (iv[3] << 24) | (iv[2] << 16) | *(unsigned __int16 *)iv;
    v7 = out;
    v8 = in;
    v9 = (iv[7] << 24) | (iv[6] << 16) | *((unsigned __int16 *)iv + 2);
    v10 = length - 8;
    v73 = v9;
    if ( (int)(length - 8) >= 0 )
    {
      v65 = length >> 3;
      v71 = v10 - 8 * (length >> 3);
      do
      {
        v11 = *v8;
        v12 = v8[1];
        v13 = v8 + 1;
        v14 = (v12 << 8) | v11;
        v15 = *++v13;
        v16 = (v15 << 16) | v14;
        v17 = *++v13;
        v18 = v13[1];
        v19 = (v17 << 24) | v16;
        v20 = (++v13)[1];
        ++v13;
        v21 = (v20 << 8) | v18;
        v22 = *++v13;
        v23 = (v22 << 16) | v21;
        v24 = v13[1];
        d = v6 ^ v19;
        v8 = v13 + 2;
        v70 = v73 ^ ((v24 << 24) | v23);
        RC2_encrypt(&d, ks);
        v25 = d;
        *v7 = d;
        v26 = v7 + 1;
        *v26++ = BYTE1(v25);
        *v26++ = BYTE2(v25);
        v6 = v25;
        *v26 = HIBYTE(v25);
        v9 = v70;
        *++v26 = v70;
        *++v26 = BYTE1(v9);
        *++v26 = BYTE2(v9);
        ++v26;
        v73 = v9;
        *v26 = HIBYTE(v9);
        v7 = v26 + 1;
        --v65;
      }
      while ( v65 );
      v10 = v71;
    }
    if ( v10 != -8 )
    {
      v27 = (int)&v8[v10 + 8];
      v28 = 0;
      v29 = 0;
      switch ( v10 )
      {
        case 0xFFFFFFF9:
          goto $LN16_20;
        case 0xFFFFFFFA:
          goto $LN17_26;
        case 0xFFFFFFFB:
          goto $LN51_3;
        case 0xFFFFFFFC:
          goto $LN50_8;
        case 0xFFFFFFFD:
          goto $LN49_8;
        case 0xFFFFFFFE:
          goto $LN48_1;
        case 0xFFFFFFFF:
          goto $LN47_2;
        case 0u:
          v30 = *(unsigned __int8 *)--v27;
          v28 = v30 << 24;
$LN47_2:
          v31 = *(unsigned __int8 *)--v27;
          v28 |= v31 << 16;
$LN48_1:
          v32 = *(unsigned __int8 *)--v27;
          v28 |= v32 << 8;
$LN49_8:
          v33 = *(unsigned __int8 *)--v27;
          v28 |= v33;
$LN50_8:
          v34 = *(unsigned __int8 *)--v27;
          v29 = v34 << 24;
$LN51_3:
          v35 = *(unsigned __int8 *)--v27;
          v29 |= v35 << 16;
$LN17_26:
          v36 = *(unsigned __int8 *)--v27;
          v29 |= v36 << 8;
$LN16_20:
          v29 |= *(unsigned __int8 *)(v27 - 1);
          break;
        default:
          break;
      }
      d = v6 ^ v29;
      v70 = v73 ^ v28;
      RC2_encrypt(&d, ks);
      v37 = d;
      *v7 = d;
      v38 = v7 + 1;
      *v38++ = BYTE1(v37);
      *v38 = BYTE2(v37);
      v6 = v37;
      *++v38 = HIBYTE(v37);
      v9 = v70;
      v38[1] = v70;
      v38 += 2;
      *v38++ = BYTE1(v9);
      *v38 = BYTE2(v9);
      v38[1] = HIBYTE(v9);
    }
    *(_DWORD *)iv = v6;
    *((_DWORD *)iv + 1) = v9;
  }
  else
  {
    v39 = out;
    v40 = in;
    v41 = (iv[3] << 24) | (iv[2] << 16) | *(unsigned __int16 *)iv;
    v42 = (iv[7] << 24) | (iv[6] << 16) | *((unsigned __int16 *)iv + 2);
    v43 = (int)(length - 8) < 0;
    v44 = length - 8;
    v74 = v42;
    v72 = length - 8;
    if ( !v43 )
    {
      v68 = (v44 + 8) >> 3;
      v72 = v44 - 8 * v68;
      do
      {
        v45 = *v40;
        v46 = v40[1];
        v47 = (unsigned __int8 *)(v40 + 1);
        v48 = *++v47;
        v63 = (v47[1] << 24) | (v48 << 16) | (v46 << 8) | v45;
        v47 += 2;
        v49 = v47[1];
        d = v63;
        v50 = *v47++;
        v51 = *++v47;
        v70 = (v47[1] << 24) | (v51 << 16) | (v49 << 8) | v50;
        v66 = v70;
        v40 = v47 + 2;
        RC2_decrypt(&d, ks);
        v52 = v70 ^ v74;
        v53 = d ^ v41;
        v54 = v39 + 1;
        *(v54 - 1) = d ^ v41;
        v41 = v63;
        *v54++ = BYTE1(v53);
        *v54++ = BYTE2(v53);
        *v54++ = HIBYTE(v53);
        *v54++ = v52;
        *v54 = BYTE1(v52);
        v42 = v66;
        *++v54 = BYTE2(v52);
        *++v54 = HIBYTE(v52);
        v39 = v54 + 1;
        v55 = v68-- == 1;
        v74 = v66;
      }
      while ( !v55 );
      v44 = v72;
    }
    if ( v44 != -8 )
    {
      v56 = *v40;
      v57 = v40[1];
      v58 = (unsigned __int8 *)(v40 + 1);
      v59 = *++v58;
      v64 = (v58[1] << 24) | (v59 << 16) | (v57 << 8) | v56;
      d = v64;
      v67 = ((v58[4] | (v58[5] << 8)) << 16) | (v58[3] << 8) | v58[2];
      v70 = v67;
      RC2_decrypt(&d, ks);
      v60 = d ^ v41;
      v61 = v70 ^ v74;
      v62 = (int)&v39[v72 + 8];
      switch ( v72 )
      {
        case 0xFFFFFFF9:
          goto $LN1_5;
        case 0xFFFFFFFA:
          goto $LN46_2;
        case 0xFFFFFFFB:
          goto $LN45_2;
        case 0xFFFFFFFC:
          goto $LN44_3;
        case 0xFFFFFFFD:
          goto $LN43_39;
        case 0xFFFFFFFE:
          goto $LN42_29;
        case 0xFFFFFFFF:
          goto $LN41_1;
        case 0u:
          *(_BYTE *)--v62 = HIBYTE(v61);
$LN41_1:
          *(_BYTE *)--v62 = BYTE2(v61);
$LN42_29:
          *(_BYTE *)--v62 = BYTE1(v61);
$LN43_39:
          *(_BYTE *)--v62 = v61;
$LN44_3:
          *(_BYTE *)--v62 = HIBYTE(v60);
$LN45_2:
          *(_BYTE *)--v62 = BYTE2(v60);
$LN46_2:
          *(_BYTE *)--v62 = BYTE1(v60);
$LN1_5:
          *(_BYTE *)(v62 - 1) = v60;
          break;
        default:
          break;
      }
      v42 = v67;
      v41 = v64;
    }
    *(_DWORD *)iv = v41;
    *((_DWORD *)iv + 1) = v42;
  }
}
