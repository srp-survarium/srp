void __usercall _mbschr_l(int a1@<edi>, int a2@<esi>, char *string, unsigned int c, localeinfo_struct *plocinfo)
{
  char *v5; // eax
  unsigned __int16 v6; // cx
  _LocaleUpdate v7; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v7, plocinfo);
  v5 = string;
  if ( string )
  {
    if ( v7.localeinfo.mbcinfo->ismbcodepage )
    {
      while ( 1 )
      {
        v6 = (unsigned __int8)*v5;
        if ( !*v5 )
          break;
        if ( (v7.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) != 0 )
        {
          if ( !*++v5 )
            goto LABEL_17;
          if ( c == ((unsigned __int8)*v5 | (v6 << 8)) )
            goto LABEL_15;
        }
        else if ( c == (unsigned __int8)*v5 )
        {
          break;
        }
        ++v5;
      }
      if ( c == (unsigned __int8)*v5 )
        goto LABEL_15;
LABEL_17:
      if ( v7.updated )
        v7.ptd->_ownlocale &= ~2u;
    }
    else
    {
      strchr(string, c);
LABEL_15:
      if ( v7.updated )
        v7.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    if ( v7.updated )
      v7.ptd->_ownlocale &= ~2u;
  }
}
