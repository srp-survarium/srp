void __cdecl dopr(
        char **sbuffer,
        char **buffer,
        unsigned int *maxlen,
        unsigned int *retlen,
        int *truncated,
        char *format)
{
  char *args; // ecx
  char v7; // bl
  const char *v8; // edi
  char *v9; // ebp
  char *v10; // esi
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
  double fvalue; // st7
  void *v26; // esp
  int v27; // eax
  char *v28; // eax
  unsigned int *v29; // eax
  __int64 v30; // [esp-4h] [ebp-4Ch]
  unsigned int fvalue_4; // [esp+4h] [ebp-44h]
  int v32; // [esp+8h] [ebp-40h]
  int v33; // [esp+Ch] [ebp-3Ch]
  char v34; // [esp+10h] [ebp-38h]
  char *v35; // [esp+24h] [ebp-24h]
  int flags; // [esp+28h] [ebp-20h]
  char flagsa; // [esp+28h] [ebp-20h]
  unsigned int currlen; // [esp+2Ch] [ebp-1Ch] BYREF
  int max; // [esp+30h] [ebp-18h]
  int v40; // [esp+34h] [ebp-14h]
  int c; // [esp+38h] [ebp-10h]
  int min; // [esp+3Ch] [ebp-Ch]
  int v43; // [esp+40h] [ebp-8h]
  int v44; // [esp+44h] [ebp-4h]
  char *v45; // [esp+60h] [ebp+18h]

  v7 = *format;
  v8 = format + 1;
  v9 = args - 4;
  v10 = args - 8;
  currlen = 0;
  v35 = args - 8;
LABEL_2:
  max = -1;
  flags = 0;
  v40 = 0;
  min = 0;
  c = 0;
LABEL_3:
  v45 = (char *)v8;
  while ( v7 )
  {
    v11 = buffer;
    v12 = maxlen;
    if ( !buffer && currlen >= *maxlen )
      goto LABEL_14;
    switch ( c )
    {
      case 0:
        if ( v7 == 37 )
        {
          c = 1;
        }
        else
        {
          doapr_outch(sbuffer, buffer, maxlen, &currlen, v7);
          v10 = v35;
          v8 = v45;
        }
        v7 = *v8++;
        v45 = (char *)v8;
        goto LABEL_12;
      case 1:
        switch ( v7 )
        {
          case ' ':
            flags |= 4u;
            v7 = *v8++;
            goto LABEL_3;
          case '#':
            flags |= 8u;
            v7 = *v8++;
            goto LABEL_3;
          case '+':
            flags |= 2u;
            v7 = *v8++;
            goto LABEL_3;
          case '-':
            flags |= 1u;
            v7 = *v8++;
            goto LABEL_3;
          case '0':
            flags |= 0x10u;
            v7 = *v8++;
            goto LABEL_3;
          default:
            c = 2;
            break;
        }
        continue;
      case 2:
        if ( isdigit((unsigned __int8)v7) )
        {
          v14 = v7;
          v7 = *v8;
          min = v14 + 10 * min - 48;
          ++v8;
          goto LABEL_3;
        }
        if ( v7 == 42 )
        {
          v7 = *v8;
          v15 = *((_DWORD *)v9 + 1);
          v9 += 4;
          v10 += 4;
          ++v8;
          v35 = v10;
          min = v15;
          v45 = (char *)v8;
        }
        c = 3;
        continue;
      case 3:
        if ( v7 != 46 )
          goto LABEL_37;
        v7 = *v8;
        c = 4;
        ++v8;
        goto LABEL_3;
      case 4:
        if ( isdigit((unsigned __int8)v7) )
        {
          v16 = max;
          if ( max < 0 )
          {
            max = 0;
            v16 = 0;
          }
          v17 = 5 * v16;
          v18 = v7;
          v7 = *v8;
          max = v18 + 2 * v17 - 48;
          ++v8;
          goto LABEL_3;
        }
        if ( v7 == 42 )
        {
          v7 = *v8;
          v19 = *((_DWORD *)v9 + 1);
          v9 += 4;
          v10 += 4;
          ++v8;
          v35 = v10;
          max = v19;
          v45 = (char *)v8;
        }
LABEL_37:
        c = 5;
        break;
      case 5:
        switch ( v7 )
        {
          case 'L':
            v7 = *v8++;
            v40 = 3;
            v45 = (char *)v8;
            goto LABEL_46;
          case 'h':
            v7 = *v8++;
            v40 = 1;
            v45 = (char *)v8;
            c = 6;
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
            v45 = (char *)v8;
            c = 6;
            break;
          case 'q':
            v7 = *v8++;
            v40 = 4;
            v45 = (char *)v8;
            c = 6;
            break;
          default:
LABEL_46:
            c = 6;
            break;
        }
        continue;
      case 6:
        c = v7;
        switch ( v7 )
        {
          case '%':
            doapr_outch(sbuffer, buffer, maxlen, &currlen, c);
            v7 = *v45;
            v10 = v35;
            v8 = v45 + 1;
            goto LABEL_2;
          case 'E':
          case 'G':
          case 'e':
          case 'g':
            v7 = *v8;
            v10 += 8;
            v9 += 8;
            ++v8;
            v35 = v10;
            goto LABEL_2;
          case 'X':
            LOBYTE(flags) = flags | 0x20;
            goto $LN104;
          case 'c':
            v27 = *((_DWORD *)v9 + 1);
            v9 += 4;
            v35 = v10 + 4;
            doapr_outch(sbuffer, buffer, maxlen, &currlen, v27);
            v7 = *v45;
            v10 += 4;
            v8 = v45 + 1;
            goto LABEL_2;
          case 'd':
          case 'i':
            if ( v40 == 1 )
            {
              v20 = *((__int16 *)v9 + 2);
              v10 += 4;
              v9 += 4;
            }
            else
            {
              if ( v40 == 4 )
              {
                v21 = *((_DWORD *)v10 + 3);
                v20 = *((_DWORD *)v10 + 2);
                v10 += 8;
                v9 += 8;
                v44 = v21;
                goto LABEL_54;
              }
              v20 = *((_DWORD *)v9 + 1);
              v10 += 4;
              v9 += 4;
            }
            v44 = v20 >> 31;
            v11 = buffer;
LABEL_54:
            v34 = flags;
            v33 = max;
            v32 = min;
            fvalue_4 = 10;
            v35 = v10;
            HIDWORD(v30) = v44;
            goto LABEL_55;
          case 'f':
            fvalue = *((double *)v10 + 1);
            v10 += 8;
            v35 = v10;
            v9 += 8;
            v26 = alloca(8);
            fmtfp(sbuffer, buffer, &currlen, maxlen, fvalue, min, max, flags);
            v7 = *v8++;
            goto LABEL_2;
          case 'n':
            v10 += 4;
            v9 += 4;
            v35 = v10;
            if ( v40 == 1 )
            {
              **(_WORD **)v9 = currlen;
              v7 = *v8++;
            }
            else
            {
              if ( v40 == 4 )
              {
                v29 = *(unsigned int **)v9;
                *v29 = currlen;
                v29[1] = 0;
              }
              else
              {
                **(_DWORD **)v9 = currlen;
              }
              v7 = *v8++;
            }
            goto LABEL_2;
          case 'o':
          case 'u':
          case 'x':
$LN104:
            flagsa = flags | 0x40;
            if ( v40 == 1 )
            {
              v22 = *((unsigned __int16 *)v9 + 2);
              v10 += 4;
              v9 += 4;
              v44 = 0;
              v11 = buffer;
            }
            else
            {
              if ( v40 == 4 )
              {
                v23 = *((_DWORD *)v10 + 2);
                v10 += 8;
                v43 = v23;
                v9 += 8;
                v44 = *((_DWORD *)v10 + 1);
                goto LABEL_64;
              }
              v22 = *((_DWORD *)v9 + 1);
              v10 += 4;
              v9 += 4;
              v44 = 0;
            }
            v43 = v22;
LABEL_64:
            v35 = v10;
            if ( v7 == 111 )
              v24 = 8;
            else
              v24 = v7 != 117 ? 16 : 10;
            v34 = flagsa;
            v33 = max;
            v32 = min;
            fvalue_4 = v24;
            HIDWORD(v30) = v44;
            v20 = v43;
LABEL_55:
            LODWORD(v30) = v20;
            fmtint(&currlen, maxlen, sbuffer, v11, v30, fvalue_4, v32, v33, v34);
LABEL_56:
            v7 = *v8++;
            break;
          case 'p':
            v10 += 4;
            v9 += 4;
            v35 = v10;
            fmtint(&currlen, maxlen, sbuffer, buffer, *(int *)v9, 0x10u, min, max, flags | 8);
            goto LABEL_56;
          case 's':
            v28 = (char *)*((_DWORD *)v9 + 1);
            v10 += 4;
            v9 += 4;
            v35 = v10;
            if ( max < 0 )
            {
              if ( buffer )
                max = 0x7FFFFFFF;
              else
                max = *maxlen;
            }
            fmtstr(maxlen, buffer, sbuffer, &currlen, v28, flags, min, max);
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
        if ( c == 7 )
          goto LABEL_13;
        continue;
    }
  }
LABEL_13:
  v12 = maxlen;
  v11 = buffer;
LABEL_14:
  v13 = *v12 - 1 >= currlen;
  *truncated = *v12 - 1 < currlen;
  if ( !v13 )
    currlen = *v12 - 1;
  doapr_outch(sbuffer, v11, v12, &currlen, 0);
  *retlen = currlen - 1;
}
