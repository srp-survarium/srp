void __cdecl ssl_cipher_apply_rule(
        unsigned int cipher_id,
        unsigned int alg_mkey,
        unsigned int alg_auth,
        unsigned int alg_enc,
        unsigned int alg_mac,
        unsigned int alg_ssl,
        unsigned int algo_strength,
        int rule,
        cipher_order_st **strength_bits,
        cipher_order_st **head_p)
{
  cipher_order_st *next; // ecx
  cipher_order_st *v11; // edi
  cipher_order_st *v12; // esi
  cipher_order_st *v13; // ebx
  const ssl_cipher_st *cipher; // eax
  cipher_order_st *prev; // eax
  cipher_order_st *v16; // eax
  cipher_order_st *v17; // eax
  cipher_order_st *v18; // eax
  cipher_order_st *v19; // eax
  cipher_order_st *v20; // eax
  cipher_order_st *v21; // [esp+10h] [ebp-14h] BYREF
  cipher_order_st *v22; // [esp+14h] [ebp-10h] BYREF
  BOOL v23; // [esp+18h] [ebp-Ch]
  cipher_order_st *v24; // [esp+1Ch] [ebp-8h]
  cipher_order_st *v25; // [esp+20h] [ebp-4h]

  v23 = algo_strength == 3;
  next = *strength_bits;
  v11 = *head_p;
  v21 = *strength_bits;
  v22 = v11;
  if ( algo_strength == 3 )
  {
    v12 = v11;
    v25 = next;
  }
  else
  {
    v12 = next;
    v25 = v11;
  }
  v13 = v12;
  if ( v12 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        if ( v12 == v25 )
        {
          *strength_bits = next;
          *head_p = v11;
          return;
        }
        v12 = v13;
        v13 = v23 ? v13->prev : v13->next;
        cipher = v12->cipher;
        v24 = v13;
        if ( rule >= 0 )
          break;
        if ( (!cipher_id || (cipher_id & cipher->algorithm_mkey) != 0)
          && (!alg_mkey || (alg_mkey & cipher->algorithm_auth) != 0)
          && (!alg_auth || (alg_auth & cipher->algorithm_enc) != 0)
          && (!alg_enc || (alg_enc & cipher->algorithm_mac) != 0)
          && (!alg_mac || (alg_mac & cipher->algorithm_ssl) != 0) )
        {
          if ( (alg_ssl & 3) == 0
            || (v13 = v24, ((unsigned __int8)alg_ssl & (unsigned __int8)cipher->algo_strength & 3) != 0) )
          {
            if ( (alg_ssl & 0x1FC) == 0 || (alg_ssl & cipher->algo_strength & 0x1FC) != 0 )
              goto LABEL_26;
          }
        }
      }
      if ( rule == cipher->strength_bits )
      {
LABEL_26:
        switch ( algo_strength )
        {
          case 1u:
            if ( !v12->active )
            {
              if ( v12 != v11 )
              {
                if ( v12 == next )
                {
                  next = v12->next;
                  v21 = next;
                }
                prev = v12->prev;
                if ( prev )
                  prev->next = v12->next;
                v16 = v12->next;
                if ( v16 )
                  v16->prev = v12->prev;
                v11->next = v12;
                v12->prev = v11;
                v11 = v12;
                v12->next = 0;
                v22 = v12;
              }
              v12->active = 1;
            }
            break;
          case 4u:
            if ( v12->active && v12 != v11 )
            {
              if ( v12 == next )
              {
                next = v12->next;
                v21 = next;
              }
              v17 = v12->prev;
              if ( v17 )
                v17->next = v12->next;
              v18 = v12->next;
              if ( v18 )
                v18->prev = v12->prev;
              v11->next = v12;
              v12->prev = v11;
              v11 = v12;
              v12->next = 0;
              v22 = v12;
            }
            break;
          case 3u:
            if ( v12->active )
            {
              ll_append_head(&v22, &v21, v12);
              next = v21;
              v11 = v22;
              v12->active = 0;
            }
            break;
          case 2u:
            if ( next == v12 )
            {
              next = v12->next;
              v21 = next;
            }
            else
            {
              v12->prev->next = v12->next;
            }
            if ( v11 == v12 )
            {
              v11 = v12->prev;
              v22 = v11;
            }
            v19 = v12->next;
            v12->active = 0;
            if ( v19 )
              v19->prev = v12->prev;
            v20 = v12->prev;
            if ( v20 )
              v20->next = v12->next;
            v12->next = 0;
            v12->prev = 0;
            break;
        }
      }
    }
  }
  *strength_bits = next;
  *head_p = v11;
}
