void __cdecl idea_cbc_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        unsigned int length,
        idea_key_st *ks,
        unsigned __int8 *iv,
        int encrypt)
{
  unsigned __int8 *v6; // esi
  const unsigned __int8 *v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  const unsigned __int8 *v13; // edi
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // ebx
  int v21; // ecx
  int v22; // ebx
  int v23; // ecx
  int v24; // ebx
  _BYTE *v25; // esi
  bool v26; // zf
  int v27; // edi
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  int v33; // ebx
  int v34; // ebx
  _BYTE *v35; // esi
  unsigned __int8 *v36; // ebp
  unsigned __int8 *v37; // edi
  const unsigned __int8 *v38; // esi
  unsigned int v39; // ebx
  unsigned __int8 *v40; // ebp
  int v41; // ecx
  int v42; // ebp
  int v43; // eax
  const unsigned __int8 *v44; // esi
  int v45; // ecx
  int v46; // edx
  int v47; // ebx
  int v48; // ebp
  int v49; // eax
  int v50; // ebp
  int v51; // ecx
  unsigned int v52; // ebp
  int v53; // ebx
  unsigned int v54; // eax
  int v55; // ecx
  _BYTE *v56; // edi
  int v57; // eax
  int v58; // ecx
  const unsigned __int8 *v59; // esi
  int v60; // edx
  unsigned int v61; // ebx
  int v62; // eax
  int v63; // edi
  _BYTE *v64; // ebp
  _BYTE *v65; // ebp
  int v66; // [esp+10h] [ebp-10h]
  int v67; // [esp+10h] [ebp-10h]
  unsigned int v68; // [esp+14h] [ebp-Ch]
  unsigned int v69; // [esp+14h] [ebp-Ch]
  unsigned int d; // [esp+18h] [ebp-8h] BYREF
  int v71; // [esp+1Ch] [ebp-4h]
  unsigned int v72; // [esp+2Ch] [ebp+Ch]
  int v73; // [esp+2Ch] [ebp+Ch]
  unsigned int v74; // [esp+2Ch] [ebp+Ch]
  unsigned int v75; // [esp+2Ch] [ebp+Ch]
  unsigned int v76; // [esp+38h] [ebp+18h]
  unsigned int v77; // [esp+38h] [ebp+18h]

  if ( encrypt )
  {
    v6 = out;
    v7 = in;
    v8 = _byteswap_ulong(*(_DWORD *)iv);
    v9 = _byteswap_ulong(*((_DWORD *)iv + 1));
    v10 = length - 8;
    v76 = v9;
    if ( (int)(length - 8) >= 0 )
    {
      v72 = length >> 3;
      v66 = v10 - 8 * v72;
      do
      {
        v11 = *v7;
        v12 = v7[1];
        v13 = v7 + 1;
        v14 = (v12 << 16) | (v11 << 24);
        v15 = *++v13;
        v16 = (v15 << 8) | v14;
        v17 = *++v13;
        v18 = v17 | v16;
        v19 = *++v13;
        v20 = *++v13;
        v21 = (v20 << 16) | (v19 << 24);
        v22 = *++v13;
        v23 = (v22 << 8) | v21;
        v24 = v13[1];
        d = v8 ^ v18;
        v7 = v13 + 2;
        v71 = v76 ^ (v24 | v23);
        idea_encrypt(&d, ks);
        v8 = d;
        v25 = v6 + 1;
        *(v25++ - 1) = HIBYTE(d);
        *(v25 - 1) = BYTE2(v8);
        v9 = v71;
        *v25++ = BYTE1(v8);
        *v25++ = v8;
        *v25++ = HIBYTE(v9);
        *v25++ = BYTE2(v9);
        *v25++ = BYTE1(v9);
        *v25 = v9;
        v6 = v25 + 1;
        v26 = v72-- == 1;
        v76 = v9;
      }
      while ( !v26 );
      v10 = v66;
    }
    if ( v10 != -8 )
    {
      v27 = (int)&v7[v10 + 8];
      v28 = 0;
      v73 = 0;
      switch ( v10 )
      {
        case -7:
          goto $LN52_1;
        case -6:
          goto $LN51_5;
        case -5:
          goto $LN50_12;
        case -4:
          goto $LN49_11;
        case -3:
          goto $LN48_4;
        case -2:
          goto $LN47_4;
        case -1:
          goto $LN46_5;
        case 0:
          v29 = *(unsigned __int8 *)--v27;
          v73 = v29;
$LN46_5:
          v30 = *(unsigned __int8 *)--v27;
          v73 |= v30 << 8;
$LN47_4:
          v31 = *(unsigned __int8 *)--v27;
          v73 |= v31 << 16;
$LN48_4:
          v32 = *(unsigned __int8 *)--v27;
          v73 |= v32 << 24;
$LN49_11:
          v28 = *(unsigned __int8 *)--v27;
$LN50_12:
          v33 = *(unsigned __int8 *)--v27;
          v28 |= v33 << 8;
$LN51_5:
          v34 = *(unsigned __int8 *)--v27;
          v28 |= v34 << 16;
$LN52_1:
          v28 |= *(unsigned __int8 *)(v27 - 1) << 24;
          break;
        default:
          break;
      }
      d = v8 ^ v28;
      v71 = v9 ^ v73;
      idea_encrypt(&d, ks);
      v8 = d;
      v35 = v6 + 1;
      *(v35 - 1) = HIBYTE(d);
      *v35 = BYTE2(v8);
      v9 = v71;
      *++v35 = BYTE1(v8);
      *++v35 = v8;
      *++v35 = HIBYTE(v9);
      *++v35 = BYTE2(v9);
      *++v35 = BYTE1(v9);
      v35[1] = v9;
    }
    *iv = HIBYTE(v8);
    iv[1] = BYTE2(v8);
    iv[2] = BYTE1(v8);
    v36 = iv + 3;
    iv[3] = v8;
  }
  else
  {
    v37 = out;
    v38 = in;
    v39 = _byteswap_ulong(*(_DWORD *)iv);
    v9 = _byteswap_ulong(*((_DWORD *)iv + 1));
    v40 = iv;
    v41 = length - 8;
    v68 = v39;
    v77 = v9;
    v67 = length - 8;
    if ( (int)(length - 8) >= 0 )
    {
      v74 = length >> 3;
      v67 = v41 - 8 * v74;
      do
      {
        v42 = *v38;
        v43 = v38[1];
        v44 = v38 + 1;
        v45 = *++v44;
        v46 = *++v44;
        v47 = *++v44;
        v48 = (v43 << 16) | (v42 << 24);
        v49 = *++v44;
        v50 = (v45 << 8) | v48;
        v51 = *++v44;
        v52 = v46 | v50;
        v53 = v44[1] | (v51 << 8) | (v49 << 16) | (v47 << 24);
        d = v52;
        v38 = v44 + 2;
        v71 = v53;
        idea_encrypt(&d, ks);
        v54 = d ^ v68;
        v55 = v71 ^ v77;
        *v37 = (d ^ v68) >> 24;
        v56 = v37 + 1;
        *v56++ = BYTE2(v54);
        *v56 = BYTE1(v54);
        v56[1] = v54;
        v56 += 2;
        *v56++ = HIBYTE(v55);
        *v56++ = BYTE2(v55);
        *v56++ = BYTE1(v55);
        *v56 = v55;
        v37 = v56 + 1;
        v26 = v74-- == 1;
        v68 = v52;
        v77 = v53;
      }
      while ( !v26 );
      v40 = iv;
      v39 = v68;
      v9 = v77;
      v41 = v67;
    }
    if ( v41 != -8 )
    {
      v57 = *v38;
      v58 = v38[1];
      v59 = v38 + 1;
      v60 = *++v59;
      v69 = v59[1] | (v60 << 8) | (v58 << 16) | (v57 << 24);
      d = v69;
      v75 = _byteswap_ulong(*(_DWORD *)(v59 + 2));
      v71 = v75;
      idea_encrypt(&d, ks);
      v61 = d ^ v39;
      v62 = v71 ^ v77;
      v63 = (int)&v37[v67 + 8];
      switch ( v67 )
      {
        case -7:
          goto $LN1_10;
        case -6:
          goto $LN45_3;
        case -5:
          goto $LN44_5;
        case -4:
          goto $LN43_8;
        case -3:
          goto $LN42_5;
        case -2:
          goto $LN41_3;
        case -1:
          goto $LN40_3;
        case 0:
          *(_BYTE *)--v63 = v62;
$LN40_3:
          *(_BYTE *)--v63 = BYTE1(v62);
$LN41_3:
          *(_BYTE *)--v63 = BYTE2(v62);
$LN42_5:
          *(_BYTE *)--v63 = HIBYTE(v62);
$LN43_8:
          *(_BYTE *)--v63 = v61;
$LN44_5:
          *(_BYTE *)--v63 = BYTE1(v61);
$LN45_3:
          *(_BYTE *)--v63 = BYTE2(v61);
$LN1_10:
          *(_BYTE *)(v63 - 1) = HIBYTE(v61);
          break;
        default:
          break;
      }
      v39 = v69;
      v9 = v75;
    }
    *v40 = HIBYTE(v39);
    v64 = v40 + 1;
    *v64++ = BYTE2(v39);
    *v64 = BYTE1(v39);
    v36 = v64 + 1;
    *v36 = v39;
  }
  v65 = v36 + 1;
  *v65++ = HIBYTE(v9);
  *v65++ = BYTE2(v9);
  *v65 = BYTE1(v9);
  v65[1] = v9;
}
