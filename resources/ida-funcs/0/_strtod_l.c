double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // esi
  int v6; // eax
  _flt *v7; // eax
  _flt *v8; // ecx
  int flags; // eax
  long double v10; // st7
  _flt answerstruct; // [esp+Ch] [ebp-30h] BYREF
  _LocaleUpdate _loc_update; // [esp+24h] [ebp-18h] BYREF
  long double tmp; // [esp+34h] [ebp-8h]

  v3 = (unsigned __int8 *)nptr;
  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( endptr )
    *endptr = nptr;
  if ( !nptr )
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)endptr, 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1
        ? _loc_update.localeinfo.locinfo->pctype[*v3] & 8
        : _isctype_l(*v3, 8, &_loc_update.localeinfo) )
    ++v3;
  strlen(v3);
  v7 = _fltin2(&answerstruct, (char *)v3, v6, 0, 0, &_loc_update.localeinfo);
  v8 = v7;
  if ( endptr )
    *endptr = (char *)&v3[v7->nbytes];
  flags = v7->flags;
  if ( (v8->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v10 = _HUGE;
    if ( *v3 == 45 )
      v10 = -_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v10 = 0.0, 0.0 != v8->dval) )
  {
    tmp = v8->dval;
    goto LABEL_24;
  }
  tmp = v10;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}
