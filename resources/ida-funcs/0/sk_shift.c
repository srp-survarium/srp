char *__cdecl sk_shift(stack_st *st)
{
  int num; // eax
  int v2; // esi
  char *v3; // edi
  int i; // eax
  char **data; // ecx
  char *v6; // ebx
  char **v7; // ecx

  if ( !st )
    return 0;
  num = st->num;
  if ( st->num <= 0 )
    return 0;
  v2 = num - 1;
  v3 = *st->data;
  if ( num != 1 )
  {
    for ( i = 0; i < v2; *v7 = v6 )
    {
      data = st->data;
      v6 = data[i + 1];
      v7 = &data[i++];
    }
  }
  --st->num;
  return v3;
}
