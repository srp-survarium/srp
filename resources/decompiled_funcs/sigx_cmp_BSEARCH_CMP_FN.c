int __cdecl sigx_cmp_BSEARCH_CMP_FN(const void *a_, const void *b_)
{
  int result; // eax

  result = *(_DWORD *)(*(_DWORD *)a_ + 4) - *(_DWORD *)(*(_DWORD *)b_ + 4);
  if ( !result )
    return *(_DWORD *)(*(_DWORD *)a_ + 8) - *(_DWORD *)(*(_DWORD *)b_ + 8);
  return result;
}
