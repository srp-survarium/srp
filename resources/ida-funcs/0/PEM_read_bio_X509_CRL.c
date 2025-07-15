X509_crl_st *__usercall PEM_read_bio_X509_CRL@<eax>(
        int a1@<ebx>,
        bio_st *bp,
        X509_crl_st **x,
        int (__cdecl *cb)(char *, int, int, void *),
        void *u)
{
  return (X509_crl_st *)PEM_ASN1_read_bio(
                          a1,
                          (void *(__cdecl *)(void **, const unsigned __int8 **, int))d2i_X509_CRL,
                          "X509 CRL",
                          bp,
                          (void **)x,
                          cb,
                          u);
}
