int __cdecl png_do_compose(int a1, _BYTE *a2, int a3)
{
  int result; // eax
  unsigned int v4; // [esp+Ch] [ebp-F0h]
  unsigned int v5; // [esp+10h] [ebp-ECh]
  unsigned int v6; // [esp+14h] [ebp-E8h]
  unsigned __int16 v7; // [esp+1Ch] [ebp-E0h]
  unsigned __int16 v8; // [esp+20h] [ebp-DCh]
  unsigned __int16 v9; // [esp+28h] [ebp-D4h]
  unsigned int v10; // [esp+2Ch] [ebp-D0h]
  unsigned int v11; // [esp+30h] [ebp-CCh]
  unsigned int v12; // [esp+34h] [ebp-C8h]
  unsigned __int16 v13; // [esp+3Ch] [ebp-C0h]
  unsigned __int16 v14; // [esp+3Ch] [ebp-C0h]
  unsigned __int16 v15; // [esp+3Ch] [ebp-C0h]
  __int16 v16; // [esp+40h] [ebp-BCh]
  __int16 v17; // [esp+40h] [ebp-BCh]
  __int16 v18; // [esp+40h] [ebp-BCh]
  unsigned __int16 v19; // [esp+44h] [ebp-B8h]
  unsigned __int16 v20; // [esp+48h] [ebp-B4h]
  unsigned __int16 v21; // [esp+4Ch] [ebp-B0h]
  unsigned __int16 v22; // [esp+50h] [ebp-ACh]
  unsigned __int8 v23; // [esp+57h] [ebp-A5h]
  unsigned __int16 v24; // [esp+58h] [ebp-A4h]
  unsigned __int16 v25; // [esp+5Ch] [ebp-A0h]
  unsigned __int16 v26; // [esp+60h] [ebp-9Ch]
  unsigned __int8 v27; // [esp+66h] [ebp-96h]
  unsigned __int8 v28; // [esp+66h] [ebp-96h]
  unsigned __int8 v29; // [esp+66h] [ebp-96h]
  unsigned __int8 v30; // [esp+67h] [ebp-95h]
  unsigned int v31; // [esp+68h] [ebp-94h]
  unsigned __int16 v32; // [esp+74h] [ebp-88h]
  unsigned int v33; // [esp+78h] [ebp-84h]
  __int16 v34; // [esp+84h] [ebp-78h]
  __int16 v35; // [esp+88h] [ebp-74h]
  unsigned __int16 v36; // [esp+8Ch] [ebp-70h]
  unsigned __int16 v37; // [esp+90h] [ebp-6Ch]
  unsigned __int8 v38; // [esp+97h] [ebp-65h]
  unsigned __int16 v39; // [esp+98h] [ebp-64h]
  unsigned __int8 v40; // [esp+9Fh] [ebp-5Dh]
  __int16 v41; // [esp+B0h] [ebp-4Ch]
  __int16 v42; // [esp+B0h] [ebp-4Ch]
  __int16 v43; // [esp+B0h] [ebp-4Ch]
  __int16 v44; // [esp+C4h] [ebp-38h]
  unsigned __int8 v45; // [esp+C8h] [ebp-34h]
  unsigned __int8 v46; // [esp+C9h] [ebp-33h]
  unsigned __int8 v47; // [esp+CAh] [ebp-32h]
  unsigned __int8 v48; // [esp+CBh] [ebp-31h]
  int v49; // [esp+CCh] [ebp-30h]
  int v50; // [esp+D0h] [ebp-2Ch]
  int v51; // [esp+D0h] [ebp-2Ch]
  int v52; // [esp+D0h] [ebp-2Ch]
  int v53; // [esp+D0h] [ebp-2Ch]
  int v54; // [esp+D0h] [ebp-2Ch]
  int v55; // [esp+D4h] [ebp-28h]
  int v56; // [esp+D8h] [ebp-24h]
  BOOL v57; // [esp+DCh] [ebp-20h]
  int v58; // [esp+E0h] [ebp-1Ch]
  int v59; // [esp+E4h] [ebp-18h]
  unsigned int v60; // [esp+E8h] [ebp-14h]
  int v61; // [esp+ECh] [ebp-10h]
  _BYTE *v62; // [esp+F0h] [ebp-Ch]
  _BYTE *v63; // [esp+F0h] [ebp-Ch]
  _BYTE *v64; // [esp+F0h] [ebp-Ch]
  _BYTE *v65; // [esp+F0h] [ebp-Ch]
  _BYTE *v66; // [esp+F0h] [ebp-Ch]
  _BYTE *v67; // [esp+F0h] [ebp-Ch]
  _BYTE *v68; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v69; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v70; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v71; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v72; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v73; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v74; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v75; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v76; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v77; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v78; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v79; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v80; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v81; // [esp+F0h] [ebp-Ch]
  unsigned __int8 *v82; // [esp+F0h] [ebp-Ch]
  unsigned int i; // [esp+F4h] [ebp-8h]
  unsigned int j; // [esp+F4h] [ebp-8h]
  unsigned int k; // [esp+F4h] [ebp-8h]
  unsigned int m; // [esp+F4h] [ebp-8h]
  unsigned int n; // [esp+F4h] [ebp-8h]
  unsigned int ii; // [esp+F4h] [ebp-8h]
  unsigned int jj; // [esp+F4h] [ebp-8h]
  unsigned int kk; // [esp+F4h] [ebp-8h]
  unsigned int mm; // [esp+F4h] [ebp-8h]
  unsigned int nn; // [esp+F4h] [ebp-8h]
  unsigned int i1; // [esp+F4h] [ebp-8h]
  unsigned int i2; // [esp+F4h] [ebp-8h]
  unsigned int i3; // [esp+F4h] [ebp-8h]
  unsigned int i4; // [esp+F4h] [ebp-8h]
  unsigned int i5; // [esp+F4h] [ebp-8h]
  unsigned int i6; // [esp+F4h] [ebp-8h]
  unsigned int i7; // [esp+F4h] [ebp-8h]
  unsigned int i8; // [esp+F4h] [ebp-8h]
  unsigned int i9; // [esp+F4h] [ebp-8h]
  unsigned int i10; // [esp+F4h] [ebp-8h]
  unsigned int i11; // [esp+F4h] [ebp-8h]
  int v104; // [esp+F8h] [ebp-4h]

  v49 = *(_DWORD *)(a3 + 384);
  v59 = *(_DWORD *)(a3 + 392);
  v61 = *(_DWORD *)(a3 + 396);
  v58 = *(_DWORD *)(a3 + 388);
  v104 = *(_DWORD *)(a3 + 400);
  v55 = *(_DWORD *)(a3 + 404);
  v56 = *(_DWORD *)(a3 + 372);
  v60 = *(_DWORD *)a1;
  v57 = (*(_DWORD *)(a3 + 112) & 0x2000) != 0;
  result = a1;
  switch ( *(_BYTE *)(a1 + 8) )
  {
    case 0:
      result = *(unsigned __int8 *)(a1 + 9) - 1;
      switch ( *(_BYTE *)(a1 + 9) )
      {
        case 1:
          v62 = a2;
          v50 = 7;
          for ( i = 0; i < v60; ++i )
          {
            if ( (((int)(unsigned __int8)*v62 >> v50) & 1) == *(_WORD *)(a3 + 432) )
            {
              *v62 &= 32639 >> (7 - v50);
              *v62 |= *(unsigned __int16 *)(a3 + 348) << v50;
            }
            if ( v50 )
            {
              --v50;
            }
            else
            {
              v50 = 7;
              ++v62;
            }
            result = i + 1;
          }
          break;
        case 2:
          if ( v49 )
          {
            result = (int)a2;
            v63 = a2;
            v51 = 6;
            for ( j = 0; j < v60; ++j )
            {
              if ( (((int)(unsigned __int8)*v63 >> v51) & 3) == *(_WORD *)(a3 + 432) )
              {
                *v63 &= 16191 >> (6 - v51);
                result = (unsigned __int8)(*(unsigned __int16 *)(a3 + 348) << v51) | (unsigned __int8)*v63;
                *v63 = result;
              }
              else
              {
                v48 = ((int)(unsigned __int8)*v63 >> v51) & 3;
                v47 = ((int)*(unsigned __int8 *)(v49 + ((v48 << 6) | (16 * v48) | (4 * v48) | v48)) >> 6) & 3;
                *v63 &= 16191 >> (6 - v51);
                result = (int)v63;
                *v63 |= v47 << v51;
              }
              if ( v51 )
              {
                v51 -= 2;
              }
              else
              {
                v51 = 6;
                ++v63;
              }
            }
          }
          else
          {
            result = (int)a2;
            v64 = a2;
            v52 = 6;
            for ( k = 0; k < v60; ++k )
            {
              result = ((int)(unsigned __int8)*v64 >> v52) & 3;
              if ( result == *(unsigned __int16 *)(a3 + 432) )
              {
                *v64 &= 16191 >> (6 - v52);
                result = (unsigned __int8)(*(unsigned __int16 *)(a3 + 348) << v52) | (unsigned __int8)*v64;
                *v64 = result;
              }
              if ( v52 )
              {
                result = v52 - 2;
                v52 -= 2;
              }
              else
              {
                v52 = 6;
                ++v64;
              }
            }
          }
          break;
        case 4:
          if ( v49 )
          {
            v65 = a2;
            v53 = 4;
            for ( m = 0; ; ++m )
            {
              result = m;
              if ( m >= v60 )
                break;
              if ( (((int)(unsigned __int8)*v65 >> v53) & 0xF) == *(_WORD *)(a3 + 432) )
              {
                *v65 &= 3855 >> (4 - v53);
                *v65 |= *(unsigned __int16 *)(a3 + 348) << v53;
              }
              else
              {
                v46 = ((int)(unsigned __int8)*v65 >> v53) & 0xF;
                v45 = ((int)*(unsigned __int8 *)(v49 + ((16 * v46) | v46)) >> 4) & 0xF;
                *v65 &= 3855 >> (4 - v53);
                *v65 |= v45 << v53;
              }
              if ( v53 )
              {
                v53 -= 4;
              }
              else
              {
                v53 = 4;
                ++v65;
              }
            }
          }
          else
          {
            result = (int)a2;
            v66 = a2;
            v54 = 4;
            for ( n = 0; n < v60; ++n )
            {
              result = ((int)(unsigned __int8)*v66 >> v54) & 0xF;
              if ( result == *(unsigned __int16 *)(a3 + 432) )
              {
                *v66 &= 3855 >> (4 - v54);
                result = (unsigned __int8)(*(unsigned __int16 *)(a3 + 348) << v54) | (unsigned __int8)*v66;
                *v66 = result;
              }
              if ( v54 )
              {
                result = v54 - 4;
                v54 -= 4;
              }
              else
              {
                v54 = 4;
                ++v66;
              }
            }
          }
          break;
        case 8:
          if ( v49 )
          {
            v67 = a2;
            for ( ii = 0; ii < v60; ++ii )
            {
              if ( (unsigned __int8)*v67 == *(unsigned __int16 *)(a3 + 432) )
                *v67 = *(_BYTE *)(a3 + 348);
              else
                *v67 = *(_BYTE *)(v49 + (unsigned __int8)*v67);
              result = (int)++v67;
            }
          }
          else
          {
            v68 = a2;
            for ( jj = 0; jj < v60; ++jj )
            {
              if ( (unsigned __int8)*v68 == *(unsigned __int16 *)(a3 + 432) )
                *v68 = *(_BYTE *)(a3 + 348);
              result = jj + 1;
              ++v68;
            }
          }
          break;
        case 0x10:
          if ( v58 )
          {
            v69 = a2;
            for ( kk = 0; kk < v60; ++kk )
            {
              if ( (unsigned __int16)(v69[1] + (*v69 << 8)) == *(unsigned __int16 *)(a3 + 432) )
              {
                *v69 = HIBYTE(*(_WORD *)(a3 + 348));
                v69[1] = *(_WORD *)(a3 + 348);
              }
              else
              {
                v44 = *(_WORD *)(*(_DWORD *)(v58 + 4 * ((int)v69[1] >> v56)) + 2 * *v69);
                *v69 = HIBYTE(v44);
                v69[1] = v44;
              }
              result = (int)(v69 + 2);
              v69 += 2;
            }
          }
          else
          {
            v70 = a2;
            for ( mm = 0; mm < v60; ++mm )
            {
              if ( (unsigned __int16)(v70[1] + (*v70 << 8)) == *(unsigned __int16 *)(a3 + 432) )
              {
                *v70 = HIBYTE(*(_WORD *)(a3 + 348));
                v70[1] = *(_WORD *)(a3 + 348);
              }
              result = mm + 1;
              v70 += 2;
            }
          }
          break;
        default:
          result = a1;
          break;
      }
      break;
    case 2:
      if ( *(_BYTE *)(a1 + 9) == 8 )
      {
        if ( v49 )
        {
          v71 = a2;
          for ( nn = 0; ; ++nn )
          {
            result = nn;
            if ( nn >= v60 )
              break;
            if ( *v71 == *(unsigned __int16 *)(a3 + 426)
              && v71[1] == *(unsigned __int16 *)(a3 + 428)
              && v71[2] == *(unsigned __int16 *)(a3 + 430) )
            {
              *v71 = *(_BYTE *)(a3 + 342);
              v71[1] = *(_BYTE *)(a3 + 344);
              v71[2] = *(_BYTE *)(a3 + 346);
            }
            else
            {
              *v71 = *(_BYTE *)(v49 + *v71);
              v71[1] = *(_BYTE *)(v49 + v71[1]);
              v71[2] = *(_BYTE *)(v49 + v71[2]);
            }
            v71 += 3;
          }
        }
        else
        {
          v72 = a2;
          for ( i1 = 0; i1 < v60; ++i1 )
          {
            if ( *v72 == *(unsigned __int16 *)(a3 + 426)
              && v72[1] == *(unsigned __int16 *)(a3 + 428)
              && v72[2] == *(unsigned __int16 *)(a3 + 430) )
            {
              *v72 = *(_BYTE *)(a3 + 342);
              v72[1] = *(_BYTE *)(a3 + 344);
              v72[2] = *(_BYTE *)(a3 + 346);
            }
            result = (int)(v72 + 3);
            v72 += 3;
          }
        }
      }
      else if ( v58 )
      {
        v73 = a2;
        for ( i2 = 0; i2 < v60; ++i2 )
        {
          if ( (unsigned __int16)(v73[1] + (*v73 << 8)) == *(unsigned __int16 *)(a3 + 426)
            && (unsigned __int16)(v73[3] + (v73[2] << 8)) == *(unsigned __int16 *)(a3 + 428)
            && (unsigned __int16)(v73[5] + (v73[4] << 8)) == *(unsigned __int16 *)(a3 + 430) )
          {
            *v73 = HIBYTE(*(_WORD *)(a3 + 342));
            v73[1] = *(_WORD *)(a3 + 342);
            v73[2] = HIBYTE(*(_WORD *)(a3 + 344));
            v73[3] = *(_WORD *)(a3 + 344);
            v73[4] = HIBYTE(*(_WORD *)(a3 + 346));
            v73[5] = *(_WORD *)(a3 + 346);
          }
          else
          {
            v41 = *(_WORD *)(*(_DWORD *)(v58 + 4 * ((int)v73[1] >> v56)) + 2 * *v73);
            *v73 = HIBYTE(v41);
            v73[1] = v41;
            v42 = *(_WORD *)(*(_DWORD *)(v58 + 4 * ((int)v73[3] >> v56)) + 2 * v73[2]);
            v73[2] = HIBYTE(v42);
            v73[3] = v42;
            v43 = *(_WORD *)(*(_DWORD *)(v58 + 4 * ((int)v73[5] >> v56)) + 2 * v73[4]);
            v73[4] = HIBYTE(v43);
            v73[5] = v43;
          }
          result = i2 + 1;
          v73 += 6;
        }
      }
      else
      {
        v74 = a2;
        for ( i3 = 0; i3 < v60; ++i3 )
        {
          if ( (unsigned __int16)(v74[1] + (*v74 << 8)) == *(unsigned __int16 *)(a3 + 426)
            && (unsigned __int16)(v74[3] + (v74[2] << 8)) == *(unsigned __int16 *)(a3 + 428)
            && (unsigned __int16)(v74[5] + (v74[4] << 8)) == *(unsigned __int16 *)(a3 + 430) )
          {
            *v74 = HIBYTE(*(_WORD *)(a3 + 342));
            v74[1] = *(_WORD *)(a3 + 342);
            v74[2] = HIBYTE(*(_WORD *)(a3 + 344));
            v74[3] = *(_WORD *)(a3 + 344);
            v74[4] = HIBYTE(*(_WORD *)(a3 + 346));
            v74[5] = *(_WORD *)(a3 + 346);
          }
          result = i3 + 1;
          v74 += 6;
        }
      }
      break;
    case 4:
      result = a1;
      if ( *(_BYTE *)(a1 + 9) == 8 )
      {
        if ( v61 && v59 && v49 )
        {
          v75 = a2;
          for ( i4 = 0; i4 < v60; ++i4 )
          {
            if ( v75[1] == 255 )
            {
              *v75 = *(_BYTE *)(v49 + *v75);
            }
            else if ( v75[1] )
            {
              v39 = v75[1] * *(unsigned __int8 *)(v61 + *v75) + (255 - v75[1]) * *(_WORD *)(a3 + 358) + 128;
              v40 = (unsigned __int16)(((int)v39 >> 8) + v39) >> 8;
              if ( !v57 )
                v40 = *(_BYTE *)(v59 + v40);
              *v75 = v40;
            }
            else
            {
              *v75 = *(_BYTE *)(a3 + 348);
            }
            result = i4 + 1;
            v75 += 2;
          }
        }
        else
        {
          v76 = a2;
          for ( i5 = 0; ; ++i5 )
          {
            result = i5;
            if ( i5 >= v60 )
              break;
            v38 = v76[1];
            if ( v38 )
            {
              if ( v38 != 255 )
              {
                v37 = v38 * *v76 + (255 - v38) * *(_WORD *)(a3 + 358) + 128;
                *v76 = (unsigned __int16)(((int)v37 >> 8) + v37) >> 8;
              }
            }
            else
            {
              *v76 = *(_BYTE *)(a3 + 348);
            }
            v76 += 2;
          }
        }
      }
      else if ( v58 && v104 && v55 )
      {
        v77 = a2;
        for ( i6 = 0; i6 < v60; ++i6 )
        {
          v36 = v77[3] + (v77[2] << 8);
          if ( v36 == 0xFFFF )
          {
            v35 = *(_WORD *)(*(_DWORD *)(v58 + 4 * ((int)v77[1] >> v56)) + 2 * *v77);
            *v77 = HIBYTE(v35);
            v77[1] = v35;
          }
          else if ( v36 )
          {
            v33 = v36 * *(unsigned __int16 *)(*(_DWORD *)(v55 + 4 * ((int)v77[1] >> v56)) + 2 * *v77)
                + (0xFFFF - v36) * *(unsigned __int16 *)(a3 + 358)
                + 0x8000;
            if ( v57 )
              v34 = (v33 + HIWORD(v33)) >> 16;
            else
              v34 = *(_WORD *)(*(_DWORD *)(v104 + 4 * ((int)(unsigned __int8)((v33 + HIWORD(v33)) >> 16) >> v56))
                             + 2 * ((int)((v33 + HIWORD(v33)) >> 16) >> 8));
            *v77 = HIBYTE(v34);
            v77[1] = v34;
          }
          else
          {
            *v77 = HIBYTE(*(_WORD *)(a3 + 348));
            v77[1] = *(_WORD *)(a3 + 348);
          }
          result = (int)(v77 + 4);
          v77 += 4;
        }
      }
      else
      {
        v78 = a2;
        for ( i7 = 0; i7 < v60; ++i7 )
        {
          v32 = v78[3] + (v78[2] << 8);
          if ( v32 )
          {
            if ( v32 != 0xFFFF )
            {
              v31 = v32 * (unsigned __int16)(v78[1] + (*v78 << 8))
                  + (0xFFFF - v32) * *(unsigned __int16 *)(a3 + 358)
                  + 0x8000;
              *v78 = (v31 + HIWORD(v31)) >> 24;
              v78[1] = (v31 + HIWORD(v31)) >> 16;
            }
          }
          else
          {
            *v78 = HIBYTE(*(_WORD *)(a3 + 348));
            v78[1] = *(_WORD *)(a3 + 348);
          }
          result = i7 + 1;
          v78 += 4;
        }
      }
      break;
    case 6:
      if ( *(_BYTE *)(a1 + 9) == 8 )
      {
        if ( v61 && v59 && v49 )
        {
          v79 = a2;
          for ( i8 = 0; ; ++i8 )
          {
            result = i8;
            if ( i8 >= v60 )
              break;
            v30 = v79[3];
            if ( v30 == 255 )
            {
              *v79 = *(_BYTE *)(v49 + *v79);
              v79[1] = *(_BYTE *)(v49 + v79[1]);
              v79[2] = *(_BYTE *)(v49 + v79[2]);
            }
            else if ( v30 )
            {
              v26 = v30 * *(unsigned __int8 *)(v61 + *v79) + (255 - v30) * *(_WORD *)(a3 + 352) + 128;
              v27 = (unsigned __int16)(((int)v26 >> 8) + v26) >> 8;
              if ( !v57 )
                v27 = *(_BYTE *)(v59 + v27);
              *v79 = v27;
              v25 = v30 * *(unsigned __int8 *)(v61 + v79[1]) + (255 - v30) * *(_WORD *)(a3 + 354) + 128;
              v28 = (unsigned __int16)(((int)v25 >> 8) + v25) >> 8;
              if ( !v57 )
                v28 = *(_BYTE *)(v59 + v28);
              v79[1] = v28;
              v24 = v30 * *(unsigned __int8 *)(v61 + v79[2]) + (255 - v30) * *(_WORD *)(a3 + 356) + 128;
              v29 = (unsigned __int16)(((int)v24 >> 8) + v24) >> 8;
              if ( !v57 )
                v29 = *(_BYTE *)(v59 + v29);
              v79[2] = v29;
            }
            else
            {
              *v79 = *(_BYTE *)(a3 + 342);
              v79[1] = *(_BYTE *)(a3 + 344);
              v79[2] = *(_BYTE *)(a3 + 346);
            }
            v79 += 4;
          }
        }
        else
        {
          v80 = a2;
          for ( i9 = 0; i9 < v60; ++i9 )
          {
            v23 = v80[3];
            if ( v23 )
            {
              if ( v23 != 255 )
              {
                v22 = v23 * *v80 + (255 - v23) * *(_WORD *)(a3 + 342) + 128;
                *v80 = (unsigned __int16)(((int)v22 >> 8) + v22) >> 8;
                v21 = v23 * v80[1] + (255 - v23) * *(_WORD *)(a3 + 344) + 128;
                v80[1] = (unsigned __int16)(((int)v21 >> 8) + v21) >> 8;
                v20 = v23 * v80[2] + (255 - v23) * *(_WORD *)(a3 + 346) + 128;
                v80[2] = (unsigned __int16)(((int)v20 >> 8) + v20) >> 8;
              }
            }
            else
            {
              *v80 = *(_BYTE *)(a3 + 342);
              v80[1] = *(_BYTE *)(a3 + 344);
              v80[2] = *(_BYTE *)(a3 + 346);
            }
            result = i9 + 1;
            v80 += 4;
          }
        }
      }
      else if ( v58 && v104 && v55 )
      {
        v81 = a2;
        for ( i10 = 0; i10 < v60; ++i10 )
        {
          v19 = v81[7] + (v81[6] << 8);
          if ( v19 == 0xFFFF )
          {
            v16 = *(_WORD *)(*(_DWORD *)(v58 + 4 * ((int)v81[1] >> v56)) + 2 * *v81);
            *v81 = HIBYTE(v16);
            v81[1] = v16;
            v17 = *(_WORD *)(*(_DWORD *)(v58 + 4 * ((int)v81[3] >> v56)) + 2 * v81[2]);
            v81[2] = HIBYTE(v17);
            v81[3] = v17;
            v18 = *(_WORD *)(*(_DWORD *)(v58 + 4 * ((int)v81[5] >> v56)) + 2 * v81[4]);
            v81[4] = HIBYTE(v18);
            v81[5] = v18;
          }
          else if ( v19 )
          {
            v12 = v19 * *(unsigned __int16 *)(*(_DWORD *)(v55 + 4 * ((int)v81[1] >> v56)) + 2 * *v81)
                + (0xFFFF - v19) * *(unsigned __int16 *)(a3 + 352)
                + 0x8000;
            v13 = (v12 + HIWORD(v12)) >> 16;
            if ( !v57 )
              v13 = *(_WORD *)(*(_DWORD *)(v104 + 4 * ((int)(unsigned __int8)v13 >> v56)) + 2 * ((int)v13 >> 8));
            *v81 = HIBYTE(v13);
            v81[1] = v13;
            v11 = v19 * *(unsigned __int16 *)(*(_DWORD *)(v55 + 4 * ((int)v81[3] >> v56)) + 2 * v81[2])
                + (0xFFFF - v19) * *(unsigned __int16 *)(a3 + 354)
                + 0x8000;
            v14 = (v11 + HIWORD(v11)) >> 16;
            if ( !v57 )
              v14 = *(_WORD *)(*(_DWORD *)(v104 + 4 * ((int)(unsigned __int8)v14 >> v56)) + 2 * ((int)v14 >> 8));
            v81[2] = HIBYTE(v14);
            v81[3] = v14;
            v10 = v19 * *(unsigned __int16 *)(*(_DWORD *)(v55 + 4 * ((int)v81[5] >> v56)) + 2 * v81[4])
                + (0xFFFF - v19) * *(unsigned __int16 *)(a3 + 356)
                + 0x8000;
            v15 = (v10 + HIWORD(v10)) >> 16;
            if ( !v57 )
              v15 = *(_WORD *)(*(_DWORD *)(v104 + 4 * ((int)(unsigned __int8)v15 >> v56)) + 2 * ((int)v15 >> 8));
            v81[4] = HIBYTE(v15);
            v81[5] = v15;
          }
          else
          {
            *v81 = HIBYTE(*(_WORD *)(a3 + 342));
            v81[1] = *(_WORD *)(a3 + 342);
            v81[2] = HIBYTE(*(_WORD *)(a3 + 344));
            v81[3] = *(_WORD *)(a3 + 344);
            v81[4] = HIBYTE(*(_WORD *)(a3 + 346));
            v81[5] = *(_WORD *)(a3 + 346);
          }
          result = (int)(v81 + 8);
          v81 += 8;
        }
      }
      else
      {
        v82 = a2;
        for ( i11 = 0; ; ++i11 )
        {
          result = i11;
          if ( i11 >= v60 )
            break;
          v9 = v82[7] + (v82[6] << 8);
          if ( v9 )
          {
            if ( v9 != 0xFFFF )
            {
              v7 = v82[3] + (v82[2] << 8);
              v8 = v82[5] + (v82[4] << 8);
              v6 = v9 * (unsigned __int16)(v82[1] + (*v82 << 8))
                 + (0xFFFF - v9) * *(unsigned __int16 *)(a3 + 342)
                 + 0x8000;
              *v82 = (v6 + HIWORD(v6)) >> 24;
              v82[1] = (v6 + HIWORD(v6)) >> 16;
              v5 = v9 * v7 + (0xFFFF - v9) * *(unsigned __int16 *)(a3 + 344) + 0x8000;
              v82[2] = (v5 + HIWORD(v5)) >> 24;
              v82[3] = (v5 + HIWORD(v5)) >> 16;
              v4 = v9 * v8 + (0xFFFF - v9) * *(unsigned __int16 *)(a3 + 346) + 0x8000;
              v82[4] = (v4 + HIWORD(v4)) >> 24;
              v82[5] = (v4 + HIWORD(v4)) >> 16;
            }
          }
          else
          {
            *v82 = HIBYTE(*(_WORD *)(a3 + 342));
            v82[1] = *(_WORD *)(a3 + 342);
            v82[2] = HIBYTE(*(_WORD *)(a3 + 344));
            v82[3] = *(_WORD *)(a3 + 344);
            v82[4] = HIBYTE(*(_WORD *)(a3 + 346));
            v82[5] = *(_WORD *)(a3 + 346);
          }
          v82 += 8;
        }
      }
      break;
    default:
      return result;
  }
  return result;
}
