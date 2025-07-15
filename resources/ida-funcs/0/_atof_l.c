long double __usercall _atof_l@<st0>(int a1@<edi>, char *nptr, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // esi
  long double result; // st7
  int v6; // eax
  _flt flt; // [esp+8h] [ebp-28h] BYREF
  _LocaleUpdate v8; // [esp+20h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v8, plocinfo);
  v3 = (unsigned __int8 *)nptr;
  if ( nptr )
  {
    while ( v8.localeinfo.locinfo->mb_cur_max <= 1
          ? v8.localeinfo.locinfo->pctype[*v3] & 8
          : _isctype_l(*v3, 8, &v8.localeinfo) )
      ++v3;
    strlen(v3);
    result = _fltin2(&flt, (char *)v3, v6, 0, 0, &v8.localeinfo)->dval;
    if ( v8.updated )
      v8.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, 0);
    if ( v8.updated )
      v8.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}
