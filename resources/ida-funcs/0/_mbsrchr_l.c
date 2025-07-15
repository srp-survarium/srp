void __usercall _mbsrchr_l(int a1@<edi>, int a2@<esi>, const char *str, unsigned int c, localeinfo_struct *plocinfo)
{
  const char *v5; // ecx
  unsigned __int8 v6; // dl
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate v9; // [esp+4h] [ebp-14h] BYREF
  const char *v10; // [esp+14h] [ebp-4h]

  v10 = 0;
  _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
  v5 = str;
  if ( !str )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    if ( v9.updated )
      v9.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( !v9.localeinfo.mbcinfo->ismbcodepage )
  {
    strrchr(str, c);
    if ( v9.updated )
      v9.ptd->_ownlocale &= ~2u;
    return;
  }
  do
  {
    v6 = *v5;
    v7 = *(unsigned __int8 *)v5;
    if ( (v9.localeinfo.mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) != 0 )
    {
      v6 = *++v5;
      if ( *v5 )
      {
        if ( c == (v6 | (v7 << 8)) )
          v10 = v5 - 1;
        goto LABEL_16;
      }
      v8 = v10 == 0;
    }
    else
    {
      v8 = c == v7;
    }
    if ( v8 )
      v10 = v5;
LABEL_16:
    ++v5;
  }
  while ( v6 );
  if ( v9.updated )
    v9.ptd->_ownlocale &= ~2u;
}
