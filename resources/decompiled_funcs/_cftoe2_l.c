unsigned int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int *v8; // eax
  int v10; // eax
  char *v11; // esi
  char *v12; // esi
  unsigned int v13; // ebx
  unsigned __int8 *v14; // ecx
  _BYTE *v15; // esi
  int v16; // eax
  _BYTE *v17; // esi
  _BYTE *v18; // esi
  unsigned int v19; // [esp-4h] [ebp-20h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, plocinfo);
  if ( !buf || !sizeInBytes )
  {
    v8 = _errno();
    v19 = 22;
LABEL_3:
    *v8 = v19;
    _invalid_parameter((unsigned int)buf, v19, 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v19;
  }
  if ( ndec <= 0 )
    v10 = 0;
  else
    v10 = ndec;
  if ( sizeInBytes <= v10 + 9 )
  {
    v8 = _errno();
    v19 = 34;
    goto LABEL_3;
  }
  if ( g_fmt )
    shift(&buf[pflt->sign == 45], ndec > 0);
  v11 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v11 = buf + 1;
  }
  if ( ndec > 0 )
  {
    *v11 = v11[1];
    *++v11 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  }
  v12 = &v11[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v13 = -1;
  else
    v13 = sizeInBytes + buf - v12;
  if ( strcpy_s(v12, v13, "e+000") )
    _invoke_watson(0, (unsigned int)pflt, (unsigned int)v12);
  v14 = (unsigned __int8 *)(v12 + 2);
  if ( caps )
    *v12 = 69;
  v15 = v12 + 1;
  if ( *pflt->mantissa != 48 )
  {
    v16 = pflt->decpt - 1;
    if ( v16 < 0 )
    {
      v16 = 1 - pflt->decpt;
      *v15 = 45;
    }
    v17 = v15 + 1;
    if ( v16 >= 100 )
    {
      *v17 += v16 / 100;
      v16 %= 100;
    }
    v18 = v17 + 1;
    if ( v16 >= 10 )
    {
      *v18 += v16 / 10;
      LOBYTE(v16) = v16 % 10;
    }
    v18[1] += v16;
  }
  if ( (_outputformat & 1) != 0 && *v14 == 48 )
    memmove(v14, v14 + 1, 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}
