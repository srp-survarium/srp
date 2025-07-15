UINT __usercall getSystemCP@<eax>(int codepage@<esi>)
{
  UINT result; // eax
  _LocaleUpdate v2; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v2, 0);
  fSystemSet = 0;
  switch ( codepage )
  {
    case -2:
      fSystemSet = 1;
      result = GetOEMCP();
      goto LABEL_3;
    case -3:
      fSystemSet = 1;
      result = GetACP();
      goto LABEL_3;
    case -4:
      result = v2.localeinfo.locinfo->lc_codepage;
      fSystemSet = 1;
LABEL_3:
      if ( v2.updated )
        v2.ptd->_ownlocale &= ~2u;
      return result;
  }
  if ( v2.updated )
    v2.ptd->_ownlocale &= ~2u;
  return codepage;
}
