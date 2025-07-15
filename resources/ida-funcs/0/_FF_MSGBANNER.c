void __usercall _FF_MSGBANNER(int a1@<ebx>, int a2@<edi>)
{
  if ( _set_error_mode(a1, a2, 3) == 1 || !_set_error_mode(a1, a2, 3) && __app_type == 1 )
  {
    _NMSG_WRITE(252);
    _NMSG_WRITE(255);
  }
}
