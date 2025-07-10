unsigned int __cdecl X509_subject_name_cmp(const x509_st *a, const x509_st *b)
{
  return X509_NAME_cmp(a->cert_info->subject, b->cert_info->subject);
}
