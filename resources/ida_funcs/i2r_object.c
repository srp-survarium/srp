BOOL __cdecl i2r_object(const v3_ext_method *method, asn1_object_st *oid, bio_st *bp, int ind)
{
  return (int)BIO_printf(bp, "%*s", ind, (const char *)&buf) > 0 && i2a_ASN1_OBJECT(bp, oid) > 0;
}
