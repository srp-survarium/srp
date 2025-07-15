unsigned __int16 __usercall _fputwc_nolock@<ax>(ioinfo *a1@<ebx>, stlp_std::ioinfo **a2@<edi>, wchar_t ch, _iobuf *str)
{
  int v4; // eax
  ioinfo *v5; // eax
  ioinfo *v6; // eax
  ioinfo *v7; // eax
  unsigned __int16 result; // ax
  int v9; // edi
  bool v10; // sf
  int v11; // eax
  int v12; // [esp+Ch] [ebp-10h] BYREF
  char v13[8]; // [esp+10h] [ebp-Ch] BYREF

  if ( (str->_flag & 0x40) != 0 )
    goto LABEL_26;
  v4 = _fileno((int)a1, (int)a2, str);
  a1 = &__badioinfo;
  if ( v4 == -1 || _fileno((int)&__badioinfo, (int)a2, str) == -2 )
  {
    v5 = &__badioinfo;
  }
  else
  {
    a2 = &__pioinfo[_fileno((int)&__badioinfo, (int)a2, str) >> 5];
    v5 = (ioinfo *)((char *)*a2 + 64 * (_fileno((int)&__badioinfo, (int)a2, str) & 0x1F));
  }
  if ( (*((_BYTE *)v5 + 36) & 0x7F) == 2
    || (_fileno((int)&__badioinfo, (int)a2, str) == -1 || _fileno((int)&__badioinfo, (int)a2, str) == -2
      ? (v6 = &__badioinfo)
      : (a2 = &__pioinfo[_fileno((int)&__badioinfo, (int)a2, str) >> 5],
         v6 = (ioinfo *)((char *)*a2 + 64 * (_fileno((int)&__badioinfo, (int)a2, str) & 0x1F))),
        (*((_BYTE *)v6 + 36) & 0x7F) == 1
     || (_fileno((int)&__badioinfo, (int)a2, str) == -1 || _fileno((int)&__badioinfo, (int)a2, str) == -2
       ? (v7 = &__badioinfo)
       : (a2 = &__pioinfo[_fileno((int)&__badioinfo, (int)a2, str) >> 5],
          v7 = (ioinfo *)((char *)*a2 + 64 * (_fileno((int)&__badioinfo, (int)a2, str) & 0x1F))),
         v7->osfile >= 0)) )
  {
LABEL_26:
    v10 = str->_cnt - 2 < 0;
    str->_cnt -= 2;
    if ( v10 )
    {
      return _flswbuf((int)a1, (int)a2, ch, str);
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
    if ( wctomb_s(&v12, v13, 5u, ch) )
      return -1;
    v9 = 0;
    if ( v12 > 0 )
    {
      while ( 1 )
      {
        v10 = --str->_cnt < 0;
        if ( v10 )
        {
          v11 = _flsbuf((int)&__badioinfo, v9, v13[v9], str);
        }
        else
        {
          *str->_ptr = v13[v9];
          v11 = *(unsigned __int8 *)str->_ptr++;
        }
        if ( v11 == -1 )
          break;
        if ( ++v9 >= v12 )
          return ch;
      }
      return -1;
    }
    return ch;
  }
  return result;
}
