int __cdecl CMS_signed_get_attr_by_NID(const CMS_SignerInfo_st *si, unsigned int nid, int lastpos)
{
  return X509at_get_attr_by_NID(si->signedAttrs, nid, lastpos);
}
