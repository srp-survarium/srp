// attributes: thunk
DWORD __stdcall XInputGetState(DWORD dwUserIndex, XINPUT_STATE *pState)
{
  return __imp__XInputGetState@8(dwUserIndex, pState);
}
