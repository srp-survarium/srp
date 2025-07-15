int __cdecl pbe2_cmp_BSEARCH_CMP_FN(_DWORD *a_, _DWORD *b_)
{
  int result; // eax

  result = *a_ - *b_;
  if ( *a_ == *b_ )
    return a_[1] - b_[1];
  return result;
}
