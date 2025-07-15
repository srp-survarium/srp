int __cdecl X509at_get_attr_by_NID(const stack_st_X509_ATTRIBUTE *x, unsigned int nid, int lastpos)
{
  asn1_object_st *v3; // eax

  v3 = OBJ_nid2obj(nid);
  if ( v3 )
    return X509v3_get_ext_by_OBJ(x, v3, lastpos);
  else
    return -2;
}
