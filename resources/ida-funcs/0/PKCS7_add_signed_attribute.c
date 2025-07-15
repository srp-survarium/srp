int __cdecl PKCS7_add_signed_attribute(pkcs7_signer_info_st *p7si, void *nid, int atrtype, int value)
{
  return add_attribute(&p7si->auth_attr, nid, atrtype, value);
}
