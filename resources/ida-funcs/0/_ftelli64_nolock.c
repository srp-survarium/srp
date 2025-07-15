unsigned int __usercall _ftelli64_nolock@<eax>(int a1@<ebx>, int a2@<edi>, _iobuf *str)
{
  int v3; // ebx
  __int64 v4; // rax
  int v5; // edi
  int v7; // ebx
  char *v8; // eax
  char *ptr; // ecx
  unsigned int v10; // edi
  int flag; // edx
  int v12; // edx
  int v13; // esi
  char *v14; // eax
  int v15; // edx
  unsigned int v16; // ebx
  unsigned __int8 *v17; // eax
  unsigned __int8 *v18; // edx
  char *i; // edx
  int cnt; // edx
  unsigned int bufsiz; // edi
  int v22; // edx
  char *base; // eax
  char *v24; // ecx
  bool v25; // zf
  int v26; // edx
  int v27; // ecx
  unsigned int v28; // [esp+Ch] [ebp-1020h]
  stlp_std::ioinfo **v29; // [esp+10h] [ebp-101Ch]
  int fh; // [esp+14h] [ebp-1018h]
  __int64 pos; // [esp+18h] [ebp-1014h]
  unsigned int NumberOfBytesRead; // [esp+20h] [ebp-100Ch] BYREF
  char v33; // [esp+27h] [ebp-1005h]
  _BYTE Buffer[4096]; // [esp+28h] [ebp-1004h] BYREF

  v3 = _fileno(a1, a2, str);
  fh = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  LODWORD(v4) = _lseeki64(v3, v3, 0, 1u);
  v5 = v4;
  pos = v4;
  if ( v4 < 0 )
    return -1;
  v29 = &__pioinfo[v3 >> 5];
  v7 = (v3 & 0x1F) << 6;
  v8 = (char *)*v29 + v7;
  v25 = (str->_flag & 0x108) == 0;
  v33 = (char)(2 * v8[36]) >> 1;
  if ( v25 )
    return v5 - str->_cnt;
  ptr = str->_ptr;
  v10 = str->_ptr - str->_base;
  flag = str->_flag;
  NumberOfBytesRead = v10;
  if ( (flag & 3) != 0 )
  {
    if ( v33 == 1 && *((_DWORD *)v8 + 12) )
    {
      v28 = v10 >> 1;
      if ( !str->_cnt )
        return pos;
      v13 = _lseeki64(v7, fh, *((_QWORD *)v8 + 5), 0);
      v14 = (char *)*v29 + v7;
      if ( v13 == *((_DWORD *)v14 + 10) && v12 == *((_DWORD *)v14 + 11) )
      {
        if ( ReadFile(*(HANDLE *)v14, Buffer, 0x1000u, &NumberOfBytesRead, 0) )
        {
          _lseeki64(v7, fh, pos, 0);
          if ( v15 >= 0 )
          {
            v16 = v10 >> 1;
            if ( v28 <= NumberOfBytesRead )
            {
              v17 = Buffer;
              if ( v28 )
              {
                v18 = &Buffer[NumberOfBytesRead];
                do
                {
                  --v16;
                  if ( v17 >= v18 )
                    break;
                  if ( *v17 == 13 )
                  {
                    if ( v17 < v18 - 1 && v17[1] == 10 )
                      ++v17;
                  }
                  else
                  {
                    v17 += _lookuptrailbytes[*v17];
                  }
                  ++v17;
                }
                while ( v16 );
              }
              return v13 + v17 - Buffer;
            }
          }
        }
      }
      return -1;
    }
    if ( v8[4] < 0 )
    {
      for ( i = str->_base; i < ptr; ++i )
      {
        if ( *i == 10 )
          ++NumberOfBytesRead;
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( !pos )
    return NumberOfBytesRead;
  if ( (str->_flag & 1) != 0 )
  {
    cnt = str->_cnt;
    if ( cnt )
    {
      bufsiz = cnt + ptr - str->_base;
      if ( v8[4] < 0 )
      {
        if ( _lseeki64(v7, fh, 0, 2u) == (_DWORD)pos && v22 == HIDWORD(pos) )
        {
          base = str->_base;
          v24 = &base[bufsiz];
          while ( base < v24 )
          {
            if ( *base == 10 )
              ++bufsiz;
            ++base;
          }
          v25 = (str->_flag & 0x2000) == 0;
        }
        else
        {
          _lseeki64(v7, fh, pos, 0);
          if ( v26 < 0 )
            return -1;
          if ( bufsiz > 0x200 || (v27 = str->_flag, (v27 & 8) == 0) || (bufsiz = 512, (v27 & 0x400) != 0) )
            bufsiz = str->_bufsiz;
          v25 = (*(&(*v29)->osfile + v7) & 4) == 0;
        }
        if ( !v25 )
          ++bufsiz;
      }
      if ( v33 == 1 )
        bufsiz >>= 1;
      LODWORD(pos) = pos - bufsiz;
    }
    else
    {
      NumberOfBytesRead = 0;
    }
  }
  if ( v33 == 1 )
    NumberOfBytesRead >>= 1;
  return pos + NumberOfBytesRead;
}
