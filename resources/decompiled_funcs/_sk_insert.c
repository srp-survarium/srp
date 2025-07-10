int __cdecl sk_insert(stack_st *st, char *data, int loc)
{
  int result; // eax
  int num_alloc; // eax
  char **v5; // eax
  int v6; // ecx
  int num; // eax
  char **v8; // ecx
  int v9; // eax

  if ( !st )
    return 0;
  num_alloc = st->num_alloc;
  if ( num_alloc <= st->num + 1 )
  {
    v5 = (char **)CRYPTO_realloc(st->data, 8 * num_alloc, ".\\crypto\\stack\\stack.c", 150);
    if ( !v5 )
      return 0;
    v6 = st->num_alloc;
    st->data = v5;
    st->num_alloc = 2 * v6;
  }
  num = st->num;
  if ( loc >= st->num || loc < 0 )
  {
    st->data[num] = data;
    result = ++st->num;
    st->sorted = 0;
  }
  else
  {
    if ( num >= loc )
    {
      v8 = &st->data[num + 1];
      v9 = num - loc + 1;
      do
      {
        *v8 = *(v8 - 1);
        --v8;
        --v9;
      }
      while ( v9 );
    }
    st->data[loc] = data;
    result = ++st->num;
    st->sorted = 0;
  }
  return result;
}
