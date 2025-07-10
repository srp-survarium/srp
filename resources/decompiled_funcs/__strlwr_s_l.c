int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
