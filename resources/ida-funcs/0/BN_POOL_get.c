bignum_pool_item *__usercall BN_POOL_get@<eax>(bignum_pool *p@<esi>)
{
  unsigned int used; // ecx
  bignum_pool_item *result; // eax
  bignum_pool_item *v3; // edi
  bignum_pool_item *v4; // ebx
  int v5; // ebp
  bignum_pool_item *tail; // eax
  bignum_pool_item *next; // edx

  used = p->used;
  if ( used != p->size )
  {
    if ( used )
    {
      if ( (used & 0xF) != 0 )
      {
LABEL_14:
        result = (bignum_pool_item *)((char *)p->current + 20 * (used & 0xF));
        p->used = used + 1;
        return result;
      }
      next = p->current->next;
    }
    else
    {
      next = p->head;
    }
    p->current = next;
    goto LABEL_14;
  }
  result = (bignum_pool_item *)CRYPTO_malloc(328, ".\\crypto\\bn\\bn_ctx.c", 409);
  v3 = result;
  if ( result )
  {
    v4 = result;
    v5 = 16;
    do
    {
      BN_init(v4->vals);
      v4 = (bignum_pool_item *)((char *)v4 + 20);
      --v5;
    }
    while ( v5 );
    tail = p->tail;
    v3->next = 0;
    v3->prev = tail;
    if ( p->head )
    {
      p->tail->next = v3;
      p->size += 16;
      ++p->used;
    }
    else
    {
      p->size += 16;
      ++p->used;
      p->head = v3;
    }
    p->current = v3;
    p->tail = v3;
    return v3;
  }
  return result;
}
