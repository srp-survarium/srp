void __usercall sk_sort(int a1@<edi>, stack_st *st)
{
  if ( st )
  {
    if ( !st->sorted )
    {
      qsort(a1, (char *)st->data, st->num, 4u, st->comp);
      st->sorted = 1;
    }
  }
}
