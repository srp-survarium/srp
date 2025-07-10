void __usercall _mbsrchr_l(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        unsigned __int8 *str,
        unsigned int c,
        localeinfo_struct *plocinfo)
{
  char *v5; // ecx
  unsigned __int8 v6; // dl
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-14h] BYREF
  char *r; // [esp+14h] [ebp-4h]

  r = 0;
  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  v5 = (char *)str;
  if ( !str )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( !_loc_update.localeinfo.mbcinfo->ismbcodepage )
  {
    strrchr(str, c);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  do
  {
    v6 = *v5;
    v7 = (unsigned __int8)*v5;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) != 0 )
    {
      v6 = *++v5;
      if ( *v5 )
      {
        if ( c == (v6 | (v7 << 8)) )
          r = v5 - 1;
        goto LABEL_16;
      }
      v8 = r == 0;
    }
    else
    {
      v8 = c == v7;
    }
    if ( v8 )
      r = v5;
LABEL_16:
    ++v5;
  }
  while ( v6 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}
