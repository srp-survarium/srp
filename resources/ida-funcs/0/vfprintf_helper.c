int __cdecl vfprintf_helper(
        int (__cdecl *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        _iobuf *str,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int v6; // eax
  ioinfo *v7; // ecx
  ioinfo *v8; // eax
  int v9; // esi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str && format )
  {
    _lock_file(str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v6 = _fileno(str);
      if ( v6 == -1 || v6 == -2 )
        v7 = &__badioinfo;
      else
        v7 = (ioinfo *)((char *)__pioinfo[v6 >> 5] + 64 * (v6 & 0x1F));
      if ( (*((_BYTE *)v7 + 36) & 0x7F) != 0
        || (v6 == -1 || v6 == -2
          ? (v8 = &__badioinfo)
          : (v8 = (ioinfo *)((char *)__pioinfo[v6 >> 5] + 64 * (v6 & 0x1F))),
            *((char *)v8 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter(0, 0, 0, 0, 0);
        retval = -1;
      }
    }
    if ( !retval )
    {
      v9 = _stbuf(str);
      retval = outfn(str, format, plocinfo, ap);
      _ftbuf(v9, str);
    }
    _unlock_file(str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return -1;
  }
}
