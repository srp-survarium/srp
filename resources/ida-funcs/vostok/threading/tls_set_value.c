void __cdecl vostok::threading::tls_set_value(DWORD key, void *value)
{
  TlsSetValue(key, value);
}
