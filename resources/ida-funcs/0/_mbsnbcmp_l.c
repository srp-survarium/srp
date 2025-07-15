int __usercall _mbsnbcmp_l@<eax>(int a1@<esi>, char *s1, char *s2, unsigned int n, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadmbcinfostruct *mbcinfo; // edi
  char *v7; // esi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int8 v11; // al
  _LocaleUpdate v12; // [esp+4h] [ebp-10h] BYREF

  if ( !n )
    return 0;
  _LocaleUpdate::_LocaleUpdate(&v12, plocinfo);
  mbcinfo = v12.localeinfo.mbcinfo;
  if ( !v12.localeinfo.mbcinfo->ismbcodepage )
  {
    result = strncmp(s1, s2, n);
    if ( v12.updated )
      v12.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( !s1 )
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)mbcinfo, a1);
    if ( v12.updated )
      v12.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v7 = s2;
  if ( !s2 )
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)mbcinfo, 0);
    if ( v12.updated )
      v12.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    v8 = (unsigned __int8)*s1;
    --n;
    ++s1;
    v9 = v8;
    if ( (v12.localeinfo.mbcinfo->mbctype[(unsigned __int8)v8 + 1] & 4) == 0 )
      goto LABEL_24;
    if ( n )
    {
      if ( *s1 )
      {
        v11 = *s1++;
        v9 = v11 | (unsigned __int16)(v9 << 8);
      }
      else
      {
        v9 = 0;
      }
LABEL_24:
      LOWORD(v10) = (unsigned __int8)*v7++;
      if ( (v12.localeinfo.mbcinfo->mbctype[(unsigned __int8)v10 + 1] & 4) != 0 )
      {
        if ( n && (--n, *v7) )
          LOWORD(v10) = (unsigned __int8)*v7++ | (unsigned __int16)((_WORD)v10 << 8);
        else
          LOWORD(v10) = 0;
      }
      goto test_0;
    }
    v10 = (unsigned __int8)*v7;
    v9 = 0;
    if ( (v12.localeinfo.mbcinfo->mbctype[v10 + 1] & 4) != 0 )
      goto LABEL_17;
test_0:
    if ( (_WORD)v10 != v9 )
      break;
    if ( !v9 || !n )
    {
LABEL_17:
      if ( v12.updated )
        v12.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v10 < v9 ? 1 : -1;
  if ( v12.updated )
    v12.ptd->_ownlocale &= ~2u;
  return result;
}
