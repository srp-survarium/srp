unsigned int __cdecl ___lc_codepage_func()
{
  _tiddata *v0; // ecx
  threadlocaleinfostruct *ptlocinfo; // eax

  v0 = _getptd();
  ptlocinfo = v0->ptlocinfo;
  if ( ptlocinfo != __ptlocinfo && (__globallocalestatus & v0->_ownlocale) == 0 )
    ptlocinfo = __updatetlocinfo();
  return ptlocinfo->lc_codepage;
}
