DWORD vostok::vfs::_dynamic_initializer_for__s_ready_referers_tls_key__()
{
  DWORD result; // eax

  result = TlsAlloc();
  s_ready_referers_tls_key = result;
  return result;
}
