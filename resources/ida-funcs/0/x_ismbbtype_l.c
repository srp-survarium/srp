int __cdecl x_ismbbtype_l(localeinfo_struct *plocinfo, unsigned __int8 tst, int cmask, unsigned __int8 kmask)
{
  int result; // eax
  _LocaleUpdate v5; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v5, plocinfo);
  if ( (kmask & v5.localeinfo.mbcinfo->mbctype[tst + 1]) != 0
    || (!cmask ? (result = 0) : (result = (unsigned __int16)(cmask & v5.localeinfo.locinfo->pctype[tst])), result) )
  {
    result = 1;
  }
  if ( v5.updated )
    v5.ptd->_ownlocale &= ~2u;
  return result;
}
