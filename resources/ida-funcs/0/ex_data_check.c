BOOL __usercall ex_data_check@<eax>(int a1@<edi>, int a2@<ebx>)
{
  BOOL v2; // esi

  v2 = 1;
  CRYPTO_lock(a1, a2, 9, 2, ".\\crypto\\ex_data.c", 270);
  if ( !ex_data )
  {
    ex_data = (lhash_st_EX_CLASS_ITEM *)lh_new(
                                          (int (__cdecl *)(const char *))EVP_CIPHER_CTX_cipher,
                                          (void (__cdecl *)(unsigned __int8 *, unsigned __int8 *))nid_cmp_BSEARCH_CMP_FN);
    v2 = ex_data != 0;
  }
  CRYPTO_lock(a1, a2, 10, 2, ".\\crypto\\ex_data.c", 274);
  return v2;
}
