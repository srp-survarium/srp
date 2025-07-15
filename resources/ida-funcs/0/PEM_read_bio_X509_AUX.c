x509_st *__usercall PEM_read_bio_X509_AUX@<eax>(
        int a1@<ebx>,
        bio_st *bp,
        x509_st **x,
        int (__cdecl *cb)(char *, int, int, void *),
        void *u)
{
  return (x509_st *)PEM_ASN1_read_bio(
                      a1,
                      (void *(__cdecl *)(void **, const unsigned __int8 **, int))d2i_X509_AUX,
                      "TRUSTED CERTIFICATE",
                      bp,
                      (void **)x,
                      cb,
                      u);
}
