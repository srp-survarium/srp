unsigned int __usercall _read_nolock@<eax>(int a1@<edi>, int fh, char *inputbuf, unsigned int cnt)
{
  unsigned int v4; // edx
  unsigned int result; // eax
  stlp_std::ioinfo **v6; // edi
  int v7; // esi
  char *v8; // eax
  char v9; // cl
  char *v10; // eax
  __int64 v11; // rax
  stlp_std::ioinfo *v12; // ecx
  char *v13; // ecx
  char v14; // cl
  stlp_std::ioinfo *v15; // ecx
  char v16; // cl
  stlp_std::ioinfo *v17; // ecx
  bool v18; // zf
  char v19; // cl
  stlp_std::ioinfo *v20; // ecx
  stlp_std::ioinfo *v21; // eax
  char *v22; // eax
  char *v23; // ebx
  char v24; // al
  char *v25; // eax
  _BYTE *v26; // ebx
  int v27; // ecx
  int v28; // eax
  char v29; // dl
  char *v30; // ecx
  _BYTE *v31; // ebx
  int v32; // ebx
  DWORD LastError; // eax
  stlp_std::ioinfo *v34; // edx
  BOOL v35; // ecx
  char *v36; // ebx
  __int16 v37; // cx
  char *v38; // esi
  __int16 v39; // [esp-Ch] [ebp-2Ch]
  unsigned int v40; // [esp+4h] [ebp-1Ch]
  unsigned int NumberOfBytesRead; // [esp+8h] [ebp-18h] BYREF
  unsigned int v42; // [esp+Ch] [ebp-14h]
  unsigned int v43; // [esp+10h] [ebp-10h]
  LPCCH lpMultiByteStr; // [esp+14h] [ebp-Ch]
  __int16 v45; // [esp+18h] [ebp-8h] BYREF
  char v46; // [esp+1Eh] [ebp-2h]
  char Buffer; // [esp+1Fh] [ebp-1h] BYREF
  LPCCH size; // [esp+30h] [ebp+10h]
  LPCCH sizea; // [esp+30h] [ebp+10h]

  v4 = cnt;
  v42 = -2;
  v40 = cnt;
  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(0, a1, fh);
    return -1;
  }
  v6 = &__pioinfo[fh >> 5];
  v7 = (fh & 0x1F) << 6;
  v8 = (char *)*v6 + v7;
  v9 = v8[4];
  if ( (v9 & 1) == 0 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_19:
    _invalid_parameter(0, (int)v6, v7);
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
    goto LABEL_18;
  v43 = 0;
  if ( !cnt || (v9 & 2) != 0 )
    return 0;
  if ( !inputbuf )
    goto LABEL_18;
  v46 = (char)(2 * v8[36]) >> 1;
  if ( v46 != 1 )
  {
    if ( v46 != 2 )
    {
LABEL_16:
      v10 = inputbuf;
      lpMultiByteStr = inputbuf;
      goto LABEL_26;
    }
    if ( (cnt & 1) == 0 )
    {
      cnt &= ~1u;
      goto LABEL_16;
    }
LABEL_18:
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_19;
  }
  if ( (cnt & 1) != 0 )
    goto LABEL_18;
  cnt = 4;
  if ( v4 >> 1 >= 4 )
    cnt = v4 >> 1;
  lpMultiByteStr = (LPCCH)_malloc_crt(cnt);
  if ( !lpMultiByteStr )
  {
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  v11 = _lseeki64_nolock(0, (int)v6, fh, 0, 1u);
  v12 = *v6;
  *(_DWORD *)(&v12[1].osfile + v7) = v11;
  v10 = (char *)lpMultiByteStr;
  *(int *)((char *)&v12[1].lockinitflag + v7) = HIDWORD(v11);
LABEL_26:
  v13 = (char *)*v6 + v7;
  if ( (v13[4] & 0x48) != 0 )
  {
    v14 = v13[5];
    if ( v14 != 10 )
    {
      if ( cnt )
      {
        *v10 = v14;
        v15 = *v6;
        ++v10;
        --cnt;
        v43 = 1;
        *(&v15->pipech + v7) = 10;
        if ( v46 )
        {
          v16 = *((_BYTE *)&(*v6)[1].osfhnd + v7 + 1);
          if ( v16 != 10 )
          {
            if ( cnt )
            {
              *v10 = v16;
              v17 = *v6;
              ++v10;
              --cnt;
              v18 = v46 == 1;
              v43 = 2;
              *((_BYTE *)&v17[1].osfhnd + v7 + 1) = 10;
              if ( v18 )
              {
                v19 = *((_BYTE *)&(*v6)[1].osfhnd + v7 + 2);
                if ( v19 != 10 )
                {
                  if ( cnt )
                  {
                    *v10 = v19;
                    v20 = *v6;
                    ++v10;
                    --cnt;
                    v43 = 3;
                    *((_BYTE *)&v20[1].osfhnd + v7 + 2) = 10;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( !ReadFile(*(HANDLE *)((char *)&(*v6)->osfhnd + v7), v10, cnt, &NumberOfBytesRead, 0)
    || (NumberOfBytesRead & 0x80000000) != 0
    || NumberOfBytesRead > cnt )
  {
    LastError = GetLastError();
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
      goto LABEL_93;
    }
    if ( LastError == 109 )
    {
      v42 = 0;
      goto error_return_2;
    }
    goto LABEL_92;
  }
  v21 = *v6;
  v43 += NumberOfBytesRead;
  v22 = &v21->osfile + v7;
  if ( *v22 < 0 )
  {
    if ( v46 != 2 )
    {
      if ( NumberOfBytesRead && *lpMultiByteStr == 10 )
        *v22 |= 4u;
      else
        *v22 &= ~4u;
      v23 = (char *)lpMultiByteStr;
      size = lpMultiByteStr;
      v43 += (unsigned int)lpMultiByteStr;
      if ( (unsigned int)lpMultiByteStr < v43 )
      {
        do
        {
          v24 = *size;
          if ( *size == 26 )
          {
            v25 = &(*v6)->osfile + v7;
            if ( (*v25 & 0x40) != 0 )
              *v23++ = *size;
            else
              *v25 |= 2u;
            break;
          }
          if ( v24 == 13 )
          {
            if ( (unsigned int)size < v43 - 1 )
            {
              if ( size[1] == 10 )
              {
                size += 2;
                goto LABEL_52;
              }
              ++size;
LABEL_63:
              *v23 = 13;
LABEL_64:
              ++v23;
              continue;
            }
            ++size;
            if ( !ReadFile(*(HANDLE *)((char *)&(*v6)->osfhnd + v7), &Buffer, 1u, &NumberOfBytesRead, 0)
              && GetLastError()
              || !NumberOfBytesRead )
            {
              goto LABEL_63;
            }
            if ( (*(&(*v6)->osfile + v7) & 0x48) != 0 )
            {
              if ( Buffer != 10 )
              {
                *v23 = 13;
                *(&(*v6)->pipech + v7) = Buffer;
                goto LABEL_64;
              }
LABEL_52:
              *v23 = 10;
              goto LABEL_64;
            }
            if ( v23 == lpMultiByteStr && Buffer == 10 )
              goto LABEL_52;
            _lseeki64_nolock((int)v23, (int)v6, fh, -1, 1u);
            if ( Buffer != 10 )
              goto LABEL_63;
          }
          else
          {
            *v23++ = v24;
            ++size;
          }
        }
        while ( (unsigned int)size < v43 );
      }
      v43 = v23 - lpMultiByteStr;
      if ( v46 != 1 || v23 == lpMultiByteStr )
        goto error_return_2;
      v26 = v23 - 1;
      LOBYTE(v27) = *v26;
      if ( (char)*v26 < 0 )
      {
        v28 = 1;
        v27 = (unsigned __int8)v27;
        while ( !_lookuptrailbytes[v27] && v28 <= 4 && v26 >= lpMultiByteStr )
        {
          v27 = (unsigned __int8)*--v26;
          ++v28;
        }
        v29 = *v26;
        if ( !_lookuptrailbytes[(unsigned __int8)*v26] )
        {
          *_errno() = 42;
LABEL_93:
          v42 = -1;
          goto error_return_2;
        }
        if ( _lookuptrailbytes[(unsigned __int8)*v26] + 1 == v28 )
        {
          v26 += v28;
        }
        else
        {
          v30 = (char *)*v6 + v7;
          if ( (v30[4] & 0x48) != 0 )
          {
            v31 = v26 + 1;
            v30[5] = v29;
            if ( v28 >= 2 )
              *((_BYTE *)&(*v6)[1].osfhnd + v7 + 1) = *v31++;
            if ( v28 == 3 )
              *((_BYTE *)&(*v6)[1].osfhnd + v7 + 2) = *v31++;
            v26 = &v31[-v28];
          }
          else
          {
            _lseeki64_nolock((int)v26, (int)v6, fh, -v28, 1u);
          }
        }
      }
      else
      {
        ++v26;
      }
      v32 = v26 - lpMultiByteStr;
      v43 = MultiByteToWideChar(0xFDE9u, 0, lpMultiByteStr, v32, (LPWSTR)inputbuf, v40 >> 1);
      if ( v43 )
      {
        v34 = *v6;
        v35 = v43 != v32;
        v43 *= 2;
        *(_RTL_CRITICAL_SECTION_DEBUG **)((char *)&v34[1].lock.DebugInfo + v7) = (_RTL_CRITICAL_SECTION_DEBUG *)v35;
        goto error_return_2;
      }
      LastError = GetLastError();
LABEL_92:
      _dosmaperr(LastError);
      goto LABEL_93;
    }
    if ( NumberOfBytesRead && *(_WORD *)lpMultiByteStr == 10 )
      *v22 |= 4u;
    else
      *v22 &= ~4u;
    v36 = (char *)lpMultiByteStr;
    sizea = lpMultiByteStr;
    v43 += (unsigned int)lpMultiByteStr;
    if ( (unsigned int)lpMultiByteStr >= v43 )
    {
LABEL_129:
      v43 = v36 - lpMultiByteStr;
      goto error_return_2;
    }
    while ( 1 )
    {
      v37 = *(_WORD *)sizea;
      if ( *(_WORD *)sizea == 26 )
      {
        v38 = &(*v6)->osfile + v7;
        if ( (*v38 & 0x40) != 0 )
        {
          *(_WORD *)v36 = *(_WORD *)sizea;
          v36 += 2;
        }
        else
        {
          *v38 |= 2u;
        }
        goto LABEL_129;
      }
      if ( v37 == 13 )
      {
        if ( (unsigned int)sizea < v43 - 2 )
        {
          if ( *((_WORD *)sizea + 1) == 10 )
          {
            sizea += 4;
            goto LABEL_110;
          }
          sizea += 2;
LABEL_121:
          v39 = 13;
LABEL_122:
          *(_WORD *)v36 = v39;
          goto LABEL_123;
        }
        sizea += 2;
        if ( !ReadFile(*(HANDLE *)((char *)&(*v6)->osfhnd + v7), &v45, 2u, &NumberOfBytesRead, 0) && GetLastError()
          || !NumberOfBytesRead )
        {
          goto LABEL_121;
        }
        if ( (*(&(*v6)->osfile + v7) & 0x48) != 0 )
        {
          if ( v45 != 10 )
          {
            *(_WORD *)v36 = 13;
            *(&(*v6)->pipech + v7) = v45;
            *((_BYTE *)&(*v6)[1].osfhnd + v7 + 1) = HIBYTE(v45);
            *((_BYTE *)&(*v6)[1].osfhnd + v7 + 2) = 10;
LABEL_123:
            v36 += 2;
            goto LABEL_124;
          }
LABEL_110:
          v39 = 10;
          goto LABEL_122;
        }
        if ( v36 == lpMultiByteStr && v45 == 10 )
          goto LABEL_110;
        _lseeki64_nolock((int)v36, (int)v6, fh, -2, 1u);
        if ( v45 != 10 )
          goto LABEL_121;
      }
      else
      {
        *(_WORD *)v36 = v37;
        v36 += 2;
        sizea += 2;
      }
LABEL_124:
      if ( (unsigned int)sizea >= v43 )
        goto LABEL_129;
    }
  }
error_return_2:
  if ( lpMultiByteStr != inputbuf )
    free((void *)lpMultiByteStr);
  result = v42;
  if ( v42 == -2 )
    return v43;
  return result;
}
