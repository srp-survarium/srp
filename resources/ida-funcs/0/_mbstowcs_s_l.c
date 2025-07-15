int __usercall _mbstowcs_s_l@<eax>(
        int a1@<edi>,
        unsigned int *pConvertedChars,
        wchar_t *pwcs,
        unsigned int sizeInWords,
        char *s,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v8; // eax
  int *v9; // eax
  int v10; // eax
  unsigned int v11; // eax
  int v12; // [esp-8h] [ebp-24h]
  _LocaleUpdate v13; // [esp+8h] [ebp-14h] BYREF
  int v14; // [esp+18h] [ebp-4h]

  v14 = 0;
  if ( pwcs )
  {
    if ( !sizeInWords )
    {
LABEL_5:
      *_errno() = 22;
      _invalid_parameter(0, a1, 22);
      return 22;
    }
    *pwcs = 0;
  }
  else if ( sizeInWords )
  {
    goto LABEL_5;
  }
  if ( pConvertedChars )
    *pConvertedChars = 0;
  _LocaleUpdate::_LocaleUpdate(&v13, plocinfo);
  v8 = n;
  if ( n > sizeInWords )
    v8 = sizeInWords;
  if ( v8 > 0x7FFFFFFF )
  {
    v9 = _errno();
    v12 = 22;
LABEL_22:
    *v9 = v12;
    _invalid_parameter(0, (int)pConvertedChars, v12);
    if ( v13.updated )
      v13.ptd->_ownlocale &= ~2u;
    return v12;
  }
  _mbstowcs_l_helper(pwcs, s, v8, &v13.localeinfo);
  if ( v10 == -1 )
  {
    if ( pwcs )
      *pwcs = 0;
    result = *_errno();
    if ( v13.updated )
      v13.ptd->_ownlocale &= ~2u;
  }
  else
  {
    v11 = v10 + 1;
    if ( pwcs )
    {
      if ( v11 > sizeInWords )
      {
        if ( n != -1 )
        {
          *pwcs = 0;
          v9 = _errno();
          v12 = 34;
          goto LABEL_22;
        }
        v11 = sizeInWords;
        v14 = 80;
      }
      pwcs[v11 - 1] = 0;
    }
    if ( pConvertedChars )
      *pConvertedChars = v11;
    if ( v13.updated )
      v13.ptd->_ownlocale &= ~2u;
    return v14;
  }
  return result;
}
