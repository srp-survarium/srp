char *__cdecl sk_delete(stack_st *st, int loc)
{
  int v2; // ecx
  int num; // edx
  char *result; // eax
  int v5; // esi
  char **data; // edx
  char *v7; // ebx
  char **v8; // edx

  if ( !st )
    return 0;
  v2 = loc;
  if ( loc < 0 )
    return 0;
  num = st->num;
  if ( loc >= st->num )
    return 0;
  result = st->data[loc];
  v5 = num - 1;
  if ( loc < num - 1 )
  {
    do
    {
      data = st->data;
      v7 = data[v2 + 1];
      v8 = &data[v2++];
      *v8 = v7;
    }
    while ( v2 < v5 );
  }
  --st->num;
  return result;
}
