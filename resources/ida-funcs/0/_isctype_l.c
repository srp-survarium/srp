int __cdecl _isctype_l(int c, int mask, localeinfo_struct *plocinfo)
{
  __int16 v3; // bx
  int v4; // eax
  int v5; // ecx
  int result; // eax
  _LocaleUpdate v7; // [esp+4h] [ebp-18h] BYREF
  char SrcStr; // [esp+14h] [ebp-8h] BYREF
  char v9; // [esp+15h] [ebp-7h]
  char v10; // [esp+16h] [ebp-6h]
  unsigned __int16 CharType; // [esp+18h] [ebp-4h] BYREF
  int v12; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(&v7, plocinfo);
  v3 = c;
  if ( (unsigned int)(c + 1) <= 0x100 )
  {
    v4 = v7.localeinfo.locinfo->pctype[c];
    goto LABEL_11;
  }
  v12 = c >> 8;
  if ( _isleadbyte_l(HIBYTE(v3), &v7.localeinfo) )
  {
    SrcStr = v12;
    v9 = v3;
    v10 = 0;
    v5 = 2;
  }
  else
  {
    SrcStr = v3;
    v9 = 0;
    v5 = 1;
  }
  if ( __crtGetStringTypeA(
         &v7.localeinfo,
         1u,
         &SrcStr,
         v5,
         &CharType,
         v7.localeinfo.locinfo->lc_codepage,
         v7.localeinfo.locinfo->lc_handle[2],
         1) )
  {
    v4 = CharType;
LABEL_11:
    result = mask & v4;
    if ( v7.updated )
      v7.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( v7.updated )
    v7.ptd->_ownlocale &= ~2u;
  return 0;
}
