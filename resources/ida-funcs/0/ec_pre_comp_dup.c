int *__cdecl ec_pre_comp_dup(int *src_)
{
  CRYPTO_add_lock(src_ + 6, 1, 36, ".\\crypto\\ec\\ec_mult.c", 127);
  return src_;
}
