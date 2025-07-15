int __usercall internal_find@<eax>(stack_st *st@<esi>, int a2@<edi>, char *data, char ret_val_options)
{
  char *v4; // edx
  int result; // eax
  char **i; // ecx
  char *v7; // eax

  v4 = data;
  if ( !st )
    return -1;
  result = (int)st->comp;
  if ( result )
  {
    if ( !st->sorted )
    {
      qsort(a2, (char *)st->data, st->num, 4u, st->comp);
      v4 = data;
      st->sorted = 1;
    }
    if ( v4 )
    {
      v7 = OBJ_bsearch_ex_(&data, (char *)st->data, st->num, 4, st->comp, ret_val_options);
      if ( v7 )
        return (v7 - (char *)st->data) >> 2;
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
