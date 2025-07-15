_flt *__cdecl _fltin2(
        _flt *flt,
        const char *str,
        int len_ignore,
        int scale_ignore,
        int radix_ignore,
        localeinfo_struct *_Locale)
{
  int v6; // ebx
  INTRNCVT_STATUS v7; // eax
  const char *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const char *v10; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v10 = str;
  v6 = 0;
  flags = __strgtold12_l(&ld12, &EndPtr, str, 0, 0, 0, 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v6 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v7 = _ld12tod(&ld12, &x);
    if ( (flags & 2) != 0 || v7 == INTRNCVT_OVERFLOW )
      v6 = 128;
    if ( (flags & 1) != 0 || v7 == INTRNCVT_UNDERFLOW )
      v6 |= 0x100u;
  }
  flt->nbytes = EndPtr - v10;
  flt->dval = x.x;
  flt->flags = v6;
  return flt;
}
