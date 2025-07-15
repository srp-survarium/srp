int __cdecl CMS_signed_get_attr_count(const CMS_SignerInfo_st *si)
{
  return X509at_get_attr_count(si->signedAttrs);
}
