int __usercall _mbsnbicoll_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  int v7; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( !n )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( s1 && s2 )
  {
    if ( n > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter(0, a1, 0x7FFFFFFFu);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage )
    {
      v7 = __crtCompareStringA(
             &_loc_update.localeinfo,
             _loc_update.localeinfo.mbcinfo->mblcid,
             0x1001u,
             (const char *)s1,
             n,
             (const char *)s2,
             n,
             _loc_update.localeinfo.mbcinfo->mbcodepage);
      if ( !v7 )
        goto LABEL_15;
      result = v7 - 2;
    }
    else
    {
      result = _strnicoll_l((const char *)s1, (const char *)s2, n, plocinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}
