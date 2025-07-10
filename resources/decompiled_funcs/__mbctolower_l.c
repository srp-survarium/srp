int __cdecl _mbctolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 ret[4]; // [esp+14h] [ebp-8h] BYREF
  char val[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( c <= 0xFF )
  {
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[c + 1] & 0x10) != 0 )
      result = _loc_update.localeinfo.mbcinfo->mbcasemap[c];
    else
      result = c;
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  val[0] = BYTE1(c);
  val[1] = c;
  if ( (_loc_update.localeinfo.mbcinfo->mbctype[BYTE1(c) + 1] & 4) != 0
    && __crtLCMapStringA(
         &_loc_update.localeinfo,
         _loc_update.localeinfo.mbcinfo->mblcid,
         0x100u,
         val,
         2,
         (char *)ret,
         2,
         _loc_update.localeinfo.mbcinfo->mbcodepage,
         1) )
  {
    result = ret[1] + (ret[0] << 8);
    goto LABEL_11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}
