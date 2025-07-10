char *__cdecl sk_pop(stack_st *st)
{
  if ( st && st->num > 0 )
    return sk_delete(st, st->num - 1);
  else
    return 0;
}
