void __stdcall _freefls(void *data)
{
  threadmbcinfostruct *v1; // edi
  threadlocaleinfostruct *v2; // edi
  int savedregs; // [esp+28h] [ebp+0h]

  if ( data )
  {
    if ( *((_DWORD *)data + 9) )
      free(*((void **)data + 9));
    if ( *((_DWORD *)data + 11) )
      free(*((void **)data + 11));
    if ( *((_DWORD *)data + 13) )
      free(*((void **)data + 13));
    if ( *((_DWORD *)data + 15) )
      free(*((void **)data + 15));
    if ( *((_DWORD *)data + 16) )
      free(*((void **)data + 16));
    if ( *((_DWORD *)data + 17) )
      free(*((void **)data + 17));
    if ( *((_DWORD *)data + 18) )
      free(*((void **)data + 18));
    if ( *((const _XCPT_ACTION **)data + 23) != _XcptActTab )
      free(*((void **)data + 23));
    _lock(13);
    v1 = (threadmbcinfostruct *)*((_DWORD *)data + 26);
    if ( v1 && !InterlockedDecrement(*((volatile LONG **)data + 26)) && v1 != &__initialmbcinfo )
      free(v1);
    _unlock(13);
    _lock(12);
    v2 = (threadlocaleinfostruct *)*((_DWORD *)data + 27);
    if ( v2 )
    {
      __removelocaleref(*((threadlocaleinfostruct **)data + 27));
      if ( v2 != __ptlocinfo && v2 != &__initiallocinfo && !v2->refcount )
        __freetlocinfo(v2);
    }
    savedregs = 1656856;
    _unlock(12);
    free(data);
  }
}
