void __cdecl ssl_cipher_collect_ciphers(
        const ssl_method_st *ssl_method,
        int num_of_ciphers,
        unsigned int disabled_mkey,
        unsigned int disabled_auth,
        unsigned int disabled_enc,
        unsigned int disabled_mac,
        unsigned int disabled_ssl,
        cipher_order_st *co_list,
        cipher_order_st **head_p,
        cipher_order_st **tail_p)
{
  signed int v10; // ebx
  int v11; // edi
  cipher_order_st **p_prev; // esi
  const ssl_cipher_st *v13; // eax
  cipher_order_st **v14; // eax
  int v15; // ecx
  cipher_order_st *v16; // eax

  v10 = 0;
  v11 = 0;
  if ( num_of_ciphers > 0 )
  {
    p_prev = &co_list->prev;
    do
    {
      v13 = ssl_method->get_cipher(v10);
      if ( v13
        && v13->valid
        && (disabled_mkey & v13->algorithm_mkey) == 0
        && (disabled_auth & v13->algorithm_auth) == 0
        && (disabled_enc & v13->algorithm_enc) == 0
        && (disabled_mac & v13->algorithm_mac) == 0
        && (disabled_ssl & v13->algorithm_ssl) == 0 )
      {
        *(p_prev - 4) = (cipher_order_st *)v13;
        *(p_prev - 1) = 0;
        *p_prev = 0;
        *(p_prev - 3) = 0;
        ++v11;
        p_prev += 5;
      }
      ++v10;
    }
    while ( v10 < num_of_ciphers );
    if ( v11 > 0 )
    {
      co_list->prev = 0;
      if ( v11 > 1 )
      {
        co_list->next = co_list + 1;
        if ( v11 - 1 > 1 )
        {
          v14 = &co_list[1].prev;
          v15 = v11 - 2;
          do
          {
            *v14 = (cipher_order_st *)(v14 - 9);
            *(v14 - 1) = (cipher_order_st *)(v14 + 1);
            v14 += 5;
            --v15;
          }
          while ( v15 );
        }
        co_list[v11 - 1].prev = &co_list[v11 - 2];
      }
      v16 = &co_list[v11];
      v16[-1].next = 0;
      *head_p = co_list;
      *tail_p = v16 - 1;
    }
  }
}
