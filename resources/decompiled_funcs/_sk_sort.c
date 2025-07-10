void __cdecl sk_sort(stack_st *st)
{
  if ( st )
  {
    if ( !st->sorted )
    {
      qsort((char *)st->data, st->num, 4u, st->comp);
      st->sorted = 1;
    }
  }
}
