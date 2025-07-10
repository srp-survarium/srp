// attributes: thunk
DWORD __stdcall XInputGetCapabilities(DWORD dwUserIndex, DWORD dwFlags, XINPUT_CAPABILITIES *pCapabilities)
{
  return __imp__XInputGetCapabilities@12(dwUserIndex, dwFlags, pCapabilities);
}
