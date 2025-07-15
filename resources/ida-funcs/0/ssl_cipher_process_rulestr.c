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
  unsigned int algo_strength; // eax
  unsigned int v19; // edx
  unsigned int algorithm_ssl; // edi
  char v21; // al
  int v22; // [esp+4h] [ebp-28h]
  unsigned int v23; // [esp+8h] [ebp-24h]
  unsigned int v24; // [esp+Ch] [ebp-20h]
  unsigned int v25; // [esp+10h] [ebp-1Ch]
  unsigned int v26; // [esp+14h] [ebp-18h]
  unsigned int v27; // [esp+18h] [ebp-14h]
  unsigned int v28; // [esp+1Ch] [ebp-10h]
  unsigned int count; // [esp+20h] [ebp-Ch]
  int v30; // [esp+24h] [ebp-8h]
  char *first; // [esp+28h] [ebp-4h]
  unsigned int v32; // [esp+30h] [ebp+4h]

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
          v23 = 4;
          ++v4;
          goto LABEL_14;
        case '!':
          v23 = 2;
          ++v4;
          goto LABEL_14;
        case '@':
          v23 = 5;
          ++v4;
          goto LABEL_14;
      }
      v23 = 1;
      if ( v5 != 58 && v5 != 32 && v5 != 59 && v5 != 44 )
        goto LABEL_14;
      ++v4;
LABEL_99:
      v5 = *v4;
      if ( !*v4 )
        return v22;
    }
    v23 = 3;
    ++v4;
LABEL_14:
    v6 = 0;
    v28 = 0;
    v27 = 0;
    v26 = 0;
    v25 = 0;
    v24 = 0;
    v32 = 0;
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
      if ( v23 == 5 )
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
        if ( v28 )
        {
          v28 &= algorithm_mkey;
          if ( !v28 )
            goto LABEL_38;
        }
        else
        {
          v28 = v11->algorithm_mkey;
        }
      }
      algorithm_auth = v11->algorithm_auth;
      if ( algorithm_auth )
      {
        if ( v27 )
        {
          v27 &= algorithm_auth;
          if ( !v27 )
            goto LABEL_38;
        }
        else
        {
          v27 = v11->algorithm_auth;
        }
      }
      algorithm_enc = v11->algorithm_enc;
      if ( algorithm_enc )
      {
        if ( v26 )
        {
          v26 &= algorithm_enc;
          if ( !v26 )
            goto LABEL_38;
        }
        else
        {
          v26 = v11->algorithm_enc;
        }
      }
      algorithm_mac = v11->algorithm_mac;
      if ( algorithm_mac )
      {
        if ( v25 )
        {
          v25 &= algorithm_mac;
          if ( !v25 )
            goto LABEL_38;
        }
        else
        {
          v25 = v11->algorithm_mac;
        }
      }
      algo_strength = v11->algo_strength;
      LOWORD(v19) = v32;
      if ( (algo_strength & 3) != 0 )
      {
        if ( (v32 & 3) != 0 )
        {
          v19 = (algo_strength | 0xFFFFFFFC) & v32;
          v32 = v19;
          if ( (v19 & 3) == 0 )
            goto LABEL_38;
        }
        else
        {
          v19 = v11->algo_strength & 3 | v32;
          v32 = v19;
        }
      }
      if ( (algo_strength & 0x1FC) != 0 )
      {
        if ( (v19 & 0x1FC) != 0 )
        {
          v32 &= algo_strength | 0xFFFFFE03;
          if ( (v32 & 0x1FC) == 0 )
            goto LABEL_38;
        }
        else
        {
          v32 |= algo_strength & 0x1FC;
        }
      }
      if ( !v11->valid )
      {
        algorithm_ssl = v11->algorithm_ssl;
        if ( algorithm_ssl )
        {
          if ( v24 )
          {
            v24 &= algorithm_ssl;
            if ( !v24 )
            {
LABEL_38:
              v9 = 0;
              goto LABEL_39;
            }
          }
          else
          {
            v24 = algorithm_ssl;
          }
        }
      }
      if ( !v30 )
        goto LABEL_39;
      v6 = 0;
    }
    ERR_put_error((int)v4, 0x14u, 230, 280, ".\\ssl\\ssl_ciph.c", 1094);
    v9 = 0;
    v22 = 0;
    ++v4;
LABEL_39:
    if ( v23 != 5 )
    {
      if ( v9 )
      {
        ssl_cipher_apply_rule(v28, v27, v26, v25, v24, v32, v23, -1, head_p, tail_p);
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
      ERR_put_error((int)v4, 0x14u, 230, 280, ".\\ssl\\ssl_ciph.c", 1247);
    }
    v22 = 0;
    goto LABEL_44;
  }
  return 1;
}
