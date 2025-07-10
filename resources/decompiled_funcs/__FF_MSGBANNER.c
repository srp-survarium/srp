void _FF_MSGBANNER()
{
  if ( _set_error_mode(3) == 1 || !_set_error_mode(3) && __app_type == 1 )
  {
    _NMSG_WRITE(252);
    _NMSG_WRITE(255);
  }
}
