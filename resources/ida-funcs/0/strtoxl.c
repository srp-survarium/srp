unsigned int __usercall strtoxl@<eax>(
        int a1@<ebx>,
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  unsigned __int8 v8; // bl
  const char *i; // edi
  int v10; // eax
  _BYTE *v11; // edi
  const unsigned __int16 *pctype; // esi
  unsigned int v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  const char *v16; // edi
  _LocaleUpdate v17; // [esp+8h] [ebp-14h] BYREF
  unsigned int v18; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(&v17, plocinfo);
  if ( endptr )
    *endptr = nptr;
  if ( !nptr || ibase && (ibase < 2 || ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, (int)nptr);
    if ( v17.updated )
      v17.ptd->_ownlocale &= ~2u;
    return 0;
  }
  locinfo = v17.localeinfo.locinfo;
  v8 = *nptr;
  v18 = 0;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v10 = locinfo->pctype[v8] & 8;
    }
    else
    {
      v10 = _isctype_l(v8, 8, &v17.localeinfo);
      locinfo = v17.localeinfo.locinfo;
    }
    if ( !v10 )
      break;
    v8 = *i;
  }
  if ( v8 == 45 )
  {
    flags |= 2u;
  }
  else if ( v8 != 43 )
  {
    goto LABEL_20;
  }
  v8 = *i++;
LABEL_20:
  if ( ibase )
  {
    if ( ibase != 16 || v8 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v8 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v11 = i + 1;
    v8 = *v11;
    i = v11 + 1;
  }
LABEL_32:
  pctype = locinfo->pctype;
  v13 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    if ( (pctype[v8] & 4) != 0 )
    {
      v14 = (char)v8 - 48;
    }
    else
    {
      if ( (pctype[v8] & 0x103) == 0 )
        break;
      v15 = (char)v8;
      if ( (unsigned __int8)(v8 - 97) <= 0x19u )
        v15 = (char)v8 - 32;
      v14 = v15 - 55;
    }
    if ( v14 >= ibase )
      break;
    flags |= 8u;
    if ( v18 < v13 || v18 == v13 && v14 <= 0xFFFFFFFF % ibase )
    {
      v18 = v14 + ibase * v18;
    }
    else
    {
      flags |= 4u;
      if ( !endptr )
        break;
    }
    v8 = *i++;
  }
  v16 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && v18 > 0x80000000 || (flags & 2) == 0 && v18 > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        v18 = -1;
      else
        v18 = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr )
      v16 = nptr;
    v18 = 0;
  }
  if ( endptr )
    *endptr = v16;
  if ( (flags & 2) != 0 )
    v18 = -v18;
  if ( v17.updated )
    v17.ptd->_ownlocale &= ~2u;
  return v18;
}
