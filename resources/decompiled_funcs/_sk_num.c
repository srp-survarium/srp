int __cdecl sk_num(const stack_st *st)
{
  if ( st )
    return st->num;
  else
    return -1;
}
