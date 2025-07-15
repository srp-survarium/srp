unsigned int __usercall _Strftime_l@<eax>(
        int a1@<edi>,
        int a2@<esi>,
        char *string,
        int maxsize,
        const char *format,
        const tm *timeptr,
        __lc_time_data *lc_time_arg,
        localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  int v9; // edi
  const char *v10; // esi
  __lc_time_data *lc_time_curr; // eax
  unsigned __int8 v12; // al
  unsigned int v13; // eax
  _LocaleUpdate v14; // [esp+4h] [ebp-20h] BYREF
  char *v15; // [esp+14h] [ebp-10h]
  __lc_time_data *v16; // [esp+18h] [ebp-Ch]
  int v17; // [esp+1Ch] [ebp-8h]
  unsigned int v18; // [esp+20h] [ebp-4h] BYREF

  v17 = 0;
  v15 = string;
  _LocaleUpdate::_LocaleUpdate(&v14, plocinfo);
  if ( !string )
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    if ( v14.updated )
      v14.ptd->_ownlocale &= ~2u;
    return 0;
  }
  v9 = maxsize;
  if ( !maxsize )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, a2);
    if ( v14.updated )
      v14.ptd->_ownlocale &= ~2u;
    return 0;
  }
  v10 = format;
  *string = 0;
  if ( !v10 )
    goto LABEL_35;
  lc_time_curr = lc_time_arg;
  if ( !lc_time_arg )
    lc_time_curr = v14.localeinfo.locinfo->lc_time_curr;
  v16 = lc_time_curr;
  v18 = v9;
  if ( !v9 )
  {
LABEL_30:
    *v15 = 0;
    if ( !v17 && !v18 )
    {
      *_errno() = 34;
LABEL_36:
      if ( v14.updated )
        v14.ptd->_ownlocale &= ~2u;
      return 0;
    }
LABEL_35:
    *_errno() = 22;
    _invalid_parameter(0, v9, (int)v10);
    goto LABEL_36;
  }
  do
  {
    v12 = *v10;
    if ( !*v10 )
      break;
    if ( v12 == 37 )
    {
      if ( !timeptr )
        goto LABEL_35;
      ++v10;
      v13 = 0;
      if ( *v10 == 35 )
      {
        v13 = 1;
        ++v10;
      }
      if ( !expandtime(*v10, timeptr, &string, &v14.localeinfo, &v18, v16, v13) )
      {
        if ( v18 )
          v17 = 1;
        goto LABEL_30;
      }
      ++v10;
    }
    else
    {
      if ( _isleadbyte_l(v12, &v14.localeinfo) && v18 > 1 )
      {
        if ( !v10[1] )
        {
          v17 = 1;
          goto LABEL_30;
        }
        *string++ = *v10;
        --v18;
        ++v10;
      }
      *string++ = *v10++;
      --v18;
    }
  }
  while ( v18 );
  if ( !v18 )
    goto LABEL_30;
  *string = 0;
  result = v9 - v18;
  if ( v14.updated )
    v14.ptd->_ownlocale &= ~2u;
  return result;
}
