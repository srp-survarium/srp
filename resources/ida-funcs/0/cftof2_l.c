int __usercall cftof2_l@<eax>(
        char *buf@<ecx>,
        _strflt *pflt@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v8; // esi
  char *v10; // eax
  __m128i *v11; // esi
  int decpt; // eax
  __m128i *v13; // esi
  int v14; // ebx
  __m128i *v15; // esi
  int v16; // ebx
  _LocaleUpdate v17; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(&v17, plocinfo);
  if ( buf && sizeInBytes )
  {
    if ( g_fmt && v8 == ndec )
    {
      v10 = &buf[v8 + (pflt->sign == 45)];
      *v10 = 48;
      v10[1] = 0;
    }
    v11 = (__m128i *)buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v11 = (__m128i *)(buf + 1);
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = (__m128i *)((char *)v11 + decpt);
    }
    else
    {
      shift(v11, 1);
      v11->m128i_i8[0] = 48;
      v13 = (__m128i *)&v11->m128i_i8[1];
    }
    if ( ndec > 0 )
    {
      shift(v13, 1);
      v13->m128i_i8[0] = *v17.localeinfo.locinfo->lconv->decimal_point;
      v14 = pflt->decpt;
      v15 = (__m128i *)&v13->m128i_i8[1];
      if ( v14 < 0 )
      {
        v16 = -v14;
        if ( g_fmt || ndec >= v16 )
          ndec = v16;
        shift(v15, ndec);
        memset((int)v15, 48, ndec);
      }
    }
    if ( v17.updated )
      v17.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter((int)pflt, (int)buf, 22);
    if ( v17.updated )
      v17.ptd->_ownlocale &= ~2u;
    return 22;
  }
}
