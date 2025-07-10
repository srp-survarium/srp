int __cdecl X509_NAME_get_index_by_NID(X509_name_st *name, unsigned int nid, int lastpos)
{
  asn1_object_st *v3; // eax

  v3 = OBJ_nid2obj(nid);
  if ( v3 )
    return X509_NAME_get_index_by_OBJ(name, v3, lastpos);
  else
    return -2;
}
