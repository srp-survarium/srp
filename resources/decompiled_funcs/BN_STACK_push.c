int __usercall BN_STACK_push@<eax>(bignum_ctx_stack *st@<esi>, unsigned int idx)
{
  unsigned int size; // eax
  unsigned int v3; // ebx
  int result; // eax
  unsigned __int8 *v5; // edi
  unsigned int depth; // eax

  size = st->size;
  if ( st->depth != size )
  {
LABEL_11:
    st->indexes[st->depth] = idx;
    result = 1;
    ++st->depth;
    return result;
  }
  if ( size )
    v3 = (3 * size) >> 1;
  else
    v3 = 32;
  result = (int)CRYPTO_malloc(4 * v3, ".\\crypto\\bn\\bn_ctx.c", 338);
  v5 = (unsigned __int8 *)result;
  if ( result )
  {
    depth = st->depth;
    if ( depth )
      memcpy(v5, (unsigned __int8 *)st->indexes, 4 * depth);
    if ( st->size )
      CRYPTO_free(st->indexes);
    st->indexes = (unsigned int *)v5;
    st->size = v3;
    goto LABEL_11;
  }
  return result;
}
