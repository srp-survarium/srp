int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax

  if ( _FPinit && _IsNonwritableInCurrentImage((unsigned __int8 *)&_FPinit) )
    _FPinit(initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(__xi_a, __xi_z);
  if ( !result )
  {
    atexit(_RTC_Terminate);
    initterm(__xc_a, __xc_z);
    if ( __dyn_tls_init_callback )
    {
      if ( _IsNonwritableInCurrentImage((unsigned __int8 *)&__dyn_tls_init_callback) )
        __dyn_tls_init_callback(0, 2u, 0);
    }
    return 0;
  }
  return result;
}
