void __usercall vostok::threading::tls_set_value(DWORD key@<ecx>, void *value@<eax>)
{
  TlsSetValue(key, value);
}
