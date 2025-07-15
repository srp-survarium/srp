int __cdecl DH_size(const dh_st *dh)
{
  return (BN_num_bits(dh->p) + 7) / 8;
}
