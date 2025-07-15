int __cdecl ssl_cipher_ptr_id_cmp(const ssl_cipher_st *const *ap, const ssl_cipher_st *const *bp)
{
  int result; // eax

  result = (*ap)->id - (*bp)->id;
  if ( result )
    return 2 * (result > 0) - 1;
  return result;
}
