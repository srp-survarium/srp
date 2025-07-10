void __stdcall __noreturn threadstartex(DWORD *ptd)
{
  unsigned int flsindex; // eax
  _DWORD *v2; // eax
  unsigned int v3; // eax
  DWORD LastError; // eax

  __set_flsgetvalue();
  flsindex = __get_flsindex();
  v2 = (_DWORD *)__fls_getvalue(flsindex);
  if ( v2 )
  {
    v2[21] = ptd[21];
    v2[22] = ptd[22];
    v2[1] = ptd[1];
    _freefls(ptd);
  }
  else
  {
    v3 = __get_flsindex();
    if ( !__fls_setvalue(v3, ptd) )
    {
      LastError = GetLastError();
      ExitThread(LastError);
    }
    *ptd = GetCurrentThreadId();
  }
  if ( _FPmtinit )
  {
    if ( _IsNonwritableInCurrentImage((unsigned __int8 *)&_FPmtinit) )
      _FPmtinit();
  }
  callthreadstartex();
}
