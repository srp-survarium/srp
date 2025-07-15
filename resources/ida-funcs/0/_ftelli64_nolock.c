unsigned int __usercall _ftelli64_nolock@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *str)
{
  int v3; // ebx
  __int64 v4; // rax
  int v5; // edi
  int v7; // ebx
  char *v8; // eax
  char *ptr; // ecx
  unsigned int v10; // edi
  int flag; // edx
  __int64 v12; // rax
  unsigned int v13; // esi
  char *v14; // eax
  unsigned int v15; // ebx
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // edx
  char *i; // edx
  int cnt; // edx
  unsigned int bufsiz; // edi
  char *base; // eax
  char *v22; // ecx
  bool v23; // zf
  int v24; // ecx
  unsigned int v25; // [esp+Ch] [ebp-1020h]
  stlp_std::ioinfo **v26; // [esp+10h] [ebp-101Ch]
  int fh; // [esp+14h] [ebp-1018h]
  __int64 pos; // [esp+18h] [ebp-1014h]
  unsigned int NumberOfBytesRead; // [esp+20h] [ebp-100Ch] BYREF
  char v30; // [esp+27h] [ebp-1005h]
  _BYTE Buffer[4096]; // [esp+28h] [ebp-1004h] BYREF

  v3 = _fileno(a1, a2, str);
  fh = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v4 = _lseeki64(v3, 0, 1);
  v5 = v4;
  pos = v4;
  if ( v4 < 0 )
    return -1;
  v26 = &__pioinfo[v3 >> 5];
  v7 = (v3 & 0x1F) << 6;
  v8 = (char *)*v26 + v7;
  v23 = (str->_flag & 0x108) == 0;
  v30 = (char)(2 * v8[36]) >> 1;
  if ( v23 )
    return v5 - str->_cnt;
  ptr = str->_ptr;
  v10 = str->_ptr - str->_base;
  flag = str->_flag;
  NumberOfBytesRead = v10;
  if ( (flag & 3) != 0 )
  {
    if ( v30 == 1 && *((_DWORD *)v8 + 12) )
    {
      v25 = v10 >> 1;
      if ( !str->_cnt )
        return pos;
      v12 = _lseeki64(fh, *((_QWORD *)v8 + 5), 0);
      v13 = v12;
      v14 = (char *)*v26 + v7;
      if ( __PAIR64__(HIDWORD(v12), v13) == *((_QWORD *)v14 + 5) )
      {
        if ( ReadFile(*(HANDLE *)v14, Buffer, 0x1000u, &NumberOfBytesRead, 0) )
        {
          if ( (((unsigned __int64)_lseeki64(fh, pos, 0) >> 32) & 0x80000000) == 0LL )
          {
            v15 = v10 >> 1;
            if ( v25 <= NumberOfBytesRead )
            {
              v16 = Buffer;
              if ( v25 )
              {
                v17 = &Buffer[NumberOfBytesRead];
                do
                {
                  --v15;
                  if ( v16 >= v17 )
                    break;
                  if ( *v16 == 13 )
                  {
                    if ( v16 < v17 - 1 && v16[1] == 10 )
                      ++v16;
                  }
                  else
                  {
                    v16 += _lookuptrailbytes[*v16];
                  }
                  ++v16;
                }
                while ( v15 );
              }
              return v13 + v16 - Buffer;
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
        if ( _lseeki64(fh, 0, 2) == pos )
        {
          base = str->_base;
          v22 = &base[bufsiz];
          while ( base < v22 )
          {
            if ( *base == 10 )
              ++bufsiz;
            ++base;
          }
          v23 = (str->_flag & 0x2000) == 0;
        }
        else
        {
          if ( (((unsigned __int64)_lseeki64(fh, pos, 0) >> 32) & 0x80000000) != 0LL )
            return -1;
          if ( bufsiz > 0x200 || (v24 = str->_flag, (v24 & 8) == 0) || (bufsiz = 512, (v24 & 0x400) != 0) )
            bufsiz = str->_bufsiz;
          v23 = (*(&(*v26)->osfile + v7) & 4) == 0;
        }
        if ( !v23 )
          ++bufsiz;
      }
      if ( v30 == 1 )
        bufsiz >>= 1;
      LODWORD(pos) = pos - bufsiz;
    }
    else
    {
      NumberOfBytesRead = 0;
    }
  }
  if ( v30 == 1 )
    NumberOfBytesRead >>= 1;
  return pos + NumberOfBytesRead;
}
