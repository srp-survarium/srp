const char *RC4_options()
{
  const char *result; // eax

  result = "rc4(4x,int)";
  if ( _bittest((const signed __int32 *)&OPENSSL_ia32cap_P, 0x14u) )
    return "rc4(1x,char)";
  return result;
}
