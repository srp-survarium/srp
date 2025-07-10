void __usercall BN_POOL_finish(bignum_pool *p@<edi>)
{
  bignum_pool_item *head; // esi
  int v2; // ebx
  bignum_pool_item *current; // edx
  bignum_pool_item *v4; // [esp-Ch] [ebp-Ch]

  if ( p->head )
  {
    do
    {
      head = p->head;
      v2 = 16;
      do
      {
        if ( head->vals[0].d )
          BN_clear_free(head->vals);
        head = (bignum_pool_item *)((char *)head + 20);
        --v2;
      }
      while ( v2 );
      v4 = p->head;
      p->current = p->head->next;
      CRYPTO_free(v4);
      current = p->current;
      p->head = current;
    }
    while ( current );
  }
}
