int __cdecl _mbstowcs_s_l(
        unsigned int *pConvertedChars,
        wchar_t *pwcs,
        unsigned int sizeInWords,
        char *s,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // eax
  int *v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // esi
  int v12; // [esp-8h] [ebp-24h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-14h] BYREF
  int retvalue; // [esp+18h] [ebp-4h]

  retvalue = 0;
  if ( pwcs )
  {
    if ( !sizeInWords )
    {
LABEL_5:
      *_errno() = 22;
      _invalid_parameter(0, 0, 0, 0, 0);
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
  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  v7 = n;
  if ( n > sizeInWords )
    v7 = sizeInWords;
  if ( v7 > 0x7FFFFFFF )
  {
    v8 = _errno();
    v12 = 22;
LABEL_22:
    v11 = v12;
    *v8 = v12;
    _invalid_parameter(0, 0, 0, 0, 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v11;
  }
  _mbstowcs_l_helper(pwcs, s, v7, &_loc_update.localeinfo);
  if ( v9 == -1 )
  {
    if ( pwcs )
      *pwcs = 0;
    result = *_errno();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    v10 = v9 + 1;
    if ( pwcs )
    {
      if ( v10 > sizeInWords )
      {
        if ( n != -1 )
        {
          *pwcs = 0;
          v8 = _errno();
          v12 = 34;
          goto LABEL_22;
        }
        v10 = sizeInWords;
        retvalue = 80;
      }
      pwcs[v10 - 1] = 0;
    }
    if ( pConvertedChars )
      *pConvertedChars = v10;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return retvalue;
  }
  return result;
}
