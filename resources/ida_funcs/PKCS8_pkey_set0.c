int __cdecl PKCS8_pkey_set0(
        pkcs8_priv_key_info_st *priv,
        asn1_object_st *aobj,
        int version,
        int ptype,
        void *pval,
        unsigned __int8 *penc,
        int penclen)
{
  unsigned __int8 **p_data; // edi
  int result; // eax
  asn1_string_st *v9; // eax

  p_data = 0;
  if ( version < 0 || (result = ASN1_INTEGER_set(priv->version, version)) != 0 )
  {
    if ( penc )
    {
      v9 = ASN1_OCTET_STRING_new();
      if ( !v9 )
        return 0;
      v9->data = penc;
      p_data = &v9->data;
      v9->length = penclen;
      ASN1_TYPE_set(priv->pkey, priv->broken != 1 ? 4 : 16, v9);
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
