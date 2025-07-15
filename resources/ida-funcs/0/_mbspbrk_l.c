void __usercall _mbspbrk_l(
        unsigned int a1@<edi>,
        unsigned __int8 *string,
        unsigned __int8 *charset,
        localeinfo_struct *plocinfo)
{
  threadmbcinfostruct *mbcinfo; // esi
  unsigned __int8 *v5; // ecx
  unsigned __int8 *i; // eax
  unsigned __int8 v7; // dl
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  mbcinfo = _loc_update.localeinfo.mbcinfo;
  if ( !_loc_update.localeinfo.mbcinfo->ismbcodepage )
  {
    strpbrk(string, charset);
LABEL_22:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v5 = string;
  if ( string && charset )
  {
    if ( *string )
    {
      do
      {
        for ( i = charset; *i; ++i )
        {
          v7 = *i;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[*i + 1] & 4) != 0 )
          {
            if ( v7 == *v5 && i[1] == v5[1] || !i[1] )
              break;
            ++i;
          }
          else if ( v7 == *v5 )
          {
            break;
          }
        }
        if ( *i )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[*v5 + 1] & 4) != 0 && !*++v5 )
          break;
        ++v5;
      }
      while ( *v5 );
    }
    goto LABEL_22;
  }
  *_errno() = 22;
  _invalid_parameter(0, a1, (unsigned int)mbcinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}
