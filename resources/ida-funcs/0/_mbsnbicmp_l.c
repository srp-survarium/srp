void __usercall _mbsnbicmp_l(
        const char *a1@<edi>,
        int a2@<esi>,
        char *s1,
        char *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  char *v6; // edi
  unsigned __int16 v7; // cx
  bool v8; // zf
  int v9; // ecx
  __int16 v10; // si
  unsigned __int8 v11; // dl
  int v12; // ecx
  char *v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  char *v17; // ecx
  _LocaleUpdate v18; // [esp+4h] [ebp-18h] BYREF
  int v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(&v18, plocinfo);
  if ( !n )
  {
    if ( v18.updated )
      v18.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( !v18.localeinfo.mbcinfo->ismbcodepage )
  {
    _strnicmp(0, a1, s1, s2, n);
    if ( v18.updated )
      v18.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( !s1 )
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)a1, a2);
    if ( v18.updated )
      v18.ptd->_ownlocale &= ~2u;
    return;
  }
  v6 = s2;
  if ( !s2 )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, a2);
    if ( v18.updated )
      v18.ptd->_ownlocale &= ~2u;
    return;
  }
  while ( 1 )
  {
    v7 = (unsigned __int8)*s1;
    --n;
    ++s1;
    v8 = (v18.localeinfo.mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) == 0;
    v19 = v7;
    if ( v8 )
    {
      v13 = (char *)v18.localeinfo.mbcinfo + (unsigned __int16)v19;
      if ( (v13[29] & 0x10) != 0 )
        v14 = (unsigned __int8)v13[285];
      else
        v14 = (unsigned __int16)v19;
      v19 = v14;
      goto LABEL_32;
    }
    if ( !n )
    {
      v9 = (unsigned __int8)*v6;
      v8 = (v18.localeinfo.mbcinfo->mbctype[v9 + 1] & 4) == 0;
      v19 = 0;
      if ( !v8 )
        goto LABEL_51;
      v9 = (unsigned __int16)v9;
      v10 = 0;
      goto LABEL_46;
    }
    if ( !*s1 )
    {
      v19 = 0;
LABEL_32:
      v10 = v19;
      goto LABEL_33;
    }
    v11 = *s1++;
    v12 = (unsigned __int16)(v11 | (unsigned __int16)(v7 << 8));
    v10 = v12;
    v19 = v12;
    if ( (unsigned __int16)v12 < v18.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v12 > v18.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v12 >= v18.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v12 <= v18.localeinfo.mbcinfo->mbulinfo[4] )
      {
        v10 = v18.localeinfo.mbcinfo->mbulinfo[5] + v12;
      }
    }
    else
    {
      v10 = v18.localeinfo.mbcinfo->mbulinfo[2] + v12;
    }
LABEL_33:
    v15 = (unsigned __int8)*v6++;
    v8 = (v18.localeinfo.mbcinfo->mbctype[(unsigned __int8)v15 + 1] & 4) == 0;
    v20 = v15;
    if ( v8 )
    {
      v17 = (char *)v18.localeinfo.mbcinfo + (unsigned __int16)v20;
      if ( (v17[29] & 0x10) != 0 )
        v9 = (unsigned __int8)v17[285];
      else
        v9 = (unsigned __int16)v20;
LABEL_46:
      v20 = v9;
      goto LABEL_47;
    }
    if ( !n || (--n, !*v6) )
    {
      v20 = 0;
LABEL_47:
      LOWORD(v16) = v20;
      goto test;
    }
    v16 = (unsigned __int16)((unsigned __int8)*v6++ | (unsigned __int16)((_WORD)v15 << 8));
    v20 = v16;
    if ( (unsigned __int16)v16 < v18.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v16 > v18.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v16 >= v18.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v16 <= v18.localeinfo.mbcinfo->mbulinfo[4] )
      {
        LOWORD(v16) = v18.localeinfo.mbcinfo->mbulinfo[5] + v16;
      }
    }
    else
    {
      LOWORD(v16) = v18.localeinfo.mbcinfo->mbulinfo[2] + v16;
    }
test:
    if ( (_WORD)v16 != v10 )
      break;
    if ( !v10 || !n )
    {
LABEL_51:
      if ( v18.updated )
        v18.ptd->_ownlocale &= ~2u;
      return;
    }
  }
  if ( v18.updated )
    v18.ptd->_ownlocale &= ~2u;
}
