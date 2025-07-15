// attributes: thunk
DWORD __stdcall __crtTlsAlloc(void (__stdcall *lpCallBack)(void *))
{
  return TlsAlloc();
}
