int __cdecl x509_name_ex_i2d(struct ASN1_VALUE_st **val, unsigned __int8 **out)
{
  X509_name_st *v2; // esi
  int result; // eax
  buf_mem_st *bytes; // esi
  unsigned int length; // ebx

  v2 = (X509_name_st *)*val;
  if ( !*((_DWORD *)*val + 1)
    || (result = x509_name_encode(v2), result >= 0) && (result = x509_name_canon(v2), result >= 0) )
  {
    bytes = v2->bytes;
    length = bytes->length;
    if ( out )
    {
      memcpy(*out, (unsigned __int8 *)bytes->data, length);
      *out += length;
    }
    return length;
  }
  return result;
}
