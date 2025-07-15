int __cdecl sk_push(stack_st *st, char *data)
{
  return sk_insert(st, data, st->num);
}
