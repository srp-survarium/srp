int __usercall _wcsicmp_l@<eax>(unsigned int a1@<edi>, wchar_t *dst, wchar_t *src, localeinfo_struct *plocinfo)
{
  unsigned __int16 *v4; // ebx
  int result; // eax
  unsigned __int16 *v6; // edi
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // si
  unsigned __int16 v9; // ax
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  v4 = dst;
  if ( dst )
  {
    v6 = src;
    if ( src )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] )
      {
        do
        {
          v8 = _towlower_l(*v4++, &_loc_update.localeinfo);
          v9 = _towlower_l(*v6++, &_loc_update.localeinfo);
        }
        while ( v8 && v8 == v9 );
      }
      else
      {
        do
        {
          v7 = *v4;
          if ( *v4 >= 0x41u && v7 <= 0x5Au )
            v7 += 32;
          v8 = v7;
          v9 = *v6;
          if ( *v6 >= 0x41u && v9 <= 0x5Au )
            v9 += 32;
          ++v4;
          ++v6;
        }
        while ( v8 && v8 == v9 );
      }
      result = v8 - v9;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter((unsigned int)dst, 0, 0);
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}
