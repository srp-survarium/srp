LPVOID __usercall vostok::threading::tls_get_value@<eax>(DWORD key@<eax>)
{
  return TlsGetValue(key);
}
