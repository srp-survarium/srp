void *__cdecl sk_set(stack_st *st, int i, void *value)
{
  void *result; // eax

  if ( !st || i < 0 || i >= st->num )
    return 0;
  result = value;
  st->data[i] = (char *)value;
  return result;
}
