int __cdecl RSA_size(const rsa_st *r)
{
  return (BN_num_bits(r->n) + 7) / 8;
}
