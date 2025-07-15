char *__cdecl OPENSSL_wipe_cpu(char a1)
{
  if ( _bittest((const signed __int32 *)OPENSSL_ia32cap_P, 1u) )
  {
    *(_DWORD *)OPENSSL_ia32cap_P = *(_DWORD *)OPENSSL_ia32cap_P;
    __asm
    {
      fldz
      fldz
      fldz
      fldz
      fldz
      fldz
      fldz
      fldz
      finit
    }
  }
  return &a1;
}
