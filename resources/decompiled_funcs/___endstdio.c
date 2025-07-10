void __endstdio()
{
  _flushall();
  if ( _exitflag )
    _fcloseall();
  free(__piob);
}
