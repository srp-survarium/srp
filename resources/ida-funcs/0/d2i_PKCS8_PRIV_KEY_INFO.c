pkcs8_priv_key_info_st *__cdecl d2i_PKCS8_PRIV_KEY_INFO(
        pkcs8_priv_key_info_st **a,
        unsigned __int8 **in,
        const unsigned __int8 **len)
{
  return (pkcs8_priv_key_info_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &local_it_66);
}
