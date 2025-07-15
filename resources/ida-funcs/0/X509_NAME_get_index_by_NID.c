int __usercall X509_NAME_get_index_by_NID@<eax>(int a1@<ebx>, X509_name_st *name, unsigned int nid, int lastpos)
{
  asn1_object_st *v4; // eax

  v4 = OBJ_nid2obj(a1, nid);
  if ( v4 )
    return X509_NAME_get_index_by_OBJ(name, v4, lastpos);
  else
    return -2;
}
