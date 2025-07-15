int __cdecl _setmbcp(int codepage)
{
  _tiddata *v1; // edi
  threadmbcinfostruct *ptmbcinfo; // ebx
  threadmbcinfostruct *v3; // eax
  threadmbcinfostruct *v4; // ebx
  int v5; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  int retcode; // [esp+14h] [ebp-20h]
  UINT codepagea; // [esp+3Ch] [ebp+8h]

  retcode = -1;
  v1 = _getptd();
  __updatetmbcinfo();
  ptmbcinfo = v1->ptmbcinfo;
  codepagea = getSystemCP(codepage);
  if ( codepagea == ptmbcinfo->mbcodepage )
    return 0;
  v3 = (threadmbcinfostruct *)_malloc_crt(0x220u);
  v4 = v3;
  if ( v3 )
  {
    qmemcpy(v3, v1->ptmbcinfo, sizeof(threadmbcinfostruct));
    v3->refcount = 0;
    v5 = _setmbcp_nolock(codepagea, v3);
    retcode = v5;
    if ( v5 )
    {
      if ( v5 == -1 )
      {
        if ( v4 != &__initialmbcinfo )
          free(v4);
        *_errno() = 22;
      }
    }
    else
    {
      if ( !InterlockedDecrement(&v1->ptmbcinfo->refcount) && v1->ptmbcinfo != &__initialmbcinfo )
        free(v1->ptmbcinfo);
      v1->ptmbcinfo = v4;
      InterlockedIncrement(&v4->refcount);
      if ( (v1->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
      {
        _lock(13);
        __mbcodepage = v4->mbcodepage;
        __ismbcodepage = v4->ismbcodepage;
        __mblcid = v4->mblcid;
        for ( i = 0; i < 5; ++i )
          __mbulinfo[i] = v4->mbulinfo[i];
        for ( j = 0; j < 257; ++j )
          _mbctype[j] = v4->mbctype[j];
        for ( k = 0; k < 256; ++k )
          _mbcasemap[k] = v4->mbcasemap[k];
        if ( !InterlockedDecrement(&__ptmbcinfo->refcount) && __ptmbcinfo != &__initialmbcinfo )
          free(__ptmbcinfo);
        __ptmbcinfo = v4;
        InterlockedIncrement(&v4->refcount);
        _unlock(13);
      }
    }
  }
  return retcode;
}
