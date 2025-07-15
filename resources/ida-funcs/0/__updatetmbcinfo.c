threadmbcinfostruct *__cdecl __updatetmbcinfo()
{
  _tiddata *v0; // edi
  threadmbcinfostruct *ptmbcinfo; // esi

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo )
  {
    ptmbcinfo = v0->ptmbcinfo;
  }
  else
  {
    _lock(13);
    ptmbcinfo = v0->ptmbcinfo;
    if ( ptmbcinfo != __ptmbcinfo )
    {
      if ( ptmbcinfo && !InterlockedDecrement(&ptmbcinfo->refcount) && ptmbcinfo != &__initialmbcinfo )
        free(ptmbcinfo);
      v0->ptmbcinfo = __ptmbcinfo;
      ptmbcinfo = __ptmbcinfo;
      InterlockedIncrement(&__ptmbcinfo->refcount);
    }
    _unlock(13);
  }
  if ( !ptmbcinfo )
    _amsg_exit(32);
  return ptmbcinfo;
}
