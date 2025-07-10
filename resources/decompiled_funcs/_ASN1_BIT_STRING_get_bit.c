BOOL __cdecl ASN1_BIT_STRING_get_bit(asn1_string_st *a, int n)
{
  int v2; // eax
  unsigned __int8 *data; // edi

  v2 = n / 8;
  return a && a->length >= v2 + 1 && (data = a->data) != 0 && ((unsigned __int8)(1 << (7 - (n & 7))) & data[v2]) != 0;
}
