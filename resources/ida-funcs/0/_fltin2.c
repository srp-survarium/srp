_flt *__cdecl _fltin2(
        _flt *flt,
        char *str,
        int len_ignore,
        int scale_ignore,
        int radix_ignore,
        localeinfo_struct *_Locale)
{
  int v6; // ebx
  INTRNCVT_STATUS v7; // eax
  char *p_end_ptr; // [esp+Ch] [ebp-24h] BYREF
  char *v10; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE d; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int v12; // [esp+1Ch] [ebp-14h]
  _LDBL12 pld12; // [esp+20h] [ebp-10h] BYREF

  v10 = str;
  v6 = 0;
  v12 = __strgtold12_l(&pld12, (const char **)&p_end_ptr, str, 0, 0, 0, 0, _Locale);
  if ( (v12 & 4) != 0 )
  {
    v6 = 512;
    *(_CRT_DOUBLE *)&d.x = 0;
  }
  else
  {
    v7 = _ld12tod(&pld12, &d);
    if ( (v12 & 2) != 0 || v7 == INTRNCVT_OVERFLOW )
      v6 = 128;
    if ( (v12 & 1) != 0 || v7 == INTRNCVT_UNDERFLOW )
      v6 |= 0x100u;
  }
  flt->nbytes = p_end_ptr - v10;
  flt->dval = d.x;
  flt->flags = v6;
  return flt;
}
