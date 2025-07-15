int __usercall _mbsicmp_l@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        localeinfo_struct *plocinfo)
{
  const unsigned __int8 *v5; // edx
  int result; // eax
  const unsigned __int8 *v7; // ebx
  threadmbcinfostruct *mbcinfo; // eax
  unsigned __int16 v9; // cx
  const unsigned __int8 *v10; // edx
  unsigned __int16 v11; // si
  int v12; // eax
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // dx
  char *v15; // ecx
  unsigned __int16 v16; // cx
  unsigned __int16 v17; // cx
  int v18; // eax
  unsigned __int16 v19; // ax
  unsigned __int16 v20; // dx
  char *v21; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-14h] BYREF
  unsigned __int8 szResult[4]; // [esp+14h] [ebp-4h] BYREF
  const unsigned __int8 *s1a; // [esp+20h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  v5 = s1;
  if ( !s1 )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v7 = s2;
  if ( !s2 )
  {
    *_errno() = 22;
    _invalid_parameter(0, a2, 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  mbcinfo = _loc_update.localeinfo.mbcinfo;
  if ( !_loc_update.localeinfo.mbcinfo->ismbcodepage )
  {
    result = _stricmp_l((const char *)s1, (const char *)s2, &_loc_update.localeinfo);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  while ( 1 )
  {
    v9 = *v5;
    v10 = v5 + 1;
    s1a = v10;
    if ( (mbcinfo->mbctype[(unsigned __int8)v9 + 1] & 4) != 0 )
    {
      if ( *v10 )
      {
        v12 = __crtLCMapStringA(
                &_loc_update.localeinfo,
                mbcinfo->mblcid,
                0x200u,
                (const char *)v10 - 1,
                2,
                (char *)szResult,
                2,
                mbcinfo->mbcodepage,
                1);
        if ( v12 == 1 )
        {
          v13 = szResult[0];
        }
        else
        {
          if ( v12 != 2 )
            goto LABEL_37;
          v13 = szResult[1] + (szResult[0] << 8);
        }
        ++s1a;
        v11 = v13;
        mbcinfo = _loc_update.localeinfo.mbcinfo;
      }
      else
      {
        v11 = 0;
      }
    }
    else
    {
      v14 = v9;
      v15 = (char *)mbcinfo + v9;
      v11 = (v15[29] & 0x10) != 0 ? (unsigned __int8)v15[285] : v14;
    }
    v16 = *v7++;
    if ( (mbcinfo->mbctype[(unsigned __int8)v16 + 1] & 4) != 0 )
      break;
    v20 = v16;
    v21 = (char *)mbcinfo + v16;
    if ( (v21[29] & 0x10) != 0 )
      v17 = (unsigned __int8)v21[285];
    else
      v17 = v20;
LABEL_34:
    if ( v17 != v11 )
    {
      result = v17 < v11 ? 1 : -1;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( !v11 )
    {
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
    v5 = s1a;
  }
  if ( !*v7 )
  {
    v17 = 0;
    goto LABEL_34;
  }
  v18 = __crtLCMapStringA(
          &_loc_update.localeinfo,
          mbcinfo->mblcid,
          0x200u,
          (const char *)v7 - 1,
          2,
          (char *)szResult,
          2,
          mbcinfo->mbcodepage,
          1);
  if ( v18 == 1 )
  {
    v19 = szResult[0];
LABEL_30:
    v17 = v19;
    mbcinfo = _loc_update.localeinfo.mbcinfo;
    ++v7;
    goto LABEL_34;
  }
  if ( v18 == 2 )
  {
    v19 = szResult[1] + (szResult[0] << 8);
    goto LABEL_30;
  }
LABEL_37:
  *_errno() = 22;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0x7FFFFFFF;
}
