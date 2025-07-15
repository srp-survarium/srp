unsigned __int64 __usercall strtoxq@<edx:eax>(
        int a1@<esi>,
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        int ibase,
        int flags)
{
  const char *v6; // edi
  threadlocaleinfostruct *locinfo; // esi
  unsigned __int8 v9; // al
  bool v10; // cc
  int v11; // eax
  unsigned __int8 v12; // al
  _BYTE *v13; // edi
  const unsigned __int16 *pctype; // ebx
  unsigned int v15; // esi
  int v16; // eax
  unsigned __int8 v17; // al
  _LocaleUpdate v18; // [esp+8h] [ebp-38h] BYREF
  int v19; // [esp+1Ch] [ebp-24h]
  unsigned __int64 v20; // [esp+20h] [ebp-20h]
  unsigned __int64 v21; // [esp+28h] [ebp-18h]
  unsigned __int64 v22; // [esp+30h] [ebp-10h]
  const char *v23; // [esp+38h] [ebp-8h]
  unsigned __int8 v24; // [esp+3Fh] [ebp-1h]

  _LocaleUpdate::_LocaleUpdate(&v18, plocinfo);
  v6 = nptr;
  if ( endptr )
    *endptr = nptr;
  if ( !nptr || ibase && (ibase < 2 || ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(0, (int)nptr, a1);
    if ( v18.updated )
      v18.ptd->_ownlocale &= ~2u;
    return 0;
  }
  locinfo = v18.localeinfo.locinfo;
  v22 = 0;
  do
  {
    v9 = *v6++;
    v10 = locinfo->mb_cur_max <= 1;
    v24 = v9;
    if ( v10 )
    {
      v11 = locinfo->pctype[v24] & 8;
    }
    else
    {
      v11 = _isctype_l(v24, 8, &v18.localeinfo);
      locinfo = v18.localeinfo.locinfo;
    }
  }
  while ( v11 );
  v23 = v6;
  if ( v24 == 45 )
  {
    flags |= 2u;
  }
  else if ( v24 != 43 )
  {
    goto LABEL_19;
  }
  v12 = *v6++;
  v23 = v6;
  v24 = v12;
LABEL_19:
  if ( !ibase )
  {
    if ( v24 != 48 )
    {
      ibase = 10;
      goto LABEL_31;
    }
    if ( *v6 != 120 && *v6 != 88 )
    {
      ibase = 8;
      goto LABEL_31;
    }
    ibase = 16;
  }
  if ( ibase == 16 && v24 == 48 && (*v6 == 120 || *v6 == 88) )
  {
    v13 = v6 + 1;
    v24 = *v13;
    v23 = v13 + 1;
  }
LABEL_31:
  v19 = ibase >> 31;
  pctype = locinfo->pctype;
  v20 = 0xFFFFFFFFFFFFFFFFuLL % ibase;
  v21 = 0xFFFFFFFFFFFFFFFFuLL / ibase;
  while ( 1 )
  {
    if ( (pctype[v24] & 4) != 0 )
    {
      v15 = (char)v24 - 48;
    }
    else
    {
      if ( (pctype[v24] & 0x103) == 0 )
        break;
      v16 = (char)v24;
      if ( (unsigned __int8)(v24 - 97) <= 0x19u )
        v16 = (char)v24 - 32;
      v15 = v16 - 55;
    }
    if ( v15 >= ibase )
      break;
    flags |= 8u;
    if ( v22 < v21 || v22 == v21 && v15 <= v20 )
    {
      v22 = v15 + __PAIR64__(v19, ibase) * v22;
    }
    else
    {
      flags |= 4u;
      if ( !endptr )
        break;
    }
    v17 = *v23++;
    v24 = v17;
  }
  --v23;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0
      && ((flags & 2) != 0 && v22 > 0x8000000000000000uLL || (flags & 2) == 0 && (v22 & 0x8000000000000000uLL) != 0LL) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
      {
        v22 = -1;
      }
      else if ( (flags & 2) != 0 )
      {
        v22 = 0x8000000000000000uLL;
      }
      else
      {
        v22 = 0x7FFFFFFFFFFFFFFFLL;
      }
    }
  }
  else
  {
    if ( endptr )
      v23 = nptr;
    v22 = 0;
  }
  if ( endptr )
    *endptr = v23;
  if ( (flags & 2) != 0 )
    v22 = -(__int64)v22;
  if ( v18.updated )
    v18.ptd->_ownlocale &= ~2u;
  return v22;
}
