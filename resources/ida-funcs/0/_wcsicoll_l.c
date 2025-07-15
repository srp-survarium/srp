int __usercall _wcsicoll_l@<eax>(
        int a1@<edi>,
        const wchar_t *_string1,
        const wchar_t *_string2,
        localeinfo_struct *plocinfo)
{
  const wchar_t *v4; // esi
  int result; // eax
  const wchar_t *v6; // edx
  unsigned int v7; // ecx
  wchar_t v8; // ax
  wchar_t v9; // cx
  wchar_t v10; // ax
  int v11; // eax
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  v4 = _string1;
  if ( _string1 && (v6 = _string2) != 0 )
  {
    v7 = _loc_update.localeinfo.locinfo->lc_handle[1];
    if ( !v7 )
    {
      do
      {
        v8 = *v4;
        if ( *v4 >= 0x41u && v8 <= 0x5Au )
          v8 += 32;
        v9 = v8;
        v10 = *v6;
        if ( *v6 >= 0x41u && v10 <= 0x5Au )
          v10 += 32;
        ++v4;
        ++v6;
      }
      while ( v9 && v9 == v10 );
      result = v9 - v10;
      goto LABEL_20;
    }
    v11 = __crtCompareStringW(
            &_loc_update.localeinfo,
            v7,
            0x1001u,
            _string1,
            -1,
            _string2,
            -1,
            _loc_update.localeinfo.locinfo->lc_codepage);
    if ( v11 )
    {
      result = v11 - 2;
LABEL_20:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    *_errno() = 22;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, (int)_string1);
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0x7FFFFFFF;
}
