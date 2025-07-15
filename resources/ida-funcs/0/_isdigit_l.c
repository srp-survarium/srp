int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate v3; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v3, plocinfo);
  if ( v3.localeinfo.locinfo->mb_cur_max <= 1 )
    result = v3.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, 4, &v3.localeinfo);
  if ( v3.updated )
    v3.ptd->_ownlocale &= ~2u;
  return result;
}
