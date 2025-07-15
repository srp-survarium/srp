int __usercall _mbsnbicmp_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const unsigned __int8 *v7; // edi
  unsigned __int16 v8; // cx
  bool v9; // zf
  int v10; // ecx
  unsigned __int16 v11; // si
  unsigned __int8 v12; // dl
  int v13; // ecx
  char *v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  char *v18; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  int c1; // [esp+14h] [ebp-8h]
  int c2; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( !n )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( !_loc_update.localeinfo.mbcinfo->ismbcodepage )
  {
    result = _strnicmp((const char *)s1, (const char *)s2, n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( !s1 )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v7 = s2;
  if ( !s2 )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    v8 = *s1;
    --n;
    ++s1;
    v9 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v8 + 1] & 4) == 0;
    c1 = v8;
    if ( v9 )
    {
      v14 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v14[29] & 0x10) != 0 )
        v15 = (unsigned __int8)v14[285];
      else
        v15 = (unsigned __int16)c1;
      c1 = v15;
      goto LABEL_32;
    }
    if ( !n )
    {
      v10 = *v7;
      v9 = (_loc_update.localeinfo.mbcinfo->mbctype[v10 + 1] & 4) == 0;
      c1 = 0;
      if ( !v9 )
        goto LABEL_51;
      v10 = (unsigned __int16)v10;
      v11 = 0;
      goto LABEL_46;
    }
    if ( !*s1 )
    {
      c1 = 0;
LABEL_32:
      v11 = c1;
      goto LABEL_33;
    }
    v12 = *s1++;
    v13 = (unsigned __int16)(v12 | (unsigned __int16)(v8 << 8));
    v11 = v13;
    c1 = v13;
    if ( (unsigned __int16)v13 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v13 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v13 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v13 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        v11 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v13;
      }
    }
    else
    {
      v11 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v13;
    }
LABEL_33:
    v16 = *v7++;
    v9 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v16 + 1] & 4) == 0;
    c2 = v16;
    if ( v9 )
    {
      v18 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c2;
      if ( (v18[29] & 0x10) != 0 )
        v10 = (unsigned __int8)v18[285];
      else
        v10 = (unsigned __int16)c2;
LABEL_46:
      c2 = v10;
      goto LABEL_47;
    }
    if ( !n || (--n, !*v7) )
    {
      c2 = 0;
LABEL_47:
      LOWORD(v17) = c2;
      goto test;
    }
    v17 = (unsigned __int16)(*v7++ | (unsigned __int16)((_WORD)v16 << 8));
    c2 = v17;
    if ( (unsigned __int16)v17 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v17 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v17 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v17 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        LOWORD(v17) = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v17;
      }
    }
    else
    {
      LOWORD(v17) = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v17;
    }
test:
    if ( (_WORD)v17 != v11 )
      break;
    if ( !v11 || !n )
    {
LABEL_51:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v17 < v11 ? 1 : -1;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}
