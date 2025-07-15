int *__cdecl ec_pre_comp_dup(int *a1)
{
  CRYPTO_add_lock(a1 + 6, 1, 36, ".\\crypto\\ec\\ec_mult.c", 127);
  return a1;
}
