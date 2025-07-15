char *__cdecl sk_delete_ptr(stack_st *st, char *p)
{
  int num; // esi
  int v3; // eax
  char **i; // ecx
  char *v6; // edi
  int j; // esi
  char **data; // ecx
  char *v9; // ebx
  char **v10; // ecx

  num = st->num;
  v3 = 0;
  if ( st->num <= 0 )
    return 0;
  for ( i = st->data; *i != p; ++i )
  {
    if ( ++v3 >= num )
      return 0;
  }
  if ( v3 < 0 || v3 >= num )
    return 0;
  v6 = st->data[v3];
  for ( j = num - 1; v3 < j; *v10 = v9 )
  {
    data = st->data;
    v9 = data[v3 + 1];
    v10 = &data[v3++];
  }
  --st->num;
  return v6;
}
