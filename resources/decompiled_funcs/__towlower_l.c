int __cdecl _towlower_l(unsigned __int16 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  LCID v3; // edx
  bool v4; // zf
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  unsigned __int16 widechar; // [esp+10h] [ebp-4h] BYREF

  result = 0xFFFF;
  if ( c != 0xFFFF )
  {
    _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
    v3 = _loc_update.localeinfo.locinfo->lc_handle[2];
    if ( v3 )
    {
      if ( c >= 0x100u )
      {
        v4 = __crtLCMapStringW(&_loc_update.localeinfo, v3, 0x100u, &c, 1, &widechar, 1) == 0;
        result = c;
        if ( !v4 )
          result = widechar;
        goto LABEL_11;
      }
      v4 = _iswctype_l(c, 1u, &_loc_update.localeinfo) == 0;
      result = c;
      if ( v4 )
      {
LABEL_11:
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return result;
      }
      LOWORD(result) = _loc_update.localeinfo.locinfo->pclmap[c];
    }
    else
    {
      LOWORD(result) = c;
      if ( (unsigned __int16)(c - 65) <= 0x19u )
        LOWORD(result) = c + 32;
    }
    result = (unsigned __int16)result;
    goto LABEL_11;
  }
  return result;
}
