int __cdecl signal(int signum, void (__cdecl *sigact)(int))
{
  void (__cdecl *v2)(int); // esi
  _tiddata *v3; // eax
  _tiddata *v4; // esi
  unsigned __int8 *v5; // eax
  _XCPT_ACTION *v6; // eax
  void (__cdecl *XcptAction)(int); // edx
  unsigned int *v8; // esi
  int SetConsoleCtrlError; // [esp+10h] [ebp-20h]
  void (__cdecl *oldsigact)(int); // [esp+14h] [ebp-1Ch]

  SetConsoleCtrlError = 0;
  v2 = sigact;
  if ( sigact == (void (__cdecl *)(int))4 || sigact == (void (__cdecl *)(int))3 )
    goto sigreterror;
  if ( signum == 2 || signum == 21 || signum == 22 || signum == 6 || signum == 15 )
  {
    _lock(0);
    if ( (signum == 2 || signum == 21) && !ConsoleCtrlHandler_Installed )
    {
      if ( SetConsoleCtrlHandler(ctrlevent_capture, 1) )
      {
        ConsoleCtrlHandler_Installed = 1;
      }
      else
      {
        v8 = __doserrno();
        *v8 = GetLastError();
        SetConsoleCtrlError = 1;
        v2 = sigact;
      }
    }
    switch ( signum )
    {
      case 2:
        oldsigact = (void (__cdecl *)(int))_decode_pointer(ctrlc_action);
        if ( v2 != (void (__cdecl *)(int))2 )
          ctrlc_action = (void (__cdecl *)(int))_encode_pointer(v2);
        break;
      case 6:
        goto LABEL_31;
      case 15:
        oldsigact = (void (__cdecl *)(int))_decode_pointer(term_action);
        if ( v2 != (void (__cdecl *)(int))2 )
          term_action = (void (__cdecl *)(int))_encode_pointer(v2);
        break;
      case 21:
        oldsigact = (void (__cdecl *)(int))_decode_pointer(ctrlbreak_action);
        if ( v2 != (void (__cdecl *)(int))2 )
          ctrlbreak_action = (void (__cdecl *)(int))_encode_pointer(v2);
        break;
      default:
LABEL_31:
        oldsigact = (void (__cdecl *)(int))_decode_pointer(abort_action);
        if ( v2 != (void (__cdecl *)(int))2 )
          abort_action = (void (__cdecl *)(int))_encode_pointer(v2);
        break;
    }
    _unlock(0);
    if ( !SetConsoleCtrlError )
      return (int)oldsigact;
    goto sigreterror;
  }
  if ( signum != 8 && signum != 4 && signum != 11 )
    goto sigreterror;
  v3 = _getptd_noexit();
  v4 = v3;
  if ( !v3 )
    goto sigreterror;
  if ( v3->_pxcptacttab == _XcptActTab )
  {
    v5 = (unsigned __int8 *)_malloc_crt(_XcptActTabSize);
    v4->_pxcptacttab = v5;
    if ( !v5 )
      goto sigreterror;
    memcpy(v5, (unsigned __int8 *)_XcptActTab, _XcptActTabSize);
  }
  v6 = siglookup(signum, (_XCPT_ACTION *)v4->_pxcptacttab);
  if ( v6 )
  {
    XcptAction = v6->XcptAction;
    if ( sigact != (void (__cdecl *)(int))2 )
    {
      do
      {
        if ( v6->SigNum != signum )
          break;
        v6->XcptAction = sigact;
        ++v6;
      }
      while ( (char *)v6 < (char *)v4->_pxcptacttab + 12 * _XcptActTabCount );
    }
    return (int)XcptAction;
  }
sigreterror:
  if ( signum != 1 && signum != 3 && signum != 13 && (signum <= 15 || signum > 17) )
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
  }
  return -1;
}
