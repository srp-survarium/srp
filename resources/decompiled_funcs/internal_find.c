int __usercall internal_find@<eax>(stack_st *st@<esi>, char *data, int ret_val_options)
{
  char *v3; // edx
  int result; // eax
  char **i; // ecx
  const void *v6; // eax

  v3 = data;
  if ( !st )
    return -1;
  result = (int)st->comp;
  if ( result )
  {
    if ( !st->sorted )
    {
      qsort((char *)st->data, st->num, 4u, st->comp);
      v3 = data;
      st->sorted = 1;
    }
    if ( v3 )
    {
      v6 = OBJ_bsearch_ex_(&data, st->data, st->num, 4, st->comp, ret_val_options);
      if ( v6 )
        return (signed int)((int)v6 - (unsigned int)st->data) >> 2;
    }
    return -1;
  }
  if ( st->num <= 0 )
    return -1;
  for ( i = st->data; *i != data; ++i )
  {
    if ( ++result >= st->num )
      return -1;
  }
  return result;
}
