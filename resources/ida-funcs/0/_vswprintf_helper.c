int __usercall _vswprintf_helper@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        int (__cdecl *woutfn)(_iobuf *, const wchar_t *, localeinfo_struct *, char *),
        char *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  bool v9; // sf
  _iobuf v10; // [esp+4h] [ebp-20h] BYREF
  int v11; // [esp+38h] [ebp+14h]

  if ( !format )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    return -1;
  }
  if ( count && !string )
  {
    *_errno() = 22;
    _invalid_parameter(0, count, 0);
    return -1;
  }
  v10._flag = 66;
  v10._base = string;
  v10._ptr = string;
  if ( count <= 0x3FFFFFFF )
    v10._cnt = 2 * count;
  else
    v10._cnt = 0x7FFFFFFF;
  result = woutfn(&v10, format, plocinfo, ap);
  v11 = result;
  if ( string )
  {
    if ( result >= 0 )
    {
      if ( --v10._cnt >= 0 )
      {
        *v10._ptr++ = 0;
LABEL_14:
        if ( --v10._cnt >= 0 )
        {
          *v10._ptr = 0;
          return v11;
        }
        if ( _flsbuf(0, count, 0, &v10) != -1 )
          return v11;
        goto LABEL_18;
      }
      if ( _flsbuf(0, count, 0, &v10) != -1 )
        goto LABEL_14;
    }
LABEL_18:
    v9 = v10._cnt < 0;
    *(_WORD *)&string[2 * count - 2] = 0;
    return !v9 - 2;
  }
  return result;
}
