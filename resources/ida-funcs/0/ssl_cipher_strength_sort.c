int __cdecl ssl_cipher_strength_sort(cipher_order_st **head_p, cipher_order_st **tail_p)
{
  cipher_order_st *v2; // eax
  int i; // edi
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  cipher_order_st *j; // eax
  int v8; // ebp
  cipher_order_st *v9; // esi
  cipher_order_st *v10; // edx
  cipher_order_st *v11; // eax
  cipher_order_st *v12; // ebx
  cipher_order_st **p_next; // ecx
  cipher_order_st *prev; // edi
  int k; // [esp+10h] [ebp-Ch]
  cipher_order_st *v16; // [esp+14h] [ebp-8h]
  _DWORD *v17; // [esp+18h] [ebp-4h]

  v2 = *head_p;
  for ( i = 0; v2; v2 = v2->next )
  {
    if ( v2->active && v2->cipher->strength_bits > i )
      i = v2->cipher->strength_bits;
  }
  v4 = CRYPTO_malloc(4 * i + 4, ".\\ssl\\ssl_ciph.c", 996);
  v5 = v4;
  v17 = v4;
  if ( v4 )
  {
    memset((int)v4, 0, 4 * i + 4);
    for ( j = *head_p; j; j = j->next )
    {
      if ( j->active )
        ++v5[j->cipher->strength_bits];
    }
    v8 = i;
    for ( k = i; v8 >= 0; k = v8 )
    {
      if ( (int)v5[v8] > 0 )
      {
        v9 = *head_p;
        v10 = *tail_p;
        v11 = *head_p;
        v16 = *tail_p;
        v12 = *head_p;
        if ( *head_p )
        {
          while ( v11 != v16 )
          {
            p_next = &v12->next;
            v11 = v12;
            v12 = v12->next;
            if ( (v8 < 0 || v8 == v11->cipher->strength_bits) && v11->active && v11 != v10 )
            {
              if ( v11 == v9 )
                v9 = v12;
              prev = v11->prev;
              if ( prev )
              {
                prev->next = v12;
                v8 = k;
              }
              if ( *p_next )
              {
                (*p_next)->prev = v11->prev;
                v8 = k;
              }
              v10->next = v11;
              v11->prev = v10;
              *p_next = 0;
              v10 = v11;
            }
          }
        }
        v5 = v17;
        *head_p = v9;
        *tail_p = v10;
      }
      --v8;
    }
    CRYPTO_free(v5);
    return 1;
  }
  else
  {
    ERR_put_error(0, 0x14u, 231, 65, ".\\ssl\\ssl_ciph.c", 999);
    return 0;
  }
}
