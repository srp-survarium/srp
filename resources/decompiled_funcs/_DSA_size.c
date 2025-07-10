int __cdecl DSA_size(const dsa_st *r)
{
  int v1; // eax
  asn1_string_st a; // [esp+0h] [ebp-10h] BYREF

  a.length = (BN_num_bits(r->q) + 7) / 8;
  a.data = (unsigned __int8 *)&r;
  a.type = 2;
  LOBYTE(r) = -1;
  v1 = i2d_ASN1_INTEGER(&a, 0);
  return ASN1_object_size(1, 2 * v1, 16);
}
