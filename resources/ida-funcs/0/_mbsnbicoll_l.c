void __usercall _mbsnbicoll_l(
        const char *a1@<edi>,
        int a2@<esi>,
        char *s1,
        char *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  _LocaleUpdate v6; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v6, plocinfo);
  if ( !n )
  {
    if ( v6.updated )
      v6.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( s1 && s2 )
  {
    if ( n > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter(0, (int)a1, 0x7FFFFFFF);
      goto LABEL_15;
    }
    if ( v6.localeinfo.mbcinfo->ismbcodepage )
    {
      if ( !__crtCompareStringA(
              &v6.localeinfo,
              v6.localeinfo.mbcinfo->mblcid,
              0x1001u,
              s1,
              n,
              s2,
              n,
              v6.localeinfo.mbcinfo->mbcodepage) )
      {
LABEL_15:
        if ( v6.updated )
          v6.ptd->_ownlocale &= ~2u;
        return;
      }
    }
    else
    {
      _strnicoll_l(a1, 0x7FFFFFFF, s1, s2, n, plocinfo);
    }
    if ( v6.updated )
      v6.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)a1, a2);
    if ( v6.updated )
      v6.ptd->_ownlocale &= ~2u;
  }
}
