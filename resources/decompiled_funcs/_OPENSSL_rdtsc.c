unsigned __int64 OPENSSL_rdtsc()
{
  unsigned __int64 result; // rax

  result = 0;
  if ( _bittest((const signed __int32 *)&OPENSSL_ia32cap_P, 4u) )
    return __rdtsc();
  return result;
}
