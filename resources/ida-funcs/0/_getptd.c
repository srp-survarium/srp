_tiddata *__cdecl _getptd()
{
  _tiddata *v0; // esi

  v0 = _getptd_noexit();
  if ( !v0 )
    _amsg_exit(16);
  return v0;
}
