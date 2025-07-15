void __cdecl DES_cfb_encrypt(
        const unsigned __int8 *in,
        unsigned __int8 *out,
        int numbits,
        unsigned int length,
        DES_ks *schedule,
        unsigned __int8 (*ivec)[8],
        int enc)
{
  unsigned int v8; // ebp
  int v9; // ebx
  int v10; // ecx
  unsigned __int8 *v11; // edi
  const unsigned __int8 *v12; // esi
  const unsigned __int8 *v13; // esi
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // edx
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  unsigned __int8 *v26; // edi
  int v27; // ecx
  unsigned __int8 *v28; // edi
  const unsigned __int8 *v29; // esi
  int v30; // eax
  const unsigned __int8 *v31; // esi
  int v32; // ebx
  int v33; // eax
  int v34; // edx
  int v35; // ecx
  int v36; // edx
  int v37; // ebx
  int v38; // ecx
  int v39; // edx
  int v40; // ecx
  int v41; // ebx
  int v42; // eax
  unsigned __int8 *v43; // edi
  int v44; // [esp+8h] [ebp-30h]
  int v45; // [esp+Ch] [ebp-2Ch]
  int v46; // [esp+10h] [ebp-28h]
  int v47; // [esp+10h] [ebp-28h]
  unsigned int v48; // [esp+14h] [ebp-24h]
  int v49; // [esp+18h] [ebp-20h]
  int v50; // [esp+20h] [ebp-18h] BYREF
  int v51; // [esp+24h] [ebp-14h]
  unsigned __int8 dst[4]; // [esp+28h] [ebp-10h] BYREF
  int v53; // [esp+2Ch] [ebp-Ch]
  int v54; // [esp+30h] [ebp-8h]
  int v55; // [esp+34h] [ebp-4h]
  int v56; // [esp+48h] [ebp+10h]

  v44 = numbits / 8;
  v8 = (numbits + 7) / 8;
  v48 = length;
  v45 = numbits % 8;
  if ( (unsigned int)(numbits - 1) <= 0x3F )
  {
    v9 = ((*ivec)[3] << 24) | ((*ivec)[2] << 16) | ((*ivec)[1] << 8) | (*ivec)[0];
    v10 = *(_DWORD *)&(*ivec)[4];
    v46 = v9;
    v56 = v10;
    if ( enc )
    {
      if ( length >= v8 )
      {
        v11 = out;
        v12 = in;
        while ( 1 )
        {
          v48 -= v8;
          v51 = v10;
          v50 = v9;
          DES_encrypt1(&v50, schedule, 1);
          v13 = &v12[v8];
          v14 = 0;
          v15 = 0;
          switch ( v8 )
          {
            case 1u:
              goto $LN52_0;
            case 2u:
              goto $LN53;
            case 3u:
              goto $LN98_2;
            case 4u:
              goto $LN97_3;
            case 5u:
              goto $LN96_2;
            case 6u:
              goto $LN95_0;
            case 7u:
              goto $LN94_1;
            case 8u:
              v16 = *--v13;
              v14 = v16 << 24;
$LN94_1:
              v17 = *--v13;
              v14 |= v17 << 16;
$LN95_0:
              v18 = *--v13;
              v14 |= v18 << 8;
$LN96_2:
              v19 = *--v13;
              v14 |= v19;
$LN97_3:
              v20 = *--v13;
              v15 = v20 << 24;
$LN98_2:
              v21 = *--v13;
              v15 |= v21 << 16;
$LN53:
              v22 = *--v13;
              v15 |= v22 << 8;
$LN52_0:
              v23 = *--v13;
              v15 |= v23;
              break;
            default:
              break;
          }
          v24 = v50 ^ v15;
          v25 = v51 ^ v14;
          v12 = &v13[v8];
          v26 = &v11[v8];
          switch ( v8 )
          {
            case 1u:
              goto $LN42_32;
            case 2u:
              goto $LN43_41;
            case 3u:
              goto $LN44_6;
            case 4u:
              goto $LN99_0;
            case 5u:
              goto $LN46_5;
            case 6u:
              goto $LN47_5;
            case 7u:
              goto $LN48_3;
            case 8u:
              *--v26 = HIBYTE(v25);
$LN48_3:
              *--v26 = BYTE2(v25);
$LN47_5:
              *--v26 = BYTE1(v25);
$LN46_5:
              *--v26 = v25;
$LN99_0:
              *--v26 = HIBYTE(v24);
$LN44_6:
              *--v26 = BYTE2(v24);
$LN43_41:
              *--v26 = BYTE1(v24);
$LN42_32:
              *--v26 = v24;
              break;
            default:
              break;
          }
          v11 = &v26[v8];
          if ( numbits == 32 )
            break;
          if ( numbits != 64 )
          {
            v55 = v25;
            *(_DWORD *)dst = v9;
            v53 = v56;
            v54 = v24;
            if ( v45 )
            {
              dst[0] = (dst[v44] << v45) | (dst[v44 + 1] >> (8 - v45));
              dst[1] = (dst[v44 + 2] >> (8 - v45)) | (dst[v44 + 1] << v45);
              dst[2] = (dst[v44 + 3] >> (8 - v45)) | (dst[v44 + 2] << v45);
              dst[3] = (dst[v44 + 3] << v45) | (*((_BYTE *)&v53 + v44) >> (8 - v45));
              LOBYTE(v53) = (*((_BYTE *)&v53 + v44 + 1) >> (8 - v45)) | (*((_BYTE *)&v53 + v44) << v45);
              BYTE1(v53) = (*((_BYTE *)&v53 + v44 + 2) >> (8 - v45)) | (*((_BYTE *)&v53 + v44 + 1) << v45);
              BYTE2(v53) = (*((_BYTE *)&v53 + v44 + 3) >> (8 - v45)) | (*((_BYTE *)&v53 + v44 + 2) << v45);
              HIBYTE(v53) = (*((_BYTE *)&v53 + v44 + 3) << v45) | (*((_BYTE *)&v54 + v44) >> (8 - v45));
            }
            else
            {
              memmove(dst, &dst[v44], 8u);
            }
            v27 = *(_DWORD *)dst;
            v56 = v53;
            goto LABEL_31;
          }
          v47 = v24;
          v56 = v25;
LABEL_32:
          v9 = v47;
          v10 = v56;
          if ( v48 < v8 )
            goto LABEL_63;
        }
        v27 = v56;
        v56 = v24;
LABEL_31:
        v47 = v27;
        goto LABEL_32;
      }
    }
    else if ( length >= v8 )
    {
      v28 = out;
      v29 = in;
      do
      {
        v48 -= v8;
        v51 = v10;
        v50 = v9;
        DES_encrypt1(&v50, schedule, 1);
        v30 = 0;
        v31 = &v29[v8];
        v32 = 0;
        v49 = 0;
        switch ( v8 )
        {
          case 1u:
            goto $LN106_0;
          case 2u:
            goto $LN105_1;
          case 3u:
            goto $LN104_1;
          case 4u:
            goto $LN103_1;
          case 5u:
            goto $LN102_0;
          case 6u:
            goto $LN101_1;
          case 7u:
            goto $LN100_1;
          case 8u:
            v33 = *--v31;
            v30 = v33 << 24;
$LN100_1:
            v34 = *--v31;
            v30 |= v34 << 16;
$LN101_1:
            v35 = *--v31;
            v30 |= v35 << 8;
$LN102_0:
            v36 = *--v31;
            v30 |= v36;
            v49 = v30;
$LN103_1:
            v37 = *--v31;
            v32 = v37 << 24;
$LN104_1:
            v38 = *--v31;
            v32 |= v38 << 16;
$LN105_1:
            v39 = *--v31;
            v32 |= v39 << 8;
$LN106_0:
            v40 = *--v31;
            v32 |= v40;
            break;
          default:
            break;
        }
        v29 = &v31[v8];
        if ( numbits == 32 )
        {
          v46 = v56;
          v56 = v32;
        }
        else if ( numbits == 64 )
        {
          v46 = v32;
          v56 = v30;
        }
        else
        {
          v55 = v30;
          *(_DWORD *)dst = v46;
          v53 = v56;
          v54 = v32;
          if ( v45 )
          {
            dst[0] = (dst[v44] << v45) | (dst[v44 + 1] >> (8 - v45));
            dst[1] = (dst[v44 + 2] >> (8 - v45)) | (dst[v44 + 1] << v45);
            dst[2] = (dst[v44 + 3] >> (8 - v45)) | (dst[v44 + 2] << v45);
            dst[3] = (dst[v44 + 3] << v45) | (*((_BYTE *)&v53 + v44) >> (8 - v45));
            LOBYTE(v53) = (*((_BYTE *)&v53 + v44 + 1) >> (8 - v45)) | (*((_BYTE *)&v53 + v44) << v45);
            BYTE1(v53) = (*((_BYTE *)&v53 + v44 + 2) >> (8 - v45)) | (*((_BYTE *)&v53 + v44 + 1) << v45);
            BYTE2(v53) = (*((_BYTE *)&v53 + v44 + 3) >> (8 - v45)) | (*((_BYTE *)&v53 + v44 + 2) << v45);
            HIBYTE(v53) = (*((_BYTE *)&v53 + v44 + 3) << v45) | (*((_BYTE *)&v54 + v44) >> (8 - v45));
          }
          else
          {
            memmove(dst, &dst[v44], 8u);
          }
          v30 = v49;
          v46 = *(_DWORD *)dst;
          v56 = v53;
        }
        v41 = v50 ^ v32;
        v42 = v51 ^ v30;
        v43 = &v28[v8];
        switch ( v8 )
        {
          case 1u:
            goto $LN114_1;
          case 2u:
            goto $LN113_2;
          case 3u:
            goto $LN112_0;
          case 4u:
            goto $LN111_0;
          case 5u:
            goto $LN110;
          case 6u:
            goto $LN109_0;
          case 7u:
            goto $LN108_0;
          case 8u:
            *--v43 = HIBYTE(v42);
$LN108_0:
            *--v43 = BYTE2(v42);
$LN109_0:
            *--v43 = BYTE1(v42);
$LN110:
            *--v43 = v42;
$LN111_0:
            *--v43 = HIBYTE(v41);
$LN112_0:
            *--v43 = BYTE2(v41);
$LN113_2:
            *--v43 = BYTE1(v41);
$LN114_1:
            *--v43 = v41;
            break;
          default:
            break;
        }
        v9 = v46;
        v10 = v56;
        v28 = &v43[v8];
      }
      while ( v48 >= v8 );
    }
LABEL_63:
    *(_DWORD *)ivec = v9;
    *(_DWORD *)&(*ivec)[4] = v10;
  }
}
