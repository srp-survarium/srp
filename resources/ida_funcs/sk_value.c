char *__cdecl sk_value(const stack_st *st, int i)
{
  if ( st && i >= 0 && i < st->num )
    return st->data[i];
  else
    return 0;
}
