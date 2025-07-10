unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}
