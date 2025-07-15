void __cdecl __noreturn _endthreadex(DWORD retcode)
{
  _tiddata *v1; // eax

  if ( _FPmtterm[0] && _IsNonwritableInCurrentImage((unsigned __int8 *)_FPmtterm) )
    _FPmtterm[0]();
  v1 = _getptd_noexit();
  if ( v1 )
    _freeptd(v1);
  ExitThread(retcode);
}
