void __usercall BN_POOL_release(bignum_pool *p@<esi>, unsigned int num@<edx>)
{
  unsigned int used; // ecx
  int v3; // eax

  used = p->used;
  v3 = ((_BYTE)used - 1) & 0xF;
  p->used = used - num;
  while ( num )
  {
    --num;
    if ( v3 )
    {
      --v3;
    }
    else
    {
      v3 = 15;
      p->current = p->current->prev;
    }
  }
}
