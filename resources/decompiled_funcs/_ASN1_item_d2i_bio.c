struct ASN1_VALUE_st *__cdecl ASN1_item_d2i_bio(const ASN1_ITEM_st *it, bio_st *in, struct ASN1_VALUE_st **x)
{
  struct ASN1_VALUE_st *v3; // esi
  unsigned __int8 *v4; // eax
  buf_mem_st *v5; // edi
  buf_mem_st *pb; // [esp+8h] [ebp-8h] BYREF
  unsigned __int8 *data; // [esp+Ch] [ebp-4h] BYREF

  pb = 0;
  v3 = 0;
  v4 = (unsigned __int8 *)asn1_d2i_read_bio(in, &pb);
  v5 = pb;
  if ( (int)v4 >= 0 )
  {
    data = (unsigned __int8 *)pb->data;
    v3 = ASN1_item_d2i(x, &data, v4, it);
  }
  if ( v5 )
    BUF_MEM_free(v5);
  return v3;
}
