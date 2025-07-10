HANDLE __usercall _beginthreadex@<eax>(
        unsigned int a1@<esi>,
        _SECURITY_ATTRIBUTES *security,
        SIZE_T stacksize,
        unsigned int (__stdcall *initialcode)(void *),
        void *argument,
        DWORD createflag,
        unsigned int *thrdaddr)
{
  unsigned int (__stdcall *v7)(void *); // edi
  HANDLE result; // eax
  _tiddata *v9; // esi
  _tiddata *v10; // eax
  void *v11; // eax
  unsigned int *p_initialcode; // eax
  DWORD err; // [esp+8h] [ebp-4h]

  v7 = initialcode;
  err = 0;
  if ( !initialcode )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, a1);
    return 0;
  }
  __set_flsgetvalue();
  v9 = (_tiddata *)_calloc_crt(1u, 0x214u);
  if ( !v9 )
    goto error_return_2;
  v10 = _getptd();
  _initptd(v9, v10->ptlocinfo);
  v11 = argument;
  v9->_thandle = -1;
  v9->_initarg = v11;
  p_initialcode = thrdaddr;
  v9->_initaddr = v7;
  if ( !p_initialcode )
    p_initialcode = (unsigned int *)&initialcode;
  result = CreateThread(security, stacksize, (LPTHREAD_START_ROUTINE)threadstartex, v9, createflag, p_initialcode);
  if ( !result )
  {
    err = GetLastError();
error_return_2:
    free(v9);
    if ( err )
      _dosmaperr(err);
    return 0;
  }
  return result;
}
