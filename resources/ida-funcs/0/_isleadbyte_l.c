int __cdecl _isleadbyte_l(unsigned __int8 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate v3; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v3, plocinfo);
  result = v3.localeinfo.locinfo->pctype[c] & 0x8000;
  if ( v3.updated )
    v3.ptd->_ownlocale &= ~2u;
  return result;
}
