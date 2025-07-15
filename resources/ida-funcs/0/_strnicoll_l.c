void __usercall _strnicoll_l(
        const char *a1@<edi>,
        int a2@<esi>,
        char *_string1,
        char *_string2,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  unsigned int v6; // ecx
  _LocaleUpdate v7; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v7, plocinfo);
  if ( !count )
  {
    if ( v7.updated )
      v7.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( _string1 && _string2 )
  {
    if ( count > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter(0, (int)a1, 0x7FFFFFFF);
      goto LABEL_16;
    }
    v6 = v7.localeinfo.locinfo->lc_handle[1];
    if ( v6 )
    {
      if ( !__crtCompareStringA(
              &v7.localeinfo,
              v6,
              0x1001u,
              _string1,
              count,
              _string2,
              count,
              v7.localeinfo.locinfo->lc_collate_cp) )
      {
        *_errno() = 22;
LABEL_16:
        if ( v7.updated )
          v7.ptd->_ownlocale &= ~2u;
        return;
      }
    }
    else
    {
      _strnicmp_l(a1, 0x7FFFFFFF, _string1, _string2, count, &v7.localeinfo);
    }
    if ( v7.updated )
      v7.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)a1, a2);
    if ( v7.updated )
      v7.ptd->_ownlocale &= ~2u;
  }
}
