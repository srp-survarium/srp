threadlocaleinfostruct *__cdecl __updatetlocinfo()
{
  _tiddata *v0; // esi
  threadlocaleinfostruct *ptlocinfo; // esi
  threadlocaleinfostruct *ptloci; // [esp+10h] [ebp-1Ch]

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo )
  {
    ptlocinfo = _getptd()->ptlocinfo;
  }
  else
  {
    _lock(12);
    ptloci = updatetlocinfoEx_nolock(&v0->ptlocinfo, __ptlocinfo);
    _unlock(12);
    ptlocinfo = ptloci;
  }
  if ( !ptlocinfo )
    _amsg_exit(32);
  return ptlocinfo;
}
