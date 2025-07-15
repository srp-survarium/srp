void __stdcall __noreturn threadstartex(DWORD *lpFlsData)
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
    v2[21] = lpFlsData[21];
    v2[22] = lpFlsData[22];
    v2[1] = lpFlsData[1];
    _freefls(lpFlsData);
  }
  else
  {
    v3 = __get_flsindex();
    if ( !__fls_setvalue(v3, lpFlsData) )
    {
      LastError = GetLastError();
      ExitThread(LastError);
    }
    *lpFlsData = GetCurrentThreadId();
  }
  if ( _FPmtinit )
  {
    if ( _IsNonwritableInCurrentImage((unsigned __int8 *)&_FPmtinit) )
      _FPmtinit();
  }
  callthreadstartex();
}
