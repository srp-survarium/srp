unsigned int __usercall trust_compat@<eax>(unsigned int a1@<edi>, x509_trust_st *trust, x509_st *x)
{
  X509_check_purpose(a1, x, -1, 0);
  return (~LOBYTE(x->ex_flags) & 0x20 | 0x10u) >> 4;
}
