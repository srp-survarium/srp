ocsp_responder_id_st *__cdecl d2i_OCSP_RESPID(
        ocsp_responder_id_st **a,
        unsigned __int8 **in,
        const unsigned __int8 **len)
{
  return (ocsp_responder_id_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &local_it_90);
}
