int __usercall X509at_get_attr_by_NID@<eax>(
        int a1@<ebx>,
        const stack_st_X509_ATTRIBUTE *x,
        asn1_object_st *nid,
        int lastpos)
{
  asn1_object_st *obj; // eax

  obj = OBJ_nid2obj(a1, (unsigned int)nid);
  if ( obj )
    return X509v3_get_ext_by_OBJ(x, obj, lastpos);
  else
    return -2;
}
