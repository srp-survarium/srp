unsigned __int16 __usercall _fputwc_nolock@<ax>(
        unsigned int a1@<ebx>,
        stlp_std::ioinfo **a2@<edi>,
        wchar_t ch,
        _iobuf *str)
{
  ioinfo *v4; // eax
  ioinfo *v5; // eax
  stlp_std::ioinfo **v6; // edi
  ioinfo *v7; // eax
  unsigned __int16 result; // ax
  int v9; // edi
  bool v10; // sf
  int v11; // eax
  int size; // [esp+Ch] [ebp-10h] BYREF
  char mbc[8]; // [esp+10h] [ebp-Ch] BYREF

  if ( (str->_flag & 0x40) != 0
    || (_fileno(a1, (unsigned int)a2, str) == -1 || _fileno((unsigned int)&__badioinfo, (unsigned int)a2, str) == -2
      ? (v4 = &__badioinfo)
      : (a2 = &__pioinfo[_fileno((unsigned int)&__badioinfo, (unsigned int)a2, str) >> 5],
         v4 = (ioinfo *)((char *)*a2 + 64 * (_fileno((unsigned int)&__badioinfo, (unsigned int)a2, str) & 0x1F))),
        (*((_BYTE *)v4 + 36) & 0x7F) == 2
     || (_fileno((unsigned int)&__badioinfo, (unsigned int)a2, str) == -1
      || _fileno((unsigned int)&__badioinfo, (unsigned int)a2, str) == -2
       ? (v5 = &__badioinfo)
       : (a2 = &__pioinfo[_fileno((unsigned int)&__badioinfo, (unsigned int)a2, str) >> 5],
          v5 = (ioinfo *)((char *)*a2 + 64 * (_fileno((unsigned int)&__badioinfo, (unsigned int)a2, str) & 0x1F))),
         (*((_BYTE *)v5 + 36) & 0x7F) == 1
      || (_fileno((unsigned int)&__badioinfo, (unsigned int)a2, str) == -1
       || _fileno((unsigned int)&__badioinfo, (unsigned int)a2, str) == -2
        ? (v7 = &__badioinfo)
        : (v6 = &__pioinfo[_fileno((unsigned int)&__badioinfo, (unsigned int)a2, str) >> 5],
           v7 = (ioinfo *)((char *)*v6 + 64 * (_fileno((unsigned int)&__badioinfo, (unsigned int)v6, str) & 0x1F))),
          v7->osfile >= 0))) )
  {
    v10 = str->_cnt - 2 < 0;
    str->_cnt -= 2;
    if ( v10 )
    {
      return _flswbuf(ch, str);
    }
    else
    {
      result = ch;
      *(_WORD *)str->_ptr = ch;
      str->_ptr += 2;
    }
  }
  else
  {
    if ( wctomb_s(&size, mbc, 5u, ch) )
      return -1;
    v9 = 0;
    if ( size > 0 )
    {
      while ( 1 )
      {
        v10 = --str->_cnt < 0;
        if ( v10 )
        {
          v11 = _flsbuf(mbc[v9], (int)str);
        }
        else
        {
          *str->_ptr = mbc[v9];
          v11 = *(unsigned __int8 *)str->_ptr++;
        }
        if ( v11 == -1 )
          break;
        if ( ++v9 >= size )
          return ch;
      }
      return -1;
    }
    return ch;
  }
  return result;
}
