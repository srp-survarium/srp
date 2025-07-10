lconv *__cdecl localeconv()
{
  _tiddata *v0; // eax

  v0 = _getptd();
  if ( v0->ptlocinfo != __ptlocinfo && (__globallocalestatus & v0->_ownlocale) == 0 )
    __updatetlocinfo();
  return __lconv;
}
