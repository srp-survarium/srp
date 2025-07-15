int __cdecl _mbctolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate v3; // [esp+4h] [ebp-18h] BYREF
  wchar_t v4; // [esp+14h] [ebp-8h] BYREF
  char v5[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v3, plocinfo);
  if ( c <= 0xFF )
  {
    if ( (v3.localeinfo.mbcinfo->mbctype[c + 1] & 0x10) != 0 )
      result = v3.localeinfo.mbcinfo->mbcasemap[c];
    else
      result = c;
LABEL_11:
    if ( v3.updated )
      v3.ptd->_ownlocale &= ~2u;
    return result;
  }
  v5[0] = BYTE1(c);
  v5[1] = c;
  if ( (v3.localeinfo.mbcinfo->mbctype[BYTE1(c) + 1] & 4) != 0
    && __crtLCMapStringA(
         &v3.localeinfo,
         v3.localeinfo.mbcinfo->mblcid,
         0x100u,
         v5,
         2,
         &v4,
         2,
         v3.localeinfo.mbcinfo->mbcodepage,
         1) )
  {
    result = HIBYTE(v4) + ((unsigned __int8)v4 << 8);
    goto LABEL_11;
  }
  if ( v3.updated )
    v3.ptd->_ownlocale &= ~2u;
  return c;
}
