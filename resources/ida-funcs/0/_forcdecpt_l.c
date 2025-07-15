void __cdecl _forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  char *v2; // esi
  bool i; // zf
  char v4; // al
  char *v5; // esi
  char v6; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&_loc_update, _Locale);
  v2 = buffer;
  for ( i = tolower(*buffer) == 101; !i; i = isdigit((unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower(*v2) == 120 )
    v2 += 2;
  v4 = *v2;
  *v2 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = v4;
    v4 = v6;
  }
  while ( *v5++ );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}
