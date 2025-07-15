void __usercall _mbspbrk_l(
        int a1@<edi>,
        unsigned __int8 *string,
        unsigned __int8 *charset,
        localeinfo_struct *plocinfo)
{
  threadmbcinfostruct *mbcinfo; // esi
  unsigned __int8 *v5; // ecx
  unsigned __int8 *i; // eax
  unsigned __int8 v7; // dl
  _LocaleUpdate v8; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v8, plocinfo);
  mbcinfo = v8.localeinfo.mbcinfo;
  if ( !v8.localeinfo.mbcinfo->ismbcodepage )
  {
    strpbrk(string, charset);
LABEL_22:
    if ( v8.updated )
      v8.ptd->_ownlocale &= ~2u;
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
          if ( (v8.localeinfo.mbcinfo->mbctype[*i + 1] & 4) != 0 )
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
        if ( (v8.localeinfo.mbcinfo->mbctype[*v5 + 1] & 4) != 0 && !*++v5 )
          break;
        ++v5;
      }
      while ( *v5 );
    }
    goto LABEL_22;
  }
  *_errno() = 22;
  _invalid_parameter(0, a1, (int)mbcinfo);
  if ( v8.updated )
    v8.ptd->_ownlocale &= ~2u;
}
