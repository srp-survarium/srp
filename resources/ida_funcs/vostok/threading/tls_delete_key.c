void __usercall vostok::threading::tls_delete_key(DWORD key@<eax>)
{
  TlsFree(key);
}
