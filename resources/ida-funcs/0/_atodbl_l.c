int __cdecl _atodbl_l(_CRT_DOUBLE *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  char *p_end_ptr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate v7; // [esp+10h] [ebp-24h] BYREF
  unsigned int v8; // [esp+20h] [ebp-14h]
  _LDBL12 pld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v7, plocinfo);
  v8 = __strgtold12_l(&pld12, (const char **)&p_end_ptr, str, 0, 0, 0, 0, &v7.localeinfo);
  v3 = _ld12tod(&pld12, d);
  if ( (v8 & 3) != 0 )
  {
    if ( (v8 & 1) != 0 )
      goto LABEL_8;
    if ( (v8 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( v7.updated )
        v7.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( v7.updated )
        v7.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( v7.updated )
    v7.ptd->_ownlocale &= ~2u;
  return 0;
}
