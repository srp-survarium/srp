int __cdecl _tolower_l(int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate v9; // [esp+8h] [ebp-18h] BYREF
  wchar_t v10; // [esp+18h] [ebp-8h] BYREF
  char v11; // [esp+1Ch] [ebp-4h] BYREF
  char v12; // [esp+1Dh] [ebp-3h]
  char v13; // [esp+1Eh] [ebp-2h]
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
  if ( (unsigned int)c >= 0x100 )
  {
    if ( v9.localeinfo.locinfo->mb_cur_max > 1 && (ca = c >> 8, _isleadbyte_l(BYTE1(c), &v9.localeinfo)) )
    {
      v11 = ca;
      v12 = c;
      v13 = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      v11 = c;
      v12 = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           &v9.localeinfo,
           v9.localeinfo.locinfo->lc_handle[2],
           0x100u,
           &v11,
           v6,
           &v10,
           3,
           v9.localeinfo.locinfo->lc_codepage,
           1);
    if ( v7 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)v10;
      if ( !v8 )
        result = HIBYTE(v10) | ((unsigned __int8)v10 << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = v9.localeinfo.locinfo;
    if ( v9.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = v9.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, 1, &v9.localeinfo);
      locinfo = v9.localeinfo.locinfo;
    }
    if ( v4 )
    {
      result = locinfo->pclmap[c];
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
