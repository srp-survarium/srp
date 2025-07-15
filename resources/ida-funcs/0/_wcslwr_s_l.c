unsigned int __cdecl _wcslwr_s_l(wchar_t *wsrc, unsigned int sizeInWords, localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  result = wcslwr_s_l_stat(wsrc, sizeInWords, &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
