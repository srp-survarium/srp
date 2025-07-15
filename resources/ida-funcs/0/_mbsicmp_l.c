unsigned int __usercall _mbsicmp_l@<eax>(int a1@<ebx>, int a2@<edi>, char *s1, char *s2, localeinfo_struct *plocinfo)
{
  char *v5; // edx
  unsigned int result; // eax
  char *v7; // ebx
  threadmbcinfostruct *mbcinfo; // eax
  unsigned __int16 v9; // cx
  char *v10; // edx
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
  _LocaleUpdate v22; // [esp+4h] [ebp-14h] BYREF
  wchar_t v23; // [esp+14h] [ebp-4h] BYREF
  char *v24; // [esp+20h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(&v22, plocinfo);
  v5 = s1;
  if ( !s1 )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    if ( v22.updated )
      v22.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v7 = s2;
  if ( !s2 )
  {
    *_errno() = 22;
    _invalid_parameter(0, a2, 0);
    if ( v22.updated )
      v22.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  mbcinfo = v22.localeinfo.mbcinfo;
  if ( !v22.localeinfo.mbcinfo->ismbcodepage )
  {
    result = _stricmp_l(a2, 0, s1, s2, &v22.localeinfo);
    if ( v22.updated )
      v22.ptd->_ownlocale &= ~2u;
    return result;
  }
  while ( 1 )
  {
    v9 = (unsigned __int8)*v5;
    v10 = v5 + 1;
    v24 = v10;
    if ( (mbcinfo->mbctype[(unsigned __int8)v9 + 1] & 4) != 0 )
    {
      if ( *v10 )
      {
        v12 = __crtLCMapStringA(&v22.localeinfo, mbcinfo->mblcid, 0x200u, v10 - 1, 2, &v23, 2, mbcinfo->mbcodepage, 1);
        if ( v12 == 1 )
        {
          v13 = (unsigned __int8)v23;
        }
        else
        {
          if ( v12 != 2 )
            goto LABEL_37;
          v13 = HIBYTE(v23) + ((unsigned __int8)v23 << 8);
        }
        ++v24;
        v11 = v13;
        mbcinfo = v22.localeinfo.mbcinfo;
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
    v16 = (unsigned __int8)*v7++;
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
      if ( v22.updated )
        v22.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( !v11 )
    {
      if ( v22.updated )
        v22.ptd->_ownlocale &= ~2u;
      return 0;
    }
    v5 = v24;
  }
  if ( !*v7 )
  {
    v17 = 0;
    goto LABEL_34;
  }
  v18 = __crtLCMapStringA(&v22.localeinfo, mbcinfo->mblcid, 0x200u, v7 - 1, 2, &v23, 2, mbcinfo->mbcodepage, 1);
  if ( v18 == 1 )
  {
    v19 = (unsigned __int8)v23;
LABEL_30:
    v17 = v19;
    mbcinfo = v22.localeinfo.mbcinfo;
    ++v7;
    goto LABEL_34;
  }
  if ( v18 == 2 )
  {
    v19 = HIBYTE(v23) + ((unsigned __int8)v23 << 8);
    goto LABEL_30;
  }
LABEL_37:
  *_errno() = 22;
  if ( v22.updated )
    v22.ptd->_ownlocale &= ~2u;
  return 0x7FFFFFFF;
}
