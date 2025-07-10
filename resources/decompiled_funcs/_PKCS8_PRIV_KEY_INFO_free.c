void __cdecl PKCS8_PRIV_KEY_INFO_free(pkcs8_priv_key_info_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_66);
}
