unsigned int __cdecl conf_value_LHASH_HASH(const char **arg)
{
  unsigned int v1; // edi

  v1 = lh_strhash(arg[1]);
  return v1 ^ (4 * lh_strhash(*arg));
}
