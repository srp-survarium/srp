long double __cdecl _atof_l(char *nptr, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v2; // esi
  long double result; // st7
  int v5; // eax
  _flt fltstruct; // [esp+8h] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+20h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  v2 = (unsigned __int8 *)nptr;
  if ( nptr )
  {
    while ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1
          ? _loc_update.localeinfo.locinfo->pctype[*v2] & 8
          : _isctype_l(*v2, 8, &_loc_update.localeinfo) )
      ++v2;
    strlen(v2);
    result = _fltin2(&fltstruct, (const char *)v2, v5, 0, 0, &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}
