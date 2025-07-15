unsigned int __usercall trust_1oidany@<eax>(unsigned int a1@<edi>, x509_trust_st *trust, x509_st *x)
{
  x509_cert_aux_st *aux; // eax

  aux = x->aux;
  if ( aux && (aux->trust || aux->reject) )
    return obj_trust(trust->arg1, x);
  X509_check_purpose(a1, x, -1, 0);
  return (~LOBYTE(x->ex_flags) & 0x20 | 0x10u) >> 4;
}
