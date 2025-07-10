int __usercall int_err_get_next_lib@<eax>(unsigned int a1@<edi>)
{
  int v1; // esi

  CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 551);
  v1 = int_err_library_number++;
  CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 553);
  return v1;
}
