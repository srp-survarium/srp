void __cdecl _cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char *v2; // eax
  char i; // cl
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *v7; // edx
  char v8; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, _Locale);
  v2 = buf;
  for ( i = *buf; *v2; i = *++v2 )
  {
    if ( i == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 )
  {
    while ( 1 )
    {
      v6 = *v5;
      if ( !*v5 || v6 == 101 || v6 == 69 )
        break;
      ++v5;
    }
    v7 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v8 = *v7;
      ++v5;
      ++v7;
      *v5 = v8;
    }
    while ( v8 );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}
