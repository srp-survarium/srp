void __cdecl DES_ede3_cfb_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        int numbits,
        unsigned int length,
        DES_ks *ks1,
        DES_ks *ks2,
        DES_ks *ks3,
        unsigned __int8 (*ivec)[8],
        int enc)
{
  unsigned int v10; // ebp
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  const unsigned __int8 *v15; // esi
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // edx
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // edx
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  unsigned __int8 *v28; // edi
  int v29; // ebx
  char v30; // dl
  char v31; // dl
  char v32; // dl
  char v33; // dl
  char v34; // dl
  char v35; // dl
  int v36; // ecx
  int v37; // eax
  const unsigned __int8 *v38; // esi
  int v39; // eax
  int v40; // eax
  int v41; // edx
  int v42; // eax
  int v43; // eax
  int v44; // edx
  int v45; // edx
  int v46; // edx
  int v47; // ebx
  char v48; // dl
  char v49; // dl
  char v50; // dl
  char v51; // dl
  char v52; // dl
  char v53; // dl
  int v54; // eax
  int v55; // ecx
  unsigned __int8 *v56; // edi
  unsigned __int8 *v57; // esi
  int v58; // [esp+8h] [ebp-40h]
  unsigned int v59; // [esp+Ch] [ebp-3Ch]
  int v60; // [esp+10h] [ebp-38h]
  int v61; // [esp+14h] [ebp-34h]
  int v62; // [esp+18h] [ebp-30h] BYREF
  int v63; // [esp+1Ch] [ebp-2Ch]
  DES_ks *v64; // [esp+20h] [ebp-28h]
  DES_ks *v65; // [esp+24h] [ebp-24h]
  DES_ks *v66; // [esp+28h] [ebp-20h]
  unsigned __int8 *v67; // [esp+2Ch] [ebp-1Ch]
  unsigned __int8 *v68; // [esp+30h] [ebp-18h]
  int dst; // [esp+34h] [ebp-14h] BYREF
  int v70; // [esp+38h] [ebp-10h]
  int v71; // [esp+3Ch] [ebp-Ch]
  int v72; // [esp+40h] [ebp-8h]

  v64 = ks2;
  v59 = length;
  v66 = ks1;
  v10 = (unsigned int)(numbits + 7) >> 3;
  v65 = ks3;
  v68 = (unsigned __int8 *)ivec;
  if ( numbits <= 64 )
  {
    v12 = (*ivec)[1] << 8;
    v67 = &(*ivec)[1];
    v13 = ((*ivec)[3] << 24) | ((*ivec)[2] << 16) | v12 | (*ivec)[0];
    v14 = (((*ivec)[6] | ((*ivec)[7] << 8)) << 16) | *(unsigned __int16 *)&(*ivec)[4];
    v58 = v14;
    if ( enc )
    {
      if ( length >= v10 )
      {
        while ( 1 )
        {
          v59 -= v10;
          v63 = v14;
          v62 = v13;
          DES_encrypt3(&v62, v66, v64, v65);
          v15 = &in[v10];
          v16 = 0;
          v17 = 0;
          switch ( v10 )
          {
            case 1u:
              goto $LN50_10;
            case 2u:
              goto $LN51_5;
            case 3u:
              goto $LN97_2;
            case 4u:
              goto $LN96_1;
            case 5u:
              goto $LN95;
            case 6u:
              goto $LN94_0;
            case 7u:
              goto $LN93;
            case 8u:
              v18 = *--v15;
              v16 = v18 << 24;
$LN93:
              v19 = *--v15;
              v16 |= v19 << 16;
$LN94_0:
              v20 = *--v15;
              v16 |= v20 << 8;
$LN95:
              v21 = *--v15;
              v16 |= v21;
$LN96_1:
              v22 = *--v15;
              v17 = v22 << 24;
$LN97_2:
              v23 = *--v15;
              v17 |= v23 << 16;
$LN51_5:
              v24 = *--v15;
              v17 |= v24 << 8;
$LN50_10:
              v25 = *--v15;
              v17 |= v25;
              break;
            default:
              break;
          }
          v26 = v62 ^ v17;
          v27 = v63 ^ v16;
          in = &v15[v10];
          v28 = &out[v10];
          switch ( v10 )
          {
            case 1u:
              goto $LN40_1;
            case 2u:
              goto $LN41_3;
            case 3u:
              goto $LN42_31;
            case 4u:
              goto $LN98_1;
            case 5u:
              goto $LN44_5;
            case 6u:
              goto $LN45_4;
            case 7u:
              goto $LN46_4;
            case 8u:
              *--v28 = HIBYTE(v27);
$LN46_4:
              *--v28 = BYTE2(v27);
$LN45_4:
              *--v28 = BYTE1(v27);
$LN44_5:
              *--v28 = v27;
$LN98_1:
              *--v28 = HIBYTE(v26);
$LN42_31:
              *--v28 = BYTE2(v26);
$LN41_3:
              *--v28 = BYTE1(v26);
$LN40_1:
              *--v28 = v26;
              break;
            default:
              break;
          }
          out = &v28[v10];
          if ( numbits == 32 )
            break;
          if ( numbits != 64 )
          {
            dst = v13;
            v70 = v58;
            v71 = v26;
            v72 = v27;
            v29 = numbits % 8;
            memmove((unsigned __int8 *)&dst, (unsigned __int8 *)&dst + numbits / 8, (numbits % 8 != 0) + 8);
            if ( numbits % 8 )
            {
              LOBYTE(dst) = (_BYTE)dst << v29;
              v30 = BYTE1(dst) >> (8 - v29);
              BYTE1(dst) <<= v29;
              LOBYTE(dst) = v30 | dst;
              v31 = BYTE2(dst) >> (8 - v29);
              BYTE2(dst) <<= v29;
              BYTE1(dst) |= v31;
              v32 = HIBYTE(dst) >> (8 - v29);
              HIBYTE(dst) <<= v29;
              BYTE2(dst) |= v32;
              v33 = (unsigned __int8)v70 >> (8 - v29);
              LOBYTE(v70) = (_BYTE)v70 << v29;
              HIBYTE(dst) |= v33;
              v34 = BYTE1(v70) >> (8 - v29);
              BYTE1(v70) <<= v29;
              LOBYTE(v70) = v34 | v70;
              v35 = BYTE2(v70) >> (8 - v29);
              BYTE2(v70) <<= v29;
              BYTE1(v70) |= v35;
              BYTE2(v70) |= HIBYTE(v70) >> (8 - v29);
              HIBYTE(v70) = ((unsigned __int8)v71 >> (8 - v29)) | (HIBYTE(v70) << v29);
            }
            v13 = (HIBYTE(dst) << 24) | (BYTE2(dst) << 16) | (unsigned __int16)dst;
            v26 = v70;
            goto LABEL_29;
          }
          v13 = v26;
          v58 = v27;
LABEL_30:
          v14 = v58;
          if ( v59 < v10 )
            goto LABEL_59;
        }
        v13 = v58;
LABEL_29:
        v58 = v26;
        goto LABEL_30;
      }
    }
    else if ( length >= v10 )
    {
      do
      {
        v59 -= v10;
        v63 = v14;
        v62 = v13;
        DES_encrypt3(&v62, v66, v64, v65);
        v36 = 0;
        v37 = 0;
        v38 = &in[v10];
        v61 = 0;
        v60 = 0;
        switch ( v10 )
        {
          case 1u:
            goto $LN19_21;
          case 2u:
            goto $LN20_19;
          case 3u:
            goto $LN103_0;
          case 4u:
            goto $LN102;
          case 5u:
            goto $LN101_0;
          case 6u:
            goto $LN100_0;
          case 7u:
            goto $LN99;
          case 8u:
            v39 = *--v38;
            v36 = v39 << 24;
$LN99:
            v40 = *--v38;
            v36 |= v40 << 16;
$LN100_0:
            v41 = *--v38;
            v36 |= v41 << 8;
$LN101_0:
            v42 = *--v38;
            v36 |= v42;
            v61 = v36;
$LN102:
            v43 = *--v38;
            v37 = v43 << 24;
$LN103_0:
            v44 = *--v38;
            v37 |= v44 << 16;
$LN20_19:
            v45 = *--v38;
            v37 |= v45 << 8;
$LN19_21:
            v46 = *--v38;
            v37 |= v46;
            v60 = v37;
            break;
          default:
            break;
        }
        in = &v38[v10];
        if ( numbits == 32 )
        {
          v13 = v58;
          v58 = v37;
        }
        else if ( numbits == 64 )
        {
          v13 = v37;
          v58 = v36;
        }
        else
        {
          dst = v13;
          v70 = v58;
          v71 = v37;
          v72 = v36;
          v47 = numbits % 8;
          memmove((unsigned __int8 *)&dst, (unsigned __int8 *)&dst + numbits / 8, (numbits % 8 != 0) + 8);
          if ( numbits % 8 )
          {
            LOBYTE(dst) = (_BYTE)dst << v47;
            v48 = BYTE1(dst) >> (8 - v47);
            BYTE1(dst) <<= v47;
            LOBYTE(dst) = v48 | dst;
            v49 = BYTE2(dst) >> (8 - v47);
            BYTE2(dst) <<= v47;
            BYTE1(dst) |= v49;
            v50 = HIBYTE(dst) >> (8 - v47);
            HIBYTE(dst) <<= v47;
            BYTE2(dst) |= v50;
            v51 = (unsigned __int8)v70 >> (8 - v47);
            LOBYTE(v70) = (_BYTE)v70 << v47;
            HIBYTE(dst) |= v51;
            v52 = BYTE1(v70) >> (8 - v47);
            BYTE1(v70) <<= v47;
            LOBYTE(v70) = v52 | v70;
            v53 = BYTE2(v70) >> (8 - v47);
            BYTE2(v70) <<= v47;
            BYTE1(v70) |= v53;
            BYTE2(v70) |= HIBYTE(v70) >> (8 - v47);
            HIBYTE(v70) = ((unsigned __int8)v71 >> (8 - v47)) | (HIBYTE(v70) << v47);
          }
          v13 = (HIBYTE(dst) << 24) | (BYTE2(dst) << 16) | (unsigned __int16)dst;
          v36 = v61;
          v58 = v70;
          v37 = v60;
        }
        v54 = v62 ^ v37;
        v55 = v63 ^ v36;
        v56 = &out[v10];
        switch ( v10 )
        {
          case 1u:
            goto $LN107_0;
          case 2u:
            goto $LN106;
          case 3u:
            goto $LN105_0;
          case 4u:
            goto $LN104_0;
          case 5u:
            goto $LN5_29;
          case 6u:
            goto $LN6_41;
          case 7u:
            goto $LN7_34;
          case 8u:
            *--v56 = HIBYTE(v55);
$LN7_34:
            *--v56 = BYTE2(v55);
$LN6_41:
            *--v56 = BYTE1(v55);
$LN5_29:
            *--v56 = v55;
$LN104_0:
            *--v56 = HIBYTE(v54);
$LN105_0:
            *--v56 = BYTE2(v54);
$LN106:
            *--v56 = BYTE1(v54);
$LN107_0:
            *--v56 = v54;
            break;
          default:
            break;
        }
        v14 = v58;
        out = &v56[v10];
      }
      while ( v59 >= v10 );
    }
LABEL_59:
    v57 = v67;
    *v68 = v13;
    *v57++ = BYTE1(v13);
    *v57++ = BYTE2(v13);
    *v57++ = HIBYTE(v13);
    *v57++ = v14;
    *v57++ = BYTE1(v14);
    *v57 = BYTE2(v14);
    v57[1] = HIBYTE(v14);
  }
}
