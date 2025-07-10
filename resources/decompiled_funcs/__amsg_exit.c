void __cdecl _amsg_exit(int rterrnum)
{
  void (__cdecl *v1)(int); // eax

  _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  v1 = (void (__cdecl *)(int))_decode_pointer(_aexit_rtn);
  v1(255);
}
