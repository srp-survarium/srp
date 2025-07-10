unsigned int __usercall _cftoa_l@<eax>(
        unsigned int a1@<ebx>,
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v7; // esi
  int *v8; // eax
  unsigned int result; // eax
  unsigned int v10; // eax
  bool v11; // zf
  _BYTE *v12; // esi
  _BYTE *v13; // eax
  _BYTE *v14; // esi
  _BYTE *v15; // esi
  char *v16; // esi
  char *v17; // eax
  char *v18; // esi
  int x_low; // eax
  unsigned __int64 v20; // rax
  unsigned __int16 v21; // ax
  unsigned int v22; // ecx
  unsigned __int64 v23; // rax
  char *i; // eax
  _BYTE *v25; // esi
  __int64 v26; // rax
  __int64 v27; // rcx
  _BYTE *v28; // esi
  _BYTE *v29; // edi
  __int64 v30; // rax
  __int64 v31; // rcx
  __int64 v32; // rax
  __int64 v33; // rcx
  __int64 v34; // rcx
  __int64 v35; // [esp-Ch] [ebp-38h]
  unsigned int v36; // [esp-4h] [ebp-30h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-24h] BYREF
  __int64 exponent; // [esp+18h] [ebp-14h]
  unsigned __int64 mask; // [esp+20h] [ebp-Ch]
  int maskpos; // [esp+28h] [ebp-4h]
  char *pos; // [esp+38h] [ebp+Ch]

  LODWORD(exponent) = 1023;
  maskpos = 48;
  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v7 = buf;
  if ( !buf || !sizeInBytes )
  {
    v8 = _errno();
    v36 = 22;
LABEL_5:
    *v8 = v36;
    _invalid_parameter(a1, 0, v36);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v36;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v8 = _errno();
    v36 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v10 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v10 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf + 2, v10, ndec, 0);
    if ( result )
    {
      v11 = !_loc_update.updated;
      *buf = 0;
      if ( !v11 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v7 = buf + 1;
    }
    *v7 = 48;
    v12 = v7 + 1;
    *v12 = caps == 0 ? 120 : 88;
    strrchr(v12 + 1, 0x65u);
    if ( v13 )
    {
      *v13 = caps == 0 ? 112 : 80;
      v13[3] = 0;
    }
  }
  else
  {
    if ( (HIDWORD(pvalue->x) & 0x80000000) != 0 )
    {
      *buf = 45;
      v7 = buf + 1;
    }
    *v7 = 48;
    v14 = v7 + 1;
    *v14 = caps == 0 ? 120 : 88;
    v15 = v14 + 1;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      *v15 = 49;
      v16 = v15 + 1;
    }
    else
    {
      *v15 = 48;
      v16 = v15 + 1;
      if ( (unsigned int)&loc_FFFFF & HIDWORD(pvalue->x) | LODWORD(pvalue->x) )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v17 = v16;
    v18 = v16 + 1;
    pos = v17;
    if ( ndec )
      *v17 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v17 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = (unsigned int)&loc_FFFFF & HIDWORD(pvalue->x);
    if ( HIDWORD(mask) || x_low )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        LODWORD(v20) = mask & LODWORD(pvalue->x);
        HIDWORD(v20) = (unsigned int)&loc_FFFFF & HIDWORD(mask) & HIDWORD(pvalue->x);
        v21 = (v20 >> maskpos) + 48;
        if ( v21 > 0x39u )
          LOBYTE(v21) = (caps != 0 ? 7 : 39) + v21;
        v22 = HIDWORD(mask);
        maskpos -= 4;
        *v18++ = v21;
        --ndec;
        mask = __PAIR64__(v22, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0 )
      {
        LODWORD(v23) = mask & LODWORD(pvalue->x);
        HIDWORD(v23) = (unsigned int)&loc_FFFFF & HIDWORD(mask) & HIDWORD(pvalue->x);
        if ( (unsigned __int16)(v23 >> maskpos) > 8u )
        {
          for ( i = v18 - 1; *i == 102 || *i == 70; --i )
            *i = 48;
          if ( i == pos )
          {
            ++*(i - 1);
          }
          else if ( *i == 57 )
          {
            *i = caps != 0 ? 65 : 97;
          }
          else
          {
            ++*i;
          }
        }
      }
    }
    if ( ndec > 0 )
    {
      memset((int)v18, (unsigned __int8 *)0x30, ndec);
      v18 += ndec;
    }
    if ( !*pos )
      v18 = pos;
    *v18 = caps == 0 ? 112 : 80;
    v25 = v18 + 1;
    HIDWORD(v27) = 0;
    v26 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v26 < 0 )
    {
      *v25 = 45;
      v28 = v25 + 1;
      v26 = -v26;
    }
    else
    {
      *v25 = 43;
      v28 = v25 + 1;
    }
    v29 = v28;
    *v28 = 48;
    if ( v26 >= 0 )
    {
      LODWORD(v27) = 1000;
      if ( v26 >= 1000 )
      {
        v35 = v27;
        v31 = v26 % v27;
        v30 = v26 / v35;
        *v28++ = v30 + 48;
        HIDWORD(exponent) = HIDWORD(v30);
        v26 = v31;
        if ( v28 != v29 )
          goto LABEL_60;
      }
    }
    if ( v26 >= 100 )
    {
LABEL_60:
      v33 = v26 % 100;
      v32 = v26 / 100;
      *v28 = v32 + 48;
      HIDWORD(exponent) = HIDWORD(v32);
      ++v28;
      v26 = v33;
    }
    if ( v28 != v29 || v26 >= 10 )
    {
      v34 = v26 % 10;
      *v28++ = v26 / 10 + 48;
      LOBYTE(v26) = v26 % 10;
      HIDWORD(exponent) = HIDWORD(v34);
    }
    *v28 = v26 + 48;
    v28[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}
