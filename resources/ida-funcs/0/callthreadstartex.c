void __noreturn callthreadstartex()
{
  _tiddata *v0; // eax
  DWORD v1; // eax
  int v2; // [esp+0h] [ebp-2Ch]

  v0 = _getptd();
  v1 = ((int (__stdcall *)(void *, int))v0->_initaddr)(v0->_initarg, v2);
  _endthreadex(v1);
}
