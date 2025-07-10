int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}
