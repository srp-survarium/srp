int __usercall RSA_verify@<eax>(
        int a1@<ebx>,
        void *dtype,
        const unsigned __int8 *m,
        unsigned int m_len,
        const unsigned __int8 *sigbuf,
        int siglen,
        rsa_st *rsa)
{
  int (*rsa_verify)(void); // ecx

  if ( (rsa->flags & 0x40) != 0 && (rsa_verify = (int (*)(void))rsa->meth->rsa_verify) != 0 )
    return rsa_verify();
  else
    return int_rsa_verify(a1, dtype, m, m_len, 0, 0, sigbuf, siglen, rsa);
}
