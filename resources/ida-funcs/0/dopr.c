void __cdecl dopr(
        const __m128i **sbuffer,
        char **buffer,
        unsigned int *maxlen,
        unsigned int *retlen,
        int *truncated,
        char *format)
{
  int v6; // ecx
  char v7; // bl
  char *v8; // edi
  int *v9; // ebp
  double *v10; // esi
  char **v11; // edx
  unsigned int *v12; // ecx
  bool v13; // zf
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // eax
  double v25; // st7
  void *v26; // esp
  int v27; // eax
  char *v28; // eax
  _DWORD *v29; // eax
  __int64 v30; // [esp-4h] [ebp-4Ch]
  unsigned int v31; // [esp+4h] [ebp-44h]
  int v32; // [esp+8h] [ebp-40h]
  int v33; // [esp+Ch] [ebp-3Ch]
  char v34; // [esp+10h] [ebp-38h]
  double *v35; // [esp+24h] [ebp-24h]
  int v36; // [esp+28h] [ebp-20h]
  char v37; // [esp+28h] [ebp-20h]
  unsigned int v38; // [esp+2Ch] [ebp-1Ch] BYREF
  int v39; // [esp+30h] [ebp-18h]
  int v40; // [esp+34h] [ebp-14h]
  int v41; // [esp+38h] [ebp-10h]
  int v42; // [esp+3Ch] [ebp-Ch]
  int v43; // [esp+40h] [ebp-8h]
  int v44; // [esp+44h] [ebp-4h]
  char *v45; // [esp+60h] [ebp+18h]

  v7 = *format;
  v8 = format + 1;
  v9 = (int *)(v6 - 4);
  v10 = (double *)(v6 - 8);
  v38 = 0;
  v35 = (double *)(v6 - 8);
LABEL_2:
  v39 = -1;
  v36 = 0;
  v40 = 0;
  v42 = 0;
  v41 = 0;
LABEL_3:
  v45 = v8;
  while ( v7 )
  {
    v11 = buffer;
    v12 = maxlen;
    if ( !buffer && v38 >= *maxlen )
      goto LABEL_14;
    switch ( v41 )
    {
      case 0:
        if ( v7 == 37 )
        {
          v41 = 1;
        }
        else
        {
          doapr_outch(sbuffer, buffer, maxlen, &v38, v7);
          v10 = v35;
          v8 = v45;
        }
        v7 = *v8++;
        v45 = v8;
        goto LABEL_12;
      case 1:
        switch ( v7 )
        {
          case ' ':
            v36 |= 4u;
            v7 = *v8++;
            goto LABEL_3;
          case '#':
            v36 |= 8u;
            v7 = *v8++;
            goto LABEL_3;
          case '+':
            v36 |= 2u;
            v7 = *v8++;
            goto LABEL_3;
          case '-':
            v36 |= 1u;
            v7 = *v8++;
            goto LABEL_3;
          case '0':
            v36 |= 0x10u;
            v7 = *v8++;
            goto LABEL_3;
          default:
            v41 = 2;
            break;
        }
        continue;
      case 2:
        if ( isdigit((unsigned __int8)v7) )
        {
          v14 = v7;
          v7 = *v8;
          v42 = v14 + 10 * v42 - 48;
          ++v8;
          goto LABEL_3;
        }
        if ( v7 == 42 )
        {
          v7 = *v8;
          v15 = v9[1];
          ++v9;
          v10 = (double *)((char *)v10 + 4);
          ++v8;
          v35 = v10;
          v42 = v15;
          v45 = v8;
        }
        v41 = 3;
        continue;
      case 3:
        if ( v7 != 46 )
          goto LABEL_37;
        v7 = *v8;
        v41 = 4;
        ++v8;
        goto LABEL_3;
      case 4:
        if ( isdigit((unsigned __int8)v7) )
        {
          v16 = v39;
          if ( v39 < 0 )
          {
            v39 = 0;
            v16 = 0;
          }
          v17 = 5 * v16;
          v18 = v7;
          v7 = *v8;
          v39 = v18 + 2 * v17 - 48;
          ++v8;
          goto LABEL_3;
        }
        if ( v7 == 42 )
        {
          v7 = *v8;
          v19 = v9[1];
          ++v9;
          v10 = (double *)((char *)v10 + 4);
          ++v8;
          v35 = v10;
          v39 = v19;
          v45 = v8;
        }
LABEL_37:
        v41 = 5;
        break;
      case 5:
        switch ( v7 )
        {
          case 'L':
            v7 = *v8++;
            v40 = 3;
            v45 = v8;
            goto LABEL_46;
          case 'h':
            v7 = *v8++;
            v40 = 1;
            v45 = v8;
            v41 = 6;
            break;
          case 'l':
            if ( *v8 == 108 )
            {
              v7 = v8[1];
              v8 += 2;
              v40 = 4;
            }
            else
            {
              v7 = *v8++;
              v40 = 2;
            }
            v45 = v8;
            v41 = 6;
            break;
          case 'q':
            v7 = *v8++;
            v40 = 4;
            v45 = v8;
            v41 = 6;
            break;
          default:
LABEL_46:
            v41 = 6;
            break;
        }
        continue;
      case 6:
        v41 = v7;
        switch ( v7 )
        {
          case '%':
            doapr_outch(sbuffer, buffer, maxlen, &v38, v41);
            v7 = *v45;
            v10 = v35;
            v8 = v45 + 1;
            goto LABEL_2;
          case 'E':
          case 'G':
          case 'e':
          case 'g':
            v7 = *v8;
            ++v10;
            v9 += 2;
            ++v8;
            v35 = v10;
            goto LABEL_2;
          case 'X':
            LOBYTE(v36) = v36 | 0x20;
            goto $LN104_12;
          case 'c':
            v27 = v9[1];
            ++v9;
            v35 = (double *)((char *)v10 + 4);
            doapr_outch(sbuffer, buffer, maxlen, &v38, v27);
            v7 = *v45;
            v10 = (double *)((char *)v10 + 4);
            v8 = v45 + 1;
            goto LABEL_2;
          case 'd':
          case 'i':
            if ( v40 == 1 )
            {
              v20 = *((__int16 *)v9 + 2);
              v10 = (double *)((char *)v10 + 4);
              ++v9;
            }
            else
            {
              if ( v40 == 4 )
              {
                v21 = *((_DWORD *)v10 + 3);
                v20 = *((_DWORD *)v10++ + 2);
                v9 += 2;
                v44 = v21;
                goto LABEL_54;
              }
              v20 = v9[1];
              v10 = (double *)((char *)v10 + 4);
              ++v9;
            }
            v44 = v20 >> 31;
            v11 = buffer;
LABEL_54:
            v34 = v36;
            v33 = v39;
            v32 = v42;
            v31 = 10;
            v35 = v10;
            HIDWORD(v30) = v44;
            goto LABEL_55;
          case 'f':
            v25 = v10[1];
            v35 = ++v10;
            v9 += 2;
            v26 = alloca(8);
            fmtfp(sbuffer, buffer, &v38, maxlen, v25, v42, v39, v36);
            v7 = *v8++;
            goto LABEL_2;
          case 'n':
            v10 = (double *)((char *)v10 + 4);
            ++v9;
            v35 = v10;
            if ( v40 == 1 )
            {
              *(_WORD *)*v9 = v38;
              v7 = *v8++;
            }
            else
            {
              if ( v40 == 4 )
              {
                v29 = (_DWORD *)*v9;
                *v29 = v38;
                v29[1] = 0;
              }
              else
              {
                *(_DWORD *)*v9 = v38;
              }
              v7 = *v8++;
            }
            goto LABEL_2;
          case 'o':
          case 'u':
          case 'x':
$LN104_12:
            v37 = v36 | 0x40;
            if ( v40 == 1 )
            {
              v22 = *((unsigned __int16 *)v9 + 2);
              v10 = (double *)((char *)v10 + 4);
              ++v9;
              v44 = 0;
              v11 = buffer;
            }
            else
            {
              if ( v40 == 4 )
              {
                v23 = *((_DWORD *)v10++ + 2);
                v43 = v23;
                v9 += 2;
                v44 = *((_DWORD *)v10 + 1);
                goto LABEL_64;
              }
              v22 = v9[1];
              v10 = (double *)((char *)v10 + 4);
              ++v9;
              v44 = 0;
            }
            v43 = v22;
LABEL_64:
            v35 = v10;
            if ( v7 == 111 )
              v24 = 8;
            else
              v24 = v7 != 117 ? 16 : 10;
            v34 = v37;
            v33 = v39;
            v32 = v42;
            v31 = v24;
            HIDWORD(v30) = v44;
            v20 = v43;
LABEL_55:
            LODWORD(v30) = v20;
            fmtint(&v38, maxlen, sbuffer, v11, v30, v31, v32, v33, v34);
LABEL_56:
            v7 = *v8++;
            break;
          case 'p':
            v10 = (double *)((char *)v10 + 4);
            ++v9;
            v35 = v10;
            fmtint(&v38, maxlen, sbuffer, buffer, *v9, 0x10u, v42, v39, v36 | 8);
            goto LABEL_56;
          case 's':
            v28 = (char *)v9[1];
            v10 = (double *)((char *)v10 + 4);
            ++v9;
            v35 = v10;
            if ( v39 < 0 )
            {
              if ( buffer )
                v39 = 0x7FFFFFFF;
              else
                v39 = *maxlen;
            }
            fmtstr(maxlen, buffer, sbuffer, &v38, v28, v36, v42, v39);
            v7 = *v8++;
            goto LABEL_2;
          case 'w':
            ++v8;
            goto LABEL_85;
          default:
LABEL_85:
            v7 = *v8++;
            goto LABEL_2;
        }
        goto LABEL_2;
      default:
LABEL_12:
        if ( v41 == 7 )
          goto LABEL_13;
        continue;
    }
  }
LABEL_13:
  v12 = maxlen;
  v11 = buffer;
LABEL_14:
  v13 = *v12 - 1 >= v38;
  *truncated = *v12 - 1 < v38;
  if ( !v13 )
    v38 = *v12 - 1;
  doapr_outch(sbuffer, v11, v12, &v38, 0);
  *retlen = v38 - 1;
}
