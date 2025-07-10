int __cdecl sk_is_sorted(const stack_st *st)
{
  if ( st )
    return st->sorted;
  else
    return 1;
}
