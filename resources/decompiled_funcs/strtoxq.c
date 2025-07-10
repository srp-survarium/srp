unsigned __int64 __usercall strtoxq@<edx:eax>(
        unsigned int a1@<esi>,
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        int ibase,
        int flags)
{
  const char *v6; // edi
  threadlocaleinfostruct *locinfo; // esi
  char v9; // al
  bool v10; // cc
  int v11; // eax
  char v12; // al
  const char *v13; // edi
  const unsigned __int16 *pctype; // ebx
  unsigned int v15; // esi
  int v16; // eax
  char v17; // al
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-38h] BYREF
  int v19; // [esp+1Ch] [ebp-24h]
  unsigned __int64 v20; // [esp+20h] [ebp-20h]
  unsigned __int64 maxval; // [esp+28h] [ebp-18h]
  unsigned __int64 number; // [esp+30h] [ebp-10h]
  const char *p; // [esp+38h] [ebp-8h]
  char c; // [esp+3Fh] [ebp-1h]

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  v6 = nptr;
  if ( endptr )
    *endptr = nptr;
  if ( !nptr || ibase && (ibase < 2 || ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(0, (unsigned int)nptr, a1);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  locinfo = _loc_update.localeinfo.locinfo;
  number = 0;
  do
  {
    v9 = *v6++;
    v10 = locinfo->mb_cur_max <= 1;
    c = v9;
    if ( v10 )
    {
      v11 = locinfo->pctype[(unsigned __int8)c] & 8;
    }
    else
    {
      v11 = _isctype_l((unsigned __int8)c, 8, &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
  }
  while ( v11 );
  p = v6;
  if ( c == 45 )
  {
    flags |= 2u;
  }
  else if ( c != 43 )
  {
    goto LABEL_19;
  }
  v12 = *v6++;
  p = v6;
  c = v12;
LABEL_19:
  if ( !ibase )
  {
    if ( c != 48 )
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
  if ( ibase == 16 && c == 48 && (*v6 == 120 || *v6 == 88) )
  {
    v13 = v6 + 1;
    c = *v13;
    p = v13 + 1;
  }
LABEL_31:
  v19 = ibase >> 31;
  pctype = locinfo->pctype;
  v20 = 0xFFFFFFFFFFFFFFFFuLL % ibase;
  maxval = 0xFFFFFFFFFFFFFFFFuLL / ibase;
  while ( 1 )
  {
    if ( (pctype[(unsigned __int8)c] & 4) != 0 )
    {
      v15 = c - 48;
    }
    else
    {
      if ( (pctype[(unsigned __int8)c] & 0x103) == 0 )
        break;
      v16 = c;
      if ( (unsigned __int8)(c - 97) <= 0x19u )
        v16 = c - 32;
      v15 = v16 - 55;
    }
    if ( v15 >= ibase )
      break;
    flags |= 8u;
    if ( number < maxval || number == maxval && v15 <= v20 )
    {
      number = v15 + __PAIR64__(v19, ibase) * number;
    }
    else
    {
      flags |= 4u;
      if ( !endptr )
        break;
    }
    v17 = *p++;
    c = v17;
  }
  --p;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0
      && ((flags & 2) != 0 && number > 0x8000000000000000uLL
       || (flags & 2) == 0 && (number & 0x8000000000000000uLL) != 0LL) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
      {
        number = -1;
      }
      else if ( (flags & 2) != 0 )
      {
        number = 0x8000000000000000uLL;
      }
      else
      {
        number = 0x7FFFFFFFFFFFFFFFLL;
      }
    }
  }
  else
  {
    if ( endptr )
      p = nptr;
    number = 0;
  }
  if ( endptr )
    *endptr = p;
  if ( (flags & 2) != 0 )
    number = -(__int64)number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}
