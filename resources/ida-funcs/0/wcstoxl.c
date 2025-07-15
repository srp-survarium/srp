unsigned int __usercall wcstoxl@<eax>(
        unsigned int a1@<esi>,
        localeinfo_struct *plocinfo,
        const wchar_t *nptr,
        const wchar_t **endptr,
        unsigned int ibase,
        int flags)
{
  unsigned __int16 v7; // si
  unsigned __int16 *v8; // edi
  unsigned __int16 *v9; // edi
  unsigned int v10; // ebx
  unsigned int v11; // eax
  int v12; // eax
  const wchar_t *v13; // edi
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( endptr )
    *endptr = nptr;
  if ( !nptr || ibase && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(0, (unsigned int)nptr, a1);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  v7 = *nptr;
  number = 0;
  v8 = (unsigned __int16 *)(nptr + 1);
  while ( _iswctype_l(v7, 8u, &_loc_update.localeinfo) )
    v7 = *v8++;
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_17;
  }
  v7 = *v8++;
LABEL_17:
  if ( ibase )
    goto LABEL_24;
  if ( !_wchartodigit(v7) )
  {
    if ( *v8 != 120 && *v8 != 88 )
    {
      ibase = 8;
      goto LABEL_29;
    }
    ibase = 16;
LABEL_24:
    if ( ibase == 16 && !_wchartodigit(v7) && (*v8 == 120 || *v8 == 88) )
    {
      v9 = v8 + 1;
      v7 = *v9;
      v8 = v9 + 1;
    }
    goto LABEL_29;
  }
  ibase = 10;
LABEL_29:
  v15 = 0xFFFFFFFF % ibase;
  v10 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    v11 = _wchartodigit(v7);
    if ( v11 != -1 )
      goto LABEL_37;
    if ( (v7 < 0x41u || v7 > 0x5Au) && (unsigned __int16)(v7 - 97) > 0x19u )
      break;
    v12 = v7;
    if ( (unsigned __int16)(v7 - 97) <= 0x19u )
      v12 = v7 - 32;
    v11 = v12 - 55;
LABEL_37:
    if ( v11 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v11 <= v15 )
    {
      number = v11 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( !endptr )
        break;
    }
    v7 = *v8++;
  }
  v13 = v8 - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr )
      v13 = nptr;
    number = 0;
  }
  if ( endptr )
    *endptr = v13;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}
