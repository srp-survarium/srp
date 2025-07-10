int __cdecl sk_comp_cmp(const ssl_comp_st *const *a, const ssl_comp_st *const *b)
{
  return **(_DWORD **)a - **(_DWORD **)b;
}
