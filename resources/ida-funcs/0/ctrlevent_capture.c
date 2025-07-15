int __stdcall ctrlevent_capture(unsigned int CtrlType)
{
  void (__cdecl **v1)(int); // esi
  void (__cdecl *v2)(int); // eax
  int sigcode; // [esp+10h] [ebp-20h]
  void (__cdecl *ctrl_action)(int); // [esp+14h] [ebp-1Ch]

  _lock(0);
  if ( CtrlType )
  {
    v1 = &ctrlbreak_action;
    v2 = (void (__cdecl *)(int))_decode_pointer(ctrlbreak_action);
    ctrl_action = v2;
    sigcode = 21;
  }
  else
  {
    v1 = &ctrlc_action;
    v2 = (void (__cdecl *)(int))_decode_pointer(ctrlc_action);
    ctrl_action = v2;
    sigcode = 2;
  }
  if ( (unsigned int)v2 >= 2 )
    *v1 = (void (__cdecl *)(int))_encoded_null();
  _unlock(0);
  if ( !ctrl_action )
    return 0;
  if ( ctrl_action != (void (__cdecl *)(int))1 )
    ctrl_action(sigcode);
  return 1;
}
