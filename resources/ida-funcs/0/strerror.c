char *__cdecl strerror(int errnum)
{
  _tiddata *v1; // eax
  _tiddata *v2; // esi
  char *v4; // eax
  char *errmsg; // esi
  char *sys_err_msg; // eax

  v1 = _getptd_noexit();
  v2 = v1;
  if ( !v1 )
    return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  if ( !v1->_errmsg )
  {
    v4 = (char *)_calloc_crt(0x86u, 1u);
    v2->_errmsg = v4;
    if ( !v4 )
      return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  }
  errmsg = v2->_errmsg;
  sys_err_msg = _get_sys_err_msg(errnum);
  if ( strcpy_s(errmsg, 0x86u, sys_err_msg) )
    _invoke_watson(0, 0x86u, (unsigned int)errmsg);
  return errmsg;
}
