void __usercall OPENSSL_cpuid_setup(int a1@<ebx>, int a2@<edi>)
{
  char *v2; // eax

  if ( !trigger )
  {
    trigger = 1;
    v2 = getenv(a1, a2, "OPENSSL_ia32cap");
    if ( v2 )
      OPENSSL_ia32cap_P = strtoul(a1, v2, 0, 0) | 0x400;
    else
      OPENSSL_ia32cap_P = OPENSSL_ia32_cpuid() | 0x400;
  }
}
