int __cdecl _mtinitlocknum(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi
  _RTL_CRITICAL_SECTION *v3; // edi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 1;
  if ( !_crtheap )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(30);
    __crtExitProcess(255);
  }
  v1 = &locktable + 2 * locknum;
  if ( *v1 )
    return 1;
  v3 = (_RTL_CRITICAL_SECTION *)_malloc_crt(0x18u);
  if ( v3 )
  {
    _lock(10);
    if ( *v1 )
    {
      free(v3);
    }
    else if ( __crtInitCritSecAndSpinCount(v3, 0xFA0u) )
    {
      *v1 = v3;
    }
    else
    {
      free(v3);
      *_errno() = 12;
      retval = 0;
    }
    _unlock(10);
    return retval;
  }
  else
  {
    *_errno() = 12;
    return 0;
  }
}
