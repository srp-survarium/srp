int __cdecl ssl_cipher_id_cmp_BSEARCH_CMP_FN(_DWORD *a_, _DWORD *b_)
{
  int result; // eax

  result = a_[2] - b_[2];
  if ( result )
    return 2 * (result > 0) - 1;
  return result;
}
