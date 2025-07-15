int __usercall vfprintf_helper@<eax>(
        int a1@<ebx>,
        int (__cdecl *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        _iobuf *str,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int v7; // eax
  ioinfo *v8; // ecx
  ioinfo *v9; // eax
  int v10; // esi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str && format )
  {
    _lock_file(str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v7 = _fileno(a1, (int)str, str);
      if ( v7 == -1 || v7 == -2 )
        v8 = &__badioinfo;
      else
        v8 = (ioinfo *)((char *)__pioinfo[v7 >> 5] + 64 * (v7 & 0x1F));
      if ( (*((_BYTE *)v8 + 36) & 0x7F) != 0
        || (v7 == -1 || v7 == -2
          ? (v9 = &__badioinfo)
          : (v9 = (ioinfo *)((char *)__pioinfo[v7 >> 5] + 64 * (v7 & 0x1F))),
            *((char *)v9 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter(a1, (int)str, 0);
        retval = -1;
      }
    }
    if ( !retval )
    {
      v10 = _stbuf(str);
      retval = outfn(str, format, plocinfo, ap);
      _ftbuf(v10, str);
    }
    _unlock_file(str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, (int)str, 0);
    return -1;
  }
}
