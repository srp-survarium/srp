void __cdecl __noreturn fast_error_exit(int rterrnum)
{
  if ( __error_mode == 1 )
    _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  __crtExitProcess(255);
}
