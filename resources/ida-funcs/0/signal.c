int __usercall signal@<eax>(int a1@<edi>, int signum, _XCPT_ACTION **sigact)
{
  _XCPT_ACTION **v3; // esi
  _tiddata *v4; // eax
  unsigned __int8 *v5; // eax
  _XCPT_ACTION *v6; // eax
  void (__cdecl *XcptAction)(int); // edx
  unsigned int *v8; // esi
  int SetConsoleCtrlError; // [esp+10h] [ebp-20h]
  void (__cdecl *oldsigact)(int); // [esp+14h] [ebp-1Ch]

  SetConsoleCtrlError = 0;
  v3 = sigact;
  if ( sigact == (_XCPT_ACTION **)4 || sigact == (_XCPT_ACTION **)3 )
    goto sigreterror;
  a1 = 2;
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
        v3 = sigact;
      }
    }
    switch ( signum )
    {
      case 2:
        oldsigact = (void (__cdecl *)(int))_decode_pointer(ctrlc_action);
        if ( v3 != (_XCPT_ACTION **)2 )
          ctrlc_action = (void (__cdecl *)(int))_encode_pointer(v3);
        break;
      case 6:
        goto LABEL_31;
      case 15:
        oldsigact = (void (__cdecl *)(int))_decode_pointer(term_action);
        if ( v3 != (_XCPT_ACTION **)2 )
          term_action = (void (__cdecl *)(int))_encode_pointer(v3);
        break;
      case 21:
        oldsigact = (void (__cdecl *)(int))_decode_pointer(ctrlbreak_action);
        if ( v3 != (_XCPT_ACTION **)2 )
          ctrlbreak_action = (void (__cdecl *)(int))_encode_pointer(v3);
        break;
      default:
LABEL_31:
        oldsigact = (void (__cdecl *)(int))_decode_pointer(abort_action);
        if ( v3 != (_XCPT_ACTION **)2 )
          abort_action = (void (__cdecl *)(int))_encode_pointer(v3);
        break;
    }
    _unlock(0);
    if ( !SetConsoleCtrlError )
      return (int)oldsigact;
    goto sigreterror;
  }
  if ( signum != 8 && signum != 4 && signum != 11 )
    goto sigreterror;
  v4 = _getptd_noexit();
  v3 = (_XCPT_ACTION **)v4;
  if ( !v4 )
    goto sigreterror;
  a1 = (int)_XcptActTab;
  if ( v4->_pxcptacttab == _XcptActTab )
  {
    v5 = (unsigned __int8 *)_malloc_crt(_XcptActTabSize);
    v3[23] = (_XCPT_ACTION *)v5;
    if ( !v5 )
      goto sigreterror;
    memcpy(v5, (unsigned __int8 *)_XcptActTab, _XcptActTabSize);
  }
  v6 = siglookup(signum, v3[23]);
  if ( v6 )
  {
    XcptAction = v6->XcptAction;
    if ( sigact != (_XCPT_ACTION **)2 )
    {
      do
      {
        if ( v6->SigNum != signum )
          break;
        v6->XcptAction = (void (__cdecl *)(int))sigact;
        ++v6;
      }
      while ( v6 < &v3[23][_XcptActTabCount] );
    }
    return (int)XcptAction;
  }
sigreterror:
  if ( signum != 1 && signum != 3 && signum != 13 && (signum <= 15 || signum > 17) )
  {
    *_errno() = 22;
    _invalid_parameter(signum, a1, (int)v3);
  }
  return -1;
}
