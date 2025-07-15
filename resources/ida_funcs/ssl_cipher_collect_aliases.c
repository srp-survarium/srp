void __fastcall ssl_cipher_collect_aliases(
        unsigned int disabled_mac,
        unsigned int disabled_enc,
        const ssl_cipher_st **ca_list,
        int num_of_group_aliases,
        unsigned int disabled_mkey,
        unsigned int disabled_auth,
        unsigned int disabled_ssl,
        cipher_order_st *head)
{
  cipher_order_st *i; // eax
  unsigned int *p_algorithm_auth; // eax
  int v12; // ebx
  unsigned int v13; // ebp
  unsigned int v14; // edx
  unsigned int v15; // esi
  unsigned int v16; // edx
  unsigned int v17; // [esp+10h] [ebp-4h]
  unsigned int v18; // [esp+1Ch] [ebp+8h]
  unsigned int v19; // [esp+20h] [ebp+Ch]
  unsigned int v20; // [esp+24h] [ebp+10h]
  unsigned int v21; // [esp+28h] [ebp+14h]
  int v22; // [esp+2Ch] [ebp+18h]

  v18 = ~disabled_mac;
  v17 = ~disabled_ssl;
  v21 = ~disabled_mkey;
  v20 = ~disabled_auth;
  v19 = ~disabled_enc;
  for ( i = head; i; ++ca_list )
  {
    *ca_list = i->cipher;
    i = i->next;
  }
  if ( num_of_group_aliases > 0 )
  {
    p_algorithm_auth = &cipher_aliases[0].algorithm_auth;
    v22 = num_of_group_aliases;
    do
    {
      v12 = *(p_algorithm_auth - 1);
      v13 = *p_algorithm_auth;
      v14 = p_algorithm_auth[1];
      v15 = p_algorithm_auth[2];
      if ( (!v12 || (v12 & v21) != 0)
        && (!v13 || (v13 & v20) != 0)
        && (!v14 || (v14 & v19) != 0)
        && (!v15 || (v15 & v18) != 0) )
      {
        v16 = p_algorithm_auth[3];
        if ( !v16 || (v16 & v17) != 0 )
          *ca_list++ = (const ssl_cipher_st *)(p_algorithm_auth - 4);
      }
      p_algorithm_auth += 12;
      --v22;
    }
    while ( v22 );
  }
  *ca_list = 0;
}
