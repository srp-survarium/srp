void __cdecl sk_zero(stack_st *st)
{
  if ( st )
  {
    if ( st->num > 0 )
    {
      memset((int)st->data, 0, 4 * st->num);
      st->num = 0;
    }
  }
}
