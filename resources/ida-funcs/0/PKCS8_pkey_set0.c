int __usercall PKCS8_pkey_set0@<eax>(
        int a1@<ebx>,
        pkcs8_priv_key_info_st *priv,
        asn1_object_st *aobj,
        int version,
        int ptype,
        int pval,
        unsigned __int8 *penc,
        int penclen)
{
  unsigned __int8 **p_data; // edi
  int result; // eax
  asn1_string_st *v10; // eax

  p_data = 0;
  if ( version < 0 || (result = ASN1_INTEGER_set(a1, priv->version, version)) != 0 )
  {
    if ( penc )
    {
      v10 = ASN1_OCTET_STRING_new();
      if ( !v10 )
        return 0;
      v10->data = penc;
      p_data = &v10->data;
      v10->length = penclen;
      ASN1_TYPE_set(priv->pkey, priv->broken != 1 ? 4 : 16, (int)v10);
    }
    if ( !X509_ALGOR_set0(priv->pkeyalg, aobj, ptype, pval) )
    {
      if ( p_data )
        *p_data = 0;
      return 0;
    }
    return 1;
  }
  return result;
}
