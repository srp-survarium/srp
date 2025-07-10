int __cdecl _stricmp_l(const char *dst, const char *src, localeinfo_struct *plocinfo)
{
  int result; // eax
  const char *v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( dst )
  {
    v4 = src;
    if ( src )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] )
      {
        do
        {
          v5 = _tolower_l(*(unsigned __int8 *)dst++, &_loc_update.localeinfo);
          v6 = v5;
          v7 = _tolower_l(*(unsigned __int8 *)v4++, &_loc_update.localeinfo);
        }
        while ( v6 && v6 == v7 );
        result = v6 - v7;
      }
      else
      {
        result = __ascii_stricmp(dst, src);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(0, 0, 0, 0, 0);
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}
