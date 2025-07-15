int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate v4; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v4, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= ~2u;
  return result;
}
