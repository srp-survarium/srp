int __usercall cftoe2_l@<eax>(
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
  int v13; // ebx
  int v14; // ecx
  _BYTE *v15; // esi
  int v16; // eax
  _BYTE *v17; // esi
  _BYTE *v18; // esi
  int v19; // [esp-4h] [ebp-20h]
  _LocaleUpdate v20; // [esp+Ch] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v20, plocinfo);
  if ( !buf || !sizeInBytes )
  {
    v8 = _errno();
    v19 = 22;
LABEL_3:
    *v8 = v19;
    _invalid_parameter((int)buf, v19, 0);
    if ( v20.updated )
      v20.ptd->_ownlocale &= ~2u;
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
    shift((__m128i *)&buf[pflt->sign == 45], ndec > 0);
  v11 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v11 = buf + 1;
  }
  if ( ndec > 0 )
  {
    *v11 = v11[1];
    *++v11 = *v20.localeinfo.locinfo->lconv->decimal_point;
  }
  v12 = &v11[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v13 = -1;
  else
    v13 = sizeInBytes + buf - v12;
  if ( strcpy_s((int)pflt, v12, v13, "e+000") )
    _invoke_watson(0, (int)pflt, (int)v12);
  v14 = (int)(v12 + 2);
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
  if ( (_outputformat & 1) != 0 && *(_BYTE *)v14 == 48 )
    memmove(v14, (const __m128i *)(v14 + 1), 3u);
  if ( v20.updated )
    v20.ptd->_ownlocale &= ~2u;
  return 0;
}
