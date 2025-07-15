int __cdecl _toupper_l(int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate v9; // [esp+4h] [ebp-18h] BYREF
  wchar_t DestStr; // [esp+14h] [ebp-8h] BYREF
  char SrcStr; // [esp+18h] [ebp-4h] BYREF
  char v12; // [esp+19h] [ebp-3h]
  char v13; // [esp+1Ah] [ebp-2h]
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
  if ( (unsigned int)c >= 0x100 )
  {
    if ( v9.localeinfo.locinfo->mb_cur_max > 1 && (ca = c >> 8, _isleadbyte_l(BYTE1(c), &v9.localeinfo)) )
    {
      SrcStr = ca;
      v12 = c;
      v13 = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      SrcStr = c;
      v12 = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           &v9.localeinfo,
           v9.localeinfo.locinfo->lc_handle[2],
           0x200u,
           &SrcStr,
           v6,
           &DestStr,
           3,
           v9.localeinfo.locinfo->lc_codepage,
           1);
    if ( v7 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)DestStr;
      if ( !v8 )
        result = HIBYTE(DestStr) | ((unsigned __int8)DestStr << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = v9.localeinfo.locinfo;
    if ( v9.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = v9.localeinfo.locinfo->pctype[c] & 2;
    }
    else
    {
      v4 = _isctype_l(c, 2, &v9.localeinfo);
      locinfo = v9.localeinfo.locinfo;
    }
    if ( v4 )
    {
      result = locinfo->pcumap[c];
LABEL_17:
      if ( v9.updated )
        v9.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( v9.updated )
    v9.ptd->_ownlocale &= ~2u;
  return c;
}
