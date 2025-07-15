BOOL __usercall ex_data_check@<eax>(unsigned int a1@<edi>)
{
  BOOL v1; // esi

  v1 = 1;
  CRYPTO_lock(a1, 9, 2, ".\\crypto\\ex_data.c", 270);
  if ( !ex_data )
  {
    ex_data = (lhash_st_EX_CLASS_ITEM *)lh_new(
                                          (unsigned int (__cdecl *)(const void *))EVP_CIPHER_CTX_cipher,
                                          nid_cmp_BSEARCH_CMP_FN);
    v1 = ex_data != 0;
  }
  CRYPTO_lock(a1, 10, 2, ".\\crypto\\ex_data.c", 274);
  return v1;
}
