int __usercall int_new_class@<eax>(int a1@<edi>, int a2@<ebx>)
{
  int v2; // esi

  CRYPTO_lock(a1, a2, 9, 2, ".\\crypto\\ex_data.c", 373);
  v2 = ex_class++;
  CRYPTO_lock(a1, a2, 10, 2, ".\\crypto\\ex_data.c", 375);
  return v2;
}
