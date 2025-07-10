int __cdecl _ftell_nolock(_iobuf *str)
{
  int v3; // eax
  int v4; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v8; // edx
  int cnt; // edx
  stlp_std::ioinfo **v10; // ebx
  int v11; // esi
  char *v12; // eax
  char *v13; // ecx
  bool v14; // zf
  int bufsiz; // eax
  int v16; // ecx
  char *offset; // [esp+8h] [ebp-Ch]
  int filepos; // [esp+Ch] [ebp-8h]
  int fd; // [esp+10h] [ebp-4h]
  unsigned int rdcnt; // [esp+1Ch] [ebp+8h]

  if ( !str )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
  v3 = _fileno(str);
  fd = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v4 = _lseek(v3, 0, 1);
  filepos = v4;
  if ( v4 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v4 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  offset = (char *)(str->_ptr - base);
  if ( (flag & 3) != 0 )
  {
    if ( *(&__pioinfo[fd >> 5]->osfile + 64 * (fd & 0x1F)) < 0 )
    {
      v8 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v8 == 10 )
            ++offset;
          ++v8;
        }
        while ( v8 < ptr );
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( !filepos )
    return (int)offset;
  if ( (str->_flag & 1) == 0 )
    return (int)&offset[filepos];
  cnt = str->_cnt;
  if ( cnt )
  {
    v10 = &__pioinfo[fd >> 5];
    rdcnt = cnt + ptr - base;
    v11 = (fd & 0x1F) << 6;
    if ( *(&(*v10)->osfile + v11) >= 0 )
    {
LABEL_39:
      filepos -= rdcnt;
      return (int)&offset[filepos];
    }
    if ( _lseek(fd, 0, 2) == filepos )
    {
      v12 = str->_base;
      v13 = &v12[rdcnt];
      while ( v12 < v13 )
      {
        if ( *v12 == 10 )
          ++rdcnt;
        ++v12;
      }
      v14 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v14 )
        ++rdcnt;
      goto LABEL_39;
    }
    if ( _lseek(fd, filepos, 0) >= 0 )
    {
      bufsiz = 512;
      if ( rdcnt > 0x200 || (v16 = str->_flag, (v16 & 8) == 0) || (v16 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      rdcnt = bufsiz;
      v14 = (*(&(*v10)->osfile + v11) & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  offset = 0;
  return (int)&offset[filepos];
}
