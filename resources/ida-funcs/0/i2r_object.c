BOOL __usercall i2r_object@<eax>(int a1@<ebx>, const v3_ext_method *method, asn1_object_st *oid, bio_st *bp, int ind)
{
  return BIO_printf(bp, "%*s", ind, uri) > 0 && i2a_ASN1_OBJECT(a1, bp, oid) > 0;
}
