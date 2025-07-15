int __cdecl _iswctype_l(unsigned __int16 c, unsigned __int16 mask, localeinfo_struct *plocinfo)
{
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  int d; // [esp+10h] [ebp-4h] BYREF

  if ( c == 0xFFFF )
  {
    d = 0;
  }
  else if ( c >= 0x100u )
  {
    _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
    if ( !__crtGetStringTypeW(
            &_loc_update.localeinfo,
            1u,
            &c,
            1,
            (unsigned __int16 *)&d,
            _loc_update.localeinfo.locinfo->lc_codepage,
            _loc_update.localeinfo.locinfo->lc_handle[2]) )
      d = 0;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    d = (unsigned __int16)(mask & _pwctype[c]);
  }
  return mask & (unsigned __int16)d;
}
