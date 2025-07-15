int __cdecl _wctomb_s_l(
        int *pRetValue,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t wchar,
        localeinfo_struct *plocinfo)
{
  char *v5; // esi
  unsigned int v6; // edi
  int result; // eax
  int v8; // esi
  int v9; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v5 = dst;
  v6 = sizeInBytes;
  if ( !dst && sizeInBytes )
  {
    if ( pRetValue )
      *pRetValue = 0;
    return 0;
  }
  if ( pRetValue )
    *pRetValue = -1;
  if ( v6 > 0x7FFFFFFF )
  {
    v8 = 22;
    *_errno() = 22;
    _invalid_parameter(0, v6, 0x16u);
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( !_loc_update.localeinfo.locinfo->lc_handle[2] )
  {
    if ( wchar > 0xFFu )
    {
      if ( v5 && v6 )
        memset((int)v5, 0, v6);
      goto LABEL_16;
    }
    if ( v5 )
    {
      if ( !v6 )
      {
LABEL_21:
        v8 = 34;
        *_errno() = 34;
        _invalid_parameter(0, v6, 0x22u);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return v8;
      }
      *v5 = wchar;
    }
    if ( pRetValue )
      *pRetValue = 1;
LABEL_26:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  dst = 0;
  v9 = WideCharToMultiByte(_loc_update.localeinfo.locinfo->lc_codepage, 0, &wchar, 1, v5, v6, 0, (LPBOOL)&dst);
  if ( v9 )
  {
    if ( !dst )
    {
      if ( pRetValue )
        *pRetValue = v9;
      goto LABEL_26;
    }
  }
  else if ( GetLastError() == 122 )
  {
    if ( v5 && v6 )
      memset((int)v5, 0, v6);
    goto LABEL_21;
  }
LABEL_16:
  *_errno() = 42;
  result = *_errno();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
