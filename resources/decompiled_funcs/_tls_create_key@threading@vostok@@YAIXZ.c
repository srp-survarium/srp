// attributes: thunk
DWORD __stdcall vostok::threading::tls_create_key()
{
  return TlsAlloc();
}
