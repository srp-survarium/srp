int __cdecl ssl_cipher_process_rulestr(
        const char *rule_str,
        cipher_order_st **head_p,
        cipher_order_st **tail_p,
        const ssl_cipher_st **ca_list)
{
  const char *v4; // ebx
  char v5; // al
  int v6; // edi
  unsigned int i; // ecx
  char v8; // al
  int v9; // ebp
  const ssl_cipher_st **v10; // esi
  const ssl_cipher_st *v11; // edi
  unsigned int algorithm_mkey; // eax
  char v13; // al
  unsigned int algorithm_auth; // eax
  unsigned int algorithm_enc; // eax
  unsigned int algorithm_mac; // eax
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int algorithm_ssl; // edi
  char v21; // al
  int v22; // [esp+4h] [ebp-28h]
  unsigned int algo_strength; // [esp+8h] [ebp-24h]
  unsigned int alg_mac; // [esp+Ch] [ebp-20h]
  unsigned int alg_enc; // [esp+10h] [ebp-1Ch]
  unsigned int alg_auth; // [esp+14h] [ebp-18h]
  unsigned int alg_mkey; // [esp+18h] [ebp-14h]
  unsigned int cipher_id; // [esp+1Ch] [ebp-10h]
  unsigned int count; // [esp+20h] [ebp-Ch]
  int v30; // [esp+24h] [ebp-8h]
  char *first; // [esp+28h] [ebp-4h]
  unsigned int alg_ssl; // [esp+30h] [ebp+4h]

  v4 = rule_str;
  v5 = *rule_str;
  v22 = 1;
  if ( *rule_str )
  {
    while ( v5 != 45 )
    {
      switch ( v5 )
      {
        case '+':
          algo_strength = 4;
          ++v4;
          goto LABEL_14;
        case '!':
          algo_strength = 2;
          ++v4;
          goto LABEL_14;
        case '@':
          algo_strength = 5;
          ++v4;
          goto LABEL_14;
      }
      algo_strength = 1;
      if ( v5 != 58 && v5 != 32 && v5 != 59 && v5 != 44 )
        goto LABEL_14;
      ++v4;
LABEL_99:
      v5 = *v4;
      if ( !*v4 )
        return v22;
    }
    algo_strength = 3;
    ++v4;
LABEL_14:
    v6 = 0;
    cipher_id = 0;
    alg_mkey = 0;
    alg_auth = 0;
    alg_enc = 0;
    alg_mac = 0;
    alg_ssl = 0;
    while ( 1 )
    {
      first = (char *)v4;
      for ( i = 0; ; ++i )
      {
        v8 = *v4;
        if ( (*v4 < 65 || v8 > 90) && (v8 < 48 || v8 > 57) && (v8 < 97 || v8 > 122) && v8 != 45 )
          break;
        ++v4;
      }
      count = i;
      if ( !i )
        break;
      if ( algo_strength == 5 )
        goto LABEL_40;
      if ( v8 == 43 )
      {
        v30 = 1;
        ++v4;
      }
      else
      {
        v30 = 0;
      }
      v9 = 0;
      if ( !*ca_list )
        goto LABEL_39;
      v10 = ca_list;
      while ( strncmp(first, (*v10)->name, count) || (*v10)->name[count] )
      {
        v10 = &ca_list[++v6];
        if ( !*v10 )
          goto LABEL_39;
      }
      v11 = ca_list[v6];
      algorithm_mkey = v11->algorithm_mkey;
      v9 = 1;
      if ( algorithm_mkey )
      {
        if ( cipher_id )
        {
          cipher_id &= algorithm_mkey;
          if ( !cipher_id )
            goto LABEL_38;
        }
        else
        {
          cipher_id = v11->algorithm_mkey;
        }
      }
      algorithm_auth = v11->algorithm_auth;
      if ( algorithm_auth )
      {
        if ( alg_mkey )
        {
          alg_mkey &= algorithm_auth;
          if ( !alg_mkey )
            goto LABEL_38;
        }
        else
        {
          alg_mkey = v11->algorithm_auth;
        }
      }
      algorithm_enc = v11->algorithm_enc;
      if ( algorithm_enc )
      {
        if ( alg_auth )
        {
          alg_auth &= algorithm_enc;
          if ( !alg_auth )
            goto LABEL_38;
        }
        else
        {
          alg_auth = v11->algorithm_enc;
        }
      }
      algorithm_mac = v11->algorithm_mac;
      if ( algorithm_mac )
      {
        if ( alg_enc )
        {
          alg_enc &= algorithm_mac;
          if ( !alg_enc )
            goto LABEL_38;
        }
        else
        {
          alg_enc = v11->algorithm_mac;
        }
      }
      v18 = v11->algo_strength;
      LOWORD(v19) = alg_ssl;
      if ( (v18 & 3) != 0 )
      {
        if ( (alg_ssl & 3) != 0 )
        {
          v19 = (v18 | 0xFFFFFFFC) & alg_ssl;
          alg_ssl = v19;
          if ( (v19 & 3) == 0 )
            goto LABEL_38;
        }
        else
        {
          v19 = v11->algo_strength & 3 | alg_ssl;
          alg_ssl = v19;
        }
      }
      if ( (v18 & 0x1FC) != 0 )
      {
        if ( (v19 & 0x1FC) != 0 )
        {
          alg_ssl &= v18 | 0xFFFFFE03;
          if ( (alg_ssl & 0x1FC) == 0 )
            goto LABEL_38;
        }
        else
        {
          alg_ssl |= v18 & 0x1FC;
        }
      }
      if ( !v11->valid )
      {
        algorithm_ssl = v11->algorithm_ssl;
        if ( algorithm_ssl )
        {
          if ( alg_mac )
          {
            alg_mac &= algorithm_ssl;
            if ( !alg_mac )
            {
LABEL_38:
              v9 = 0;
              goto LABEL_39;
            }
          }
          else
          {
            alg_mac = algorithm_ssl;
          }
        }
      }
      if ( !v30 )
        goto LABEL_39;
      v6 = 0;
    }
    ERR_put_error(0x14u, 230, 280, ".\\ssl\\ssl_ciph.c", 1094);
    v9 = 0;
    v22 = 0;
    ++v4;
LABEL_39:
    if ( algo_strength != 5 )
    {
      if ( v9 )
      {
        ssl_cipher_apply_rule(
          cipher_id,
          alg_mkey,
          alg_auth,
          alg_enc,
          alg_mac,
          alg_ssl,
          algo_strength,
          -1,
          head_p,
          tail_p);
      }
      else
      {
        v21 = *v4;
        if ( !*v4 )
          return v22;
        while ( v21 != 58 && v21 != 32 && v21 != 59 && v21 != 44 )
        {
          v21 = *++v4;
          if ( !v21 )
            return v22;
        }
      }
      goto LABEL_89;
    }
LABEL_40:
    if ( count == 8 && !strncmp(first, "STRENGTH", 8u) )
    {
      if ( ssl_cipher_strength_sort(head_p, tail_p) )
      {
LABEL_44:
        v13 = *v4;
        if ( !*v4 )
          return v22;
        while ( v13 != 58 && v13 != 32 && v13 != 59 && v13 != 44 )
        {
          v13 = *++v4;
          if ( !v13 )
            return v22;
        }
LABEL_89:
        if ( !*v4 )
          return v22;
        goto LABEL_99;
      }
    }
    else
    {
      ERR_put_error(0x14u, 230, 280, ".\\ssl\\ssl_ciph.c", 1247);
    }
    v22 = 0;
    goto LABEL_44;
  }
  return 1;
}
