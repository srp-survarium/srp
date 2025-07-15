int __usercall _ftell_nolock@<eax>(int a1@<esi>, _iobuf *str)
{
  int v4; // eax
  int v5; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v9; // edx
  int cnt; // edx
  stlp_std::ioinfo **v11; // ebx
  int v12; // esi
  char *v13; // eax
  char *v14; // ecx
  bool v15; // zf
  int bufsiz; // eax
  int v17; // ecx
  char *v18; // [esp+8h] [ebp-Ch]
  int pos; // [esp+Ch] [ebp-8h]
  int fh; // [esp+10h] [ebp-4h]
  int stream; // [esp+1Ch] [ebp+8h]

  if ( !str )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, a1);
    return -1;
  }
  v4 = _fileno(0, (int)str, str);
  fh = v4;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v5 = _lseek(v4, 0, 1);
  pos = v5;
  if ( v5 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v5 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  v18 = (char *)(str->_ptr - base);
  if ( (flag & 3) != 0 )
  {
    if ( *(&__pioinfo[fh >> 5]->osfile + 64 * (fh & 0x1F)) < 0 )
    {
      v9 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v9 == 10 )
            ++v18;
          ++v9;
        }
        while ( v9 < ptr );
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( !pos )
    return (int)v18;
  if ( (str->_flag & 1) == 0 )
    return (int)&v18[pos];
  cnt = str->_cnt;
  if ( cnt )
  {
    v11 = &__pioinfo[fh >> 5];
    stream = cnt + ptr - base;
    v12 = (fh & 0x1F) << 6;
    if ( *(&(*v11)->osfile + v12) >= 0 )
    {
LABEL_39:
      pos -= stream;
      return (int)&v18[pos];
    }
    if ( _lseek(fh, 0, 2) == pos )
    {
      v13 = str->_base;
      v14 = &v13[stream];
      while ( v13 < v14 )
      {
        if ( *v13 == 10 )
          ++stream;
        ++v13;
      }
      v15 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v15 )
        ++stream;
      goto LABEL_39;
    }
    if ( _lseek(fh, pos, 0) >= 0 )
    {
      bufsiz = 512;
      if ( (unsigned int)stream > 0x200 || (v17 = str->_flag, (v17 & 8) == 0) || (v17 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      stream = bufsiz;
      v15 = (*(&(*v11)->osfile + v12) & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  v18 = 0;
  return (int)&v18[pos];
}
