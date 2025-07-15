void __usercall __noreturn OpenSSLDie(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const char *file,
        int line,
        const char *assertion)
{
  OPENSSL_showfatal(a1, a2, "%s(%d): OpenSSL internal error, assertion failed: %s\n", file, line, assertion);
  raise(22);
  _exit(3);
}
