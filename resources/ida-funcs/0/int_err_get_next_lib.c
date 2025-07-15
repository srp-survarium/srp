int __usercall int_err_get_next_lib@<eax>(int a1@<edi>, int a2@<ebx>)
{
  int v2; // esi

  CRYPTO_lock(a1, a2, 9, 1, ".\\crypto\\err\\err.c", 551);
  v2 = int_err_library_number++;
  CRYPTO_lock(a1, a2, 10, 1, ".\\crypto\\err\\err.c", 553);
  return v2;
}
