int __usercall _wcsnicmp_l@<eax>(
        wchar_t *a1@<edi>,
        wchar_t *first,
        wchar_t *last,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  wchar_t *v6; // ebx
  wchar_t v7; // ax
  unsigned __int16 v8; // si
  wchar_t v9; // ax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  result = 0;
  if ( count )
  {
    v6 = first;
    if ( first && (a1 = last) != 0 )
    {
      _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] )
      {
        do
        {
          v8 = _towlower_l(*v6, &_loc_update.localeinfo);
          v9 = _towlower_l(*a1, &_loc_update.localeinfo);
          ++v6;
          ++a1;
          --count;
        }
        while ( count && v8 && v8 == v9 );
      }
      else
      {
        do
        {
          v7 = *v6;
          if ( *v6 >= 0x41u && v7 <= 0x5Au )
            v7 += 32;
          v8 = v7;
          v9 = *a1;
          if ( *a1 >= 0x41u && v9 <= 0x5Au )
            v9 += 32;
          ++v6;
          ++a1;
          --count;
        }
        while ( count && v8 && v8 == v9 );
      }
      result = v8 - v9;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter((int)first, (int)a1, 0);
      return 0x7FFFFFFF;
    }
  }
  return result;
}
