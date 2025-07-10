int __cdecl x_ismbbtype_l(localeinfo_struct *plocinfo, unsigned __int8 tst, int cmask, unsigned __int8 kmask)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( (kmask & _loc_update.localeinfo.mbcinfo->mbctype[tst + 1]) != 0
    || (!cmask ? (result = 0) : (result = (unsigned __int16)(cmask & _loc_update.localeinfo.locinfo->pctype[tst])),
        result) )
  {
    result = 1;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
