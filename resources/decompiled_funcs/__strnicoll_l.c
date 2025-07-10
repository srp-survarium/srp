void __usercall _strnicoll_l(
        const char *a1@<edi>,
        unsigned int a2@<esi>,
        char *_string1,
        char *_string2,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  LCID v6; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( !count )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( _string1 && _string2 )
  {
    if ( count > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter(0, (unsigned int)a1, 0x7FFFFFFFu);
      goto LABEL_16;
    }
    v6 = _loc_update.localeinfo.locinfo->lc_handle[1];
    if ( v6 )
    {
      if ( !__crtCompareStringA(
              &_loc_update.localeinfo,
              v6,
              0x1001u,
              _string1,
              count,
              _string2,
              count,
              _loc_update.localeinfo.locinfo->lc_collate_cp) )
      {
        *_errno() = 22;
LABEL_16:
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return;
      }
    }
    else
    {
      _strnicmp_l(a1, 0x7FFFFFFFu, _string1, _string2, count, &_loc_update.localeinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, (unsigned int)a1, a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}
