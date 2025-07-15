BOOL __usercall CMS_signed_add1_attr_by_NID@<eax>(
        int a1@<ebx>,
        CMS_SignerInfo_st *si,
        unsigned int nid,
        int type,
        __m128i *bytes,
        int len)
{
  return X509at_add1_attr_by_NID(a1, &si->signedAttrs, nid, type, bytes, len) != 0;
}
