int __cdecl by_dir_hash_cmp(const lookup_dir_hashes_st *const *a, const lookup_dir_hashes_st *const *b)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx

  v2 = **(_DWORD **)a;
  v3 = **(_DWORD **)b;
  if ( v2 <= v3 )
    return -(v2 < v3);
  else
    return 1;
}
