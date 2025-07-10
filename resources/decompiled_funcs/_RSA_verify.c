int __cdecl RSA_verify(
        unsigned int dtype,
        const unsigned __int8 *m,
        unsigned int m_len,
        unsigned __int8 *sigbuf,
        unsigned int siglen,
        rsa_st *rsa)
{
  int (*rsa_verify)(void); // ecx

  if ( (rsa->flags & 0x40) != 0 && (rsa_verify = (int (*)(void))rsa->meth->rsa_verify) != 0 )
    return rsa_verify();
  else
    return int_rsa_verify(dtype, m, m_len, 0, 0, sigbuf, siglen, rsa);
}
