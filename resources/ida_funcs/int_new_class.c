int __usercall int_new_class@<eax>(unsigned int a1@<edi>)
{
  int v1; // esi

  CRYPTO_lock(a1, 9, 2, ".\\crypto\\ex_data.c", 373);
  v1 = ex_class++;
  CRYPTO_lock(a1, 10, 2, ".\\crypto\\ex_data.c", 375);
  return v1;
}
