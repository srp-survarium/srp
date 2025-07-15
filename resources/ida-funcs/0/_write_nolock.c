int __usercall _write_nolock@<eax>(char a1@<bl>, int a2@<edi>, int fh, char *buf, unsigned int cnt)
{
  stlp_std::ioinfo **v6; // esi
  int v7; // edi
  char *v8; // eax
  char v9; // bl
  _tiddata *v10; // eax
  UINT ConsoleCP; // eax
  char *v12; // ebx
  unsigned __int8 v13; // cl
  stlp_std::ioinfo **v14; // esi
  int v15; // eax
  int v16; // eax
  DWORD v17; // eax
  signed int v18; // esi
  stlp_std::ioinfo *v19; // eax
  int v20; // esi
  stlp_std::ioinfo *v21; // ecx
  char v22; // dl
  HANDLE *v23; // eax
  unsigned int v24; // ecx
  char *v25; // eax
  char *v26; // edx
  char v27; // dl
  signed int v28; // ebx
  unsigned int v29; // ecx
  char *v30; // eax
  char *v31; // edx
  __int16 v32; // dx
  signed int v33; // ebx
  unsigned int v34; // ecx
  wchar_t *v35; // eax
  wchar_t v36; // dx
  int v37; // esi
  int v38; // ebx
  void *v39; // [esp-10h] [ebp-1AF8h]
  unsigned int Mode; // [esp+4h] [ebp-1AE4h] BYREF
  BOOL v41; // [esp+8h] [ebp-1AE0h]
  char v42; // [esp+Fh] [ebp-1AD9h]
  stlp_std::ioinfo **v43; // [esp+10h] [ebp-1AD8h]
  unsigned int v44; // [esp+14h] [ebp-1AD4h] BYREF
  int v45; // [esp+18h] [ebp-1AD0h]
  char *s; // [esp+1Ch] [ebp-1ACCh]
  unsigned int v47; // [esp+20h] [ebp-1AC8h]
  unsigned int NumberOfBytesWritten; // [esp+24h] [ebp-1AC4h] BYREF
  wchar_t pwc[2]; // [esp+28h] [ebp-1AC0h] BYREF
  char *v50; // [esp+2Ch] [ebp-1ABCh]
  char Buffer[1704]; // [esp+30h] [ebp-1AB8h] BYREF
  char v52[3416]; // [esp+6D8h] [ebp-1410h] BYREF
  wchar_t WideCharStr[854]; // [esp+1430h] [ebp-6B8h] BYREF
  char MultiByteStr[8]; // [esp+1ADCh] [ebp-Ch] BYREF

  s = buf;
  v47 = 0;
  v45 = 0;
  if ( !cnt )
    return 0;
  if ( !buf )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return -1;
  }
  v6 = &__pioinfo[fh >> 5];
  v7 = (fh & 0x1F) << 6;
  v8 = (char *)*v6 + v7;
  v9 = (char)(2 * v8[36]) >> 1;
  v43 = v6;
  v42 = v9;
  if ( (v9 == 2 || v9 == 1) && (cnt & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(v9, v7, 0);
    return -1;
  }
  if ( (v8[4] & 0x20) != 0 )
    _lseeki64_nolock(v9, v7, fh, 0, 2u);
  if ( _isatty(v9, v7, fh) )
  {
    if ( *(&(*v6)->osfile + v7) < 0 )
    {
      v10 = _getptd();
      v39 = *(void **)((char *)&(*v6)->osfhnd + v7);
      v41 = v10->ptlocinfo->lc_handle[2] == 0;
      if ( GetConsoleMode(v39, &Mode) )
      {
        if ( !v41 || v9 )
        {
          ConsoleCP = GetConsoleCP();
          v12 = s;
          Mode = ConsoleCP;
          NumberOfBytesWritten = 0;
          v50 = 0;
          while ( 1 )
          {
            if ( v42 )
            {
              if ( v42 == 1 || v42 == 2 )
              {
                v20 = *(unsigned __int16 *)v12;
                v12 += 2;
                v50 += 2;
                *(_DWORD *)pwc = v20;
                v41 = (_WORD)v20 == 10;
              }
              if ( v42 == 1 || v42 == 2 )
              {
                if ( _putwch_nolock(pwc[0]) != pwc[0] )
                  goto LABEL_85;
                v47 += 2;
                if ( v41 )
                {
                  wcscpy(pwc, L"\r");
                  if ( _putwch_nolock(0xDu) != pwc[0] )
                    goto LABEL_85;
                  ++v47;
                  ++v45;
                }
              }
              goto LABEL_42;
            }
            v13 = *v12;
            v14 = v43;
            v41 = *v12 == 10;
            v15 = (int)*v43 + v7;
            if ( *(_DWORD *)(v15 + 56) )
            {
              MultiByteStr[0] = *(_BYTE *)(v15 + 52);
              MultiByteStr[1] = v13;
              *(_DWORD *)(v15 + 56) = 0;
              v16 = mbtowc(pwc, MultiByteStr, 2);
            }
            else
            {
              if ( isleadbyte(v13) )
              {
                if ( cnt + s - v12 <= 1 )
                {
                  v21 = *v14;
                  v22 = *v12;
                  ++v47;
                  *((_BYTE *)&v21[1].lock.LockCount + v7) = v22;
                  *(int *)((char *)&(*v14)[1].lock.RecursionCount + v7) = 1;
                  goto LABEL_86;
                }
                if ( mbtowc(pwc, v12, 2) == -1 )
                  goto LABEL_86;
                ++v12;
                ++v50;
                goto LABEL_26;
              }
              v16 = mbtowc(pwc, v12, 1);
            }
            if ( v16 == -1 )
              goto LABEL_86;
LABEL_26:
            ++v12;
            ++v50;
            v17 = WideCharToMultiByte(Mode, 0, pwc, 1, MultiByteStr, 5, 0, 0);
            v18 = v17;
            if ( !v17 )
              goto LABEL_86;
            if ( !WriteFile(*(HANDLE *)((char *)&(*v43)->osfhnd + v7), MultiByteStr, v17, &NumberOfBytesWritten, 0) )
              goto LABEL_85;
            v47 = (unsigned int)&v50[v45];
            if ( (int)NumberOfBytesWritten < v18 )
              goto LABEL_86;
            if ( v41 )
            {
              v19 = *v43;
              MultiByteStr[0] = 13;
              if ( !WriteFile(*(HANDLE *)((char *)&v19->osfhnd + v7), MultiByteStr, 1u, &NumberOfBytesWritten, 0) )
                goto LABEL_85;
              if ( (int)NumberOfBytesWritten < 1 )
                goto LABEL_86;
              ++v45;
              ++v47;
            }
LABEL_42:
            if ( (unsigned int)v50 >= cnt )
              goto LABEL_86;
          }
        }
      }
    }
  }
  v23 = (HANDLE *)((char *)*v6 + v7);
  if ( *((char *)v23 + 4) >= 0 )
  {
    if ( WriteFile(*v23, s, cnt, &v44, 0) )
    {
      *(_DWORD *)pwc = 0;
      v47 = v44;
      goto LABEL_86;
    }
  }
  else
  {
    *(_DWORD *)pwc = 0;
    if ( v9 )
    {
      v50 = s;
      if ( v9 == 2 )
      {
        while ( 1 )
        {
          NumberOfBytesWritten = 0;
          v29 = v50 - s;
          v30 = Buffer;
          do
          {
            if ( v29 >= cnt )
              break;
            v31 = v50;
            v50 += 2;
            v32 = *(_WORD *)v31;
            v29 += 2;
            if ( v32 == 10 )
            {
              v45 += 2;
              *(_WORD *)v30 = 13;
              v30 += 2;
              NumberOfBytesWritten += 2;
            }
            NumberOfBytesWritten += 2;
            *(_WORD *)v30 = v32;
            v30 += 2;
          }
          while ( NumberOfBytesWritten < 0x13FE );
          v33 = v30 - Buffer;
          if ( !WriteFile(*(HANDLE *)((char *)&(*v6)->osfhnd + v7), Buffer, v30 - Buffer, &v44, 0) )
            break;
          v47 += v44;
          if ( (int)v44 < v33 || v50 - s >= cnt )
            goto LABEL_86;
          v6 = v43;
        }
      }
      else
      {
        while ( 1 )
        {
          NumberOfBytesWritten = 0;
          v34 = v50 - s;
          v35 = WideCharStr;
          do
          {
            if ( v34 >= cnt )
              break;
            v36 = *(_WORD *)v50;
            v50 += 2;
            v34 += 2;
            if ( v36 == 10 )
            {
              *v35++ = 13;
              NumberOfBytesWritten += 2;
            }
            NumberOfBytesWritten += 2;
            *v35++ = v36;
          }
          while ( NumberOfBytesWritten < 0x6A8 );
          v37 = 0;
          v38 = WideCharToMultiByte(0xFDE9u, 0, WideCharStr, v35 - WideCharStr, v52, 3413, 0, 0);
          if ( !v38 )
            break;
          while ( WriteFile(*(HANDLE *)((char *)&(*v43)->osfhnd + v7), &v52[v37], v38 - v37, &v44, 0) )
          {
            v37 += v44;
            if ( v38 <= v37 )
              goto LABEL_80;
          }
          *(_DWORD *)pwc = GetLastError();
LABEL_80:
          if ( v38 <= v37 )
          {
            v47 = v50 - s;
            if ( v50 - s < cnt )
              continue;
          }
          goto LABEL_86;
        }
      }
    }
    else
    {
      NumberOfBytesWritten = (unsigned int)s;
      while ( 1 )
      {
        v50 = 0;
        v24 = NumberOfBytesWritten - (_DWORD)s;
        v25 = Buffer;
        do
        {
          if ( v24 >= cnt )
            break;
          v26 = (char *)NumberOfBytesWritten++;
          v27 = *v26;
          ++v24;
          if ( v27 == 10 )
          {
            ++v45;
            *v25++ = 13;
            ++v50;
          }
          *v25++ = v27;
          ++v50;
        }
        while ( (unsigned int)v50 < 0x13FF );
        v28 = v25 - Buffer;
        if ( !WriteFile(*(HANDLE *)((char *)&(*v6)->osfhnd + v7), Buffer, v25 - Buffer, &v44, 0) )
          break;
        v47 += v44;
        if ( (int)v44 < v28 || NumberOfBytesWritten - (unsigned int)s >= cnt )
          goto LABEL_86;
        v6 = v43;
      }
    }
  }
LABEL_85:
  *(_DWORD *)pwc = GetLastError();
LABEL_86:
  if ( !v47 )
  {
    if ( *(_DWORD *)pwc )
    {
      if ( *(_DWORD *)pwc == 5 )
      {
        *_errno() = 9;
        *__doserrno() = 5;
      }
      else
      {
        _dosmaperr(*(unsigned int *)pwc);
      }
    }
    else
    {
      if ( (*(&(*v43)->osfile + v7) & 0x40) != 0 && *s == 26 )
        return 0;
      *_errno() = 28;
      *__doserrno() = 0;
    }
    return -1;
  }
  return v47 - v45;
}
