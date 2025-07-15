int __cdecl _iswctype_l(wchar_t c, unsigned __int16 mask, localeinfo_struct *plocinfo)
{
  _LocaleUpdate v4; // [esp+0h] [ebp-14h] BYREF
  unsigned __int16 CharType[2]; // [esp+10h] [ebp-4h] BYREF

  if ( c == 0xFFFF )
  {
    *(_DWORD *)CharType = 0;
  }
  else if ( c >= 0x100u )
  {
    _LocaleUpdate::_LocaleUpdate(&v4, plocinfo);
    if ( !__crtGetStringTypeW(&v4.localeinfo, 1u, &c, 1, CharType) )
      *(_DWORD *)CharType = 0;
    if ( v4.updated )
      v4.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *(_DWORD *)CharType = (unsigned __int16)(mask & _pwctype[c]);
  }
  return mask & CharType[0];
}
