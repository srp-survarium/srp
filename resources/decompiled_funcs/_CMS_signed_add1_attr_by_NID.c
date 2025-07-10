BOOL __cdecl CMS_signed_add1_attr_by_NID(
        CMS_SignerInfo_st *si,
        unsigned int nid,
        int type,
        unsigned __int8 *bytes,
        int len)
{
  return X509at_add1_attr_by_NID(&si->signedAttrs, nid, type, bytes, len) != 0;
}
