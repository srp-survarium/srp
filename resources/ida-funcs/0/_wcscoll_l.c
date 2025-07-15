int __usercall _wcscoll_l@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        const wchar_t *_string1,
        const wchar_t *_string2,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // ecx
  int v7; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( _string1 && _string2 )
  {
    v6 = _loc_update.localeinfo.locinfo->lc_handle[1];
    if ( !v6 )
    {
      result = wcscmp(_string1, _string2);
      goto LABEL_12;
    }
    v7 = __crtCompareStringW(
           &_loc_update.localeinfo,
           v6,
           0x1000u,
           _string1,
           -1,
           _string2,
           -1,
           _loc_update.localeinfo.locinfo->lc_collate_cp);
    if ( v7 )
    {
      result = v7 - 2;
LABEL_12:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    *_errno() = 22;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0x7FFFFFFF;
}
