int __usercall _cftoa_l@<eax>(
        int a1@<ebx>,
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v7; // esi
  int *v8; // eax
  int result; // eax
  unsigned int v10; // eax
  bool v11; // zf
  char *v12; // esi
  _BYTE *v13; // eax
  _BYTE *v14; // esi
  _BYTE *v15; // esi
  char *v16; // esi
  char *v17; // eax
  char *v18; // esi
  int x_low; // eax
  unsigned __int16 v20; // ax
  unsigned int v21; // ecx
  char *i; // eax
  _BYTE *v23; // esi
  __int64 v24; // rax
  __int64 v25; // rcx
  _BYTE *v26; // esi
  _BYTE *v27; // edi
  __int64 v28; // rax
  __int64 v29; // rcx
  __int64 v30; // rax
  __int64 v31; // rcx
  __int64 v32; // rcx
  __int64 v33; // [esp-Ch] [ebp-38h]
  int v34; // [esp-4h] [ebp-30h]
  _LocaleUpdate v35; // [esp+8h] [ebp-24h] BYREF
  int v36; // [esp+18h] [ebp-14h]
  int v37; // [esp+1Ch] [ebp-10h]
  unsigned __int64 v38; // [esp+20h] [ebp-Ch]
  int v39; // [esp+28h] [ebp-4h]
  char *v40; // [esp+38h] [ebp+Ch]

  v36 = 1023;
  v39 = 48;
  _LocaleUpdate::_LocaleUpdate(&v35, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v7 = buf;
  if ( !buf || !sizeInBytes )
  {
    v8 = _errno();
    v34 = 22;
LABEL_5:
    *v8 = v34;
    _invalid_parameter(a1, 0, v34);
    if ( v35.updated )
      v35.ptd->_ownlocale &= ~2u;
    return v34;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v8 = _errno();
    v34 = 34;
    goto LABEL_5;
  }
  LODWORD(v38) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v10 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v10 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf + 2, v10, ndec, 0);
    if ( result )
    {
      v11 = !v35.updated;
      *buf = 0;
      if ( !v11 )
        v35.ptd->_ownlocale &= ~2u;
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
      if ( HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x) )
        v36 = 1022;
      else
        v36 = 0;
    }
    v17 = v16;
    v18 = v16 + 1;
    v40 = v17;
    if ( ndec )
      *v17 = *v35.localeinfo.locinfo->lconv->decimal_point;
    else
      *v17 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(v38) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(v38) || x_low )
    {
      LODWORD(v38) = 0;
      HIDWORD(v38) = &locret_F0000;
      do
      {
        if ( ndec <= 0 )
          break;
        v20 = ((v38 & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> v39) + 48;
        if ( v20 > 0x39u )
          LOBYTE(v20) = (caps != 0 ? 7 : 39) + v20;
        v21 = HIDWORD(v38);
        v39 -= 4;
        *v18++ = v20;
        --ndec;
        v38 = __PAIR64__(v21, v38) >> 4;
      }
      while ( (v39 & 0x8000u) == 0 );
      if ( (v39 & 0x8000u) == 0 && (unsigned __int16)((v38 & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> v39) > 8u )
      {
        for ( i = v18 - 1; *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == v40 )
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
    if ( ndec > 0 )
    {
      memset((int)v18, 48, ndec);
      v18 += ndec;
    }
    if ( !*v40 )
      v18 = v40;
    *v18 = caps == 0 ? 112 : 80;
    v23 = v18 + 1;
    HIDWORD(v25) = 0;
    v24 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)v36;
    if ( v24 < 0 )
    {
      *v23 = 45;
      v26 = v23 + 1;
      v24 = -v24;
    }
    else
    {
      *v23 = 43;
      v26 = v23 + 1;
    }
    v27 = v26;
    *v26 = 48;
    if ( v24 >= 0 )
    {
      LODWORD(v25) = 1000;
      if ( v24 >= 1000 )
      {
        v33 = v25;
        v29 = v24 % v25;
        v28 = v24 / v33;
        *v26++ = v28 + 48;
        v37 = HIDWORD(v28);
        v24 = v29;
        if ( v26 != v27 )
          goto LABEL_60;
      }
    }
    if ( v24 >= 100 )
    {
LABEL_60:
      v31 = v24 % 100;
      v30 = v24 / 100;
      *v26 = v30 + 48;
      v37 = HIDWORD(v30);
      ++v26;
      v24 = v31;
    }
    if ( v26 != v27 || v24 >= 10 )
    {
      v32 = v24 % 10;
      *v26++ = v24 / 10 + 48;
      LOBYTE(v24) = v24 % 10;
      v37 = HIDWORD(v32);
    }
    *v26 = v24 + 48;
    v26[1] = 0;
  }
  if ( v35.updated )
    v35.ptd->_ownlocale &= ~2u;
  return 0;
}
