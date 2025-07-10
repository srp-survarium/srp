BOOL __usercall check_crl_chain@<eax>(stack_st_X509 *cert_path@<ecx>, stack_st_X509 *crl_path@<esi>)
{
  int v3; // eax
  const x509_st *v4; // edi
  int v5; // eax
  const x509_st *v6; // eax

  v3 = sk_num(&cert_path->stack);
  v4 = (const x509_st *)sk_value(&cert_path->stack, v3 - 1);
  v5 = sk_num(&crl_path->stack);
  v6 = (const x509_st *)sk_value(&crl_path->stack, v5 - 1);
  return X509_cmp(v4, v6) == 0;
}
