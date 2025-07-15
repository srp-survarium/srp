void __usercall __noreturn OpenSSLDie(
        int a1@<edi>,
        int a2@<esi>,
        int a3@<ebx>,
        const char *file,
        int line,
        const char *assertion)
{
  OPENSSL_showfatal(a1, a2, a3, "%s(%d): OpenSSL internal error, assertion failed: %s\n", file, line, assertion);
  raise(a2, 22);
  _exit(3);
}
