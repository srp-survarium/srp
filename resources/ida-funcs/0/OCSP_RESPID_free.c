void __cdecl OCSP_RESPID_free(ocsp_responder_id_st *a)
{
  ASN1_item_free((struct ASN1_VALUE_st *)a, &local_it_90);
}
