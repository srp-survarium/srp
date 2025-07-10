void *__getgmtimebuf()
{
  _tiddata *v0; // eax
  _tiddata *v1; // esi
  void *v3; // eax

  v0 = _getptd_noexit();
  v1 = v0;
  if ( v0 )
  {
    if ( v0->_gmtimebuf )
      return v1->_gmtimebuf;
    v3 = _malloc_crt(0x24u);
    v1->_gmtimebuf = v3;
    if ( v3 )
      return v1->_gmtimebuf;
  }
  *_errno() = 12;
  return 0;
}
