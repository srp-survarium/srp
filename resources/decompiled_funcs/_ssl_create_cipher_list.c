stack_st_SSL_CIPHER *__cdecl ssl_create_cipher_list(
        const ssl_method_st *ssl_method,
        stack_st_SSL_CIPHER **cipher_list,
        stack_st_SSL_CIPHER **cipher_list_by_id,
        char *rule_str)
{
  int v4; // edi
  cipher_order_st *v5; // eax
  cipher_order_st *v7; // eax
  cipher_order_st *v8; // ecx
  cipher_order_st *v9; // ebx
  cipher_order_st *v10; // edi
  bool v11; // zf
  cipher_order_st **p_next; // edx
  cipher_order_st *prev; // esi
  cipher_order_st *v14; // eax
  cipher_order_st *v15; // esi
  cipher_order_st *v16; // edi
  cipher_order_st *v17; // ebp
  cipher_order_st *v18; // ecx
  cipher_order_st *v19; // edi
  cipher_order_st **v20; // edx
  cipher_order_st *v21; // esi
  cipher_order_st *v22; // ebx
  cipher_order_st *v23; // eax
  cipher_order_st *v24; // edi
  cipher_order_st **v25; // edx
  cipher_order_st *v26; // esi
  cipher_order_st *v27; // ebp
  cipher_order_st *v28; // ecx
  cipher_order_st *v29; // edi
  cipher_order_st **v30; // edx
  cipher_order_st *v31; // esi
  cipher_order_st *v32; // eax
  cipher_order_st *v33; // ebx
  cipher_order_st *v34; // edi
  cipher_order_st **v35; // edx
  cipher_order_st *v36; // esi
  cipher_order_st *v37; // ebp
  cipher_order_st *v38; // edx
  cipher_order_st *v39; // edi
  cipher_order_st **v40; // ecx
  cipher_order_st *v41; // esi
  cipher_order_st *v42; // ebx
  cipher_order_st *v43; // eax
  cipher_order_st *v44; // edi
  cipher_order_st **v45; // ecx
  cipher_order_st *v46; // esi
  cipher_order_st *v47; // ebp
  cipher_order_st *v48; // ecx
  cipher_order_st *v49; // eax
  cipher_order_st *v50; // edi
  cipher_order_st **v51; // edx
  cipher_order_st *v52; // esi
  cipher_order_st *v53; // ebx
  cipher_order_st *v54; // eax
  cipher_order_st *v55; // edi
  cipher_order_st **v56; // edx
  cipher_order_st *v57; // esi
  cipher_order_st *v58; // edx
  cipher_order_st *v59; // esi
  cipher_order_st *v60; // edi
  cipher_order_st **v61; // ecx
  cipher_order_st *v62; // edx
  cipher_order_st *v63; // esi
  cipher_order_st *v64; // edi
  cipher_order_st *v65; // ebx
  const ssl_cipher_st **v66; // esi
  const char *v67; // edi
  int v68; // ebx
  int v69; // eax
  stack_st_SSL_CIPHER *v70; // edi
  cipher_order_st *i; // esi
  stack_st_SSL_CIPHER *v72; // esi
  cipher_order_st *tail_p; // [esp+0h] [ebp-24h] BYREF
  cipher_order_st *head_p; // [esp+4h] [ebp-20h] BYREF
  void *str; // [esp+8h] [ebp-1Ch]
  unsigned int ssl; // [esp+Ch] [ebp-18h] BYREF
  unsigned int auth; // [esp+10h] [ebp-14h] BYREF
  unsigned int mkey; // [esp+14h] [ebp-10h] BYREF
  unsigned int mac; // [esp+18h] [ebp-Ch] BYREF
  unsigned int enc; // [esp+1Ch] [ebp-8h] BYREF
  int v81; // [esp+20h] [ebp-4h]

  head_p = 0;
  tail_p = 0;
  if ( !rule_str || !cipher_list || !cipher_list_by_id )
    return 0;
  ssl_cipher_get_disabled(&auth, &enc, &mac, &mkey, &ssl);
  v4 = ssl_method->num_ciphers();
  v81 = v4;
  v5 = (cipher_order_st *)CRYPTO_malloc(20 * v4, ".\\ssl\\ssl_ciph.c", 1309);
  str = v5;
  if ( !v5 )
  {
    ERR_put_error(0x14u, 166, 65, ".\\ssl\\ssl_ciph.c", 1312);
    return 0;
  }
  ssl_cipher_collect_ciphers(ssl_method, v4, mkey, auth, enc, mac, ssl, v5, &head_p, &tail_p);
  v7 = head_p;
  v8 = tail_p;
  v9 = head_p;
  v10 = head_p;
  if ( head_p )
  {
    while ( v7 != tail_p )
    {
      v7 = v10;
      v11 = SLOBYTE(v10->cipher->algorithm_mkey) >= 0;
      p_next = &v10->next;
      v10 = v10->next;
      if ( !v11 && !v7->active )
      {
        if ( v7 != v8 )
        {
          if ( v7 == v9 )
            v9 = v10;
          prev = v7->prev;
          if ( prev )
            prev->next = v10;
          if ( *p_next )
            (*p_next)->prev = v7->prev;
          v8->next = v7;
          v7->prev = v8;
          *p_next = 0;
          v8 = v7;
        }
        v7->active = 1;
      }
    }
  }
  v14 = v9;
  tail_p = v9;
  head_p = v8;
  v15 = v8;
  v16 = v8;
  if ( v8 )
  {
    while ( v15 != v9 )
    {
      v15 = v16;
      v11 = SLOBYTE(v16->cipher->algorithm_mkey) >= 0;
      v16 = v16->prev;
      if ( !v11 && v15->active )
      {
        ll_append_head(&head_p, &tail_p, v15);
        v15->active = 0;
      }
    }
    v14 = tail_p;
  }
  v17 = head_p;
  v18 = v14;
  tail_p = head_p;
  v19 = v14;
  if ( v14 )
  {
    while ( v14 != head_p )
    {
      v14 = v19;
      v11 = (v19->cipher->algorithm_enc & 0xC0) == 0;
      v20 = &v19->next;
      v19 = v19->next;
      if ( !v11 && !v14->active )
      {
        if ( v14 != v17 )
        {
          if ( v14 == v18 )
            v18 = v19;
          v21 = v14->prev;
          if ( v21 )
            v21->next = v19;
          if ( *v20 )
            (*v20)->prev = v14->prev;
          v17->next = v14;
          v14->prev = v17;
          *v20 = 0;
          v17 = v14;
        }
        v14->active = 1;
      }
    }
    tail_p = v17;
  }
  v22 = v17;
  v23 = v18;
  head_p = v17;
  v24 = v18;
  if ( v18 )
  {
    while ( v18 != v17 )
    {
      v18 = v24;
      v11 = v24->active == 0;
      v25 = &v24->next;
      v24 = v24->next;
      if ( v11 )
      {
        if ( v18 != v22 )
        {
          if ( v18 == v23 )
            v23 = v24;
          v26 = v18->prev;
          if ( v26 )
          {
            v26->next = v24;
            v17 = tail_p;
          }
          if ( *v25 )
          {
            (*v25)->prev = v18->prev;
            v17 = tail_p;
          }
          v22->next = v18;
          v18->prev = v22;
          *v25 = 0;
          v22 = v18;
        }
        v18->active = 1;
      }
    }
    head_p = v22;
  }
  v27 = v22;
  v28 = v23;
  tail_p = v22;
  v29 = v23;
  if ( v23 )
  {
    while ( v23 != v22 )
    {
      v23 = v29;
      v11 = (v29->cipher->algorithm_mac & 1) == 0;
      v30 = &v29->next;
      v29 = v29->next;
      if ( !v11 && v23->active && v23 != v27 )
      {
        if ( v23 == v28 )
          v28 = v29;
        v31 = v23->prev;
        if ( v31 )
        {
          v31->next = v29;
          v22 = head_p;
        }
        if ( *v30 )
        {
          (*v30)->prev = v23->prev;
          v22 = head_p;
        }
        v27->next = v23;
        v23->prev = v27;
        *v30 = 0;
        v27 = v23;
      }
    }
    tail_p = v27;
  }
  v32 = v28;
  v33 = v27;
  v34 = v28;
  if ( v28 )
  {
    while ( v28 != v27 )
    {
      v28 = v34;
      v11 = (v34->cipher->algorithm_auth & 4) == 0;
      v35 = &v34->next;
      v34 = v34->next;
      if ( !v11 && v28->active && v28 != v33 )
      {
        if ( v28 == v32 )
          v32 = v34;
        v36 = v28->prev;
        if ( v36 )
        {
          v36->next = v34;
          v27 = tail_p;
        }
        if ( *v35 )
        {
          (*v35)->prev = v28->prev;
          v27 = tail_p;
        }
        v33->next = v28;
        v28->prev = v33;
        *v35 = 0;
        v33 = v28;
      }
    }
  }
  v37 = v33;
  v38 = v32;
  head_p = v33;
  v39 = v32;
  if ( v32 )
  {
    while ( v32 != v33 )
    {
      v32 = v39;
      v11 = (v39->cipher->algorithm_auth & 0x10) == 0;
      v40 = &v39->next;
      v39 = v39->next;
      if ( !v11 && v32->active && v32 != v37 )
      {
        if ( v32 == v38 )
          v38 = v39;
        v41 = v32->prev;
        if ( v41 )
        {
          v41->next = v39;
          v37 = head_p;
        }
        if ( *v40 )
        {
          (*v40)->prev = v32->prev;
          v37 = head_p;
        }
        v37->next = v32;
        v32->prev = v37;
        v37 = v32;
        *v40 = 0;
        head_p = v32;
      }
    }
  }
  v42 = v37;
  head_p = v37;
  v43 = v38;
  v44 = v38;
  if ( v38 )
  {
    while ( v43 != v37 )
    {
      v43 = v44;
      v11 = (v44->cipher->algorithm_mkey & 1) == 0;
      v45 = &v44->next;
      v44 = v44->next;
      if ( !v11 && v43->active && v43 != v42 )
      {
        if ( v43 == v38 )
          v38 = v44;
        v46 = v43->prev;
        if ( v46 )
        {
          v46->next = v44;
          v42 = head_p;
        }
        if ( *v45 )
        {
          (*v45)->prev = v43->prev;
          v42 = head_p;
        }
        v42->next = v43;
        v43->prev = v42;
        v42 = v43;
        *v45 = 0;
        head_p = v43;
      }
    }
  }
  v47 = v42;
  v48 = v38;
  head_p = v42;
  v49 = v38;
  v50 = v38;
  if ( v38 )
  {
    while ( v49 != v42 )
    {
      v49 = v50;
      v11 = (v50->cipher->algorithm_mkey & 0x100) == 0;
      v51 = &v50->next;
      v50 = v50->next;
      if ( !v11 && v49->active && v49 != v47 )
      {
        if ( v49 == v48 )
          v48 = v50;
        v52 = v49->prev;
        if ( v52 )
        {
          v52->next = v50;
          v47 = head_p;
        }
        if ( *v51 )
        {
          (*v51)->prev = v49->prev;
          v47 = head_p;
        }
        v47->next = v49;
        v49->prev = v47;
        v47 = v49;
        *v51 = 0;
        head_p = v49;
      }
    }
  }
  v53 = v47;
  v54 = v48;
  head_p = v47;
  v55 = v48;
  if ( v48 )
  {
    while ( v48 != v47 )
    {
      v48 = v55;
      v11 = (v55->cipher->algorithm_mkey & 0x10) == 0;
      v56 = &v55->next;
      v55 = v55->next;
      if ( !v11 && v48->active && v48 != v53 )
      {
        if ( v48 == v54 )
          v54 = v55;
        v57 = v48->prev;
        if ( v57 )
        {
          v57->next = v55;
          v53 = head_p;
        }
        if ( *v56 )
        {
          (*v56)->prev = v48->prev;
          v53 = head_p;
        }
        v53->next = v48;
        v48->prev = v53;
        v53 = v48;
        *v56 = 0;
        head_p = v48;
      }
    }
  }
  v58 = v54;
  head_p = v54;
  v59 = v53;
  v60 = v54;
  if ( v54 )
  {
    while ( v54 != v53 )
    {
      v54 = v60;
      v11 = (v60->cipher->algorithm_enc & 4) == 0;
      v61 = &v60->next;
      v60 = v60->next;
      if ( !v11 && v54->active && v54 != v59 )
      {
        if ( v54 == v58 )
          head_p = v60;
        v62 = v54->prev;
        if ( v62 )
          v62->next = v60;
        if ( *v61 )
          (*v61)->prev = v54->prev;
        v58 = head_p;
        v59->next = v54;
        v54->prev = v59;
        *v61 = 0;
        v59 = v54;
      }
    }
  }
  head_p = v58;
  tail_p = v59;
  if ( !ssl_cipher_strength_sort(&head_p, &tail_p) )
    goto LABEL_154;
  v63 = tail_p;
  v64 = head_p;
  v65 = tail_p;
  if ( tail_p )
  {
    while ( v63 != v64 )
    {
      v63 = v65;
      v65 = v65->prev;
      if ( v63->active )
      {
        ll_append_head(&tail_p, &head_p, v63);
        v63->active = 0;
      }
    }
    v64 = head_p;
  }
  head_p = v64;
  v66 = (const ssl_cipher_st **)CRYPTO_malloc(4 * v81 + 272, ".\\ssl\\ssl_ciph.c", 1373);
  if ( !v66 )
  {
    CRYPTO_free(str);
    ERR_put_error(0x14u, 166, 65, ".\\ssl\\ssl_ciph.c", 1377);
    return 0;
  }
  ssl_cipher_collect_aliases(mac, enc, v66, 67, mkey, auth, ssl, v64);
  v67 = rule_str;
  v68 = 1;
  if ( strncmp(rule_str, "DEFAULT", 7u) )
    goto LABEL_169;
  v69 = ssl_cipher_process_rulestr("ALL:!aNULL:!eNULL:!SSLv2", &head_p, &tail_p, v66);
  v67 = rule_str + 7;
  v68 = v69;
  if ( rule_str[7] == 58 )
    v67 = rule_str + 8;
  if ( v69 )
  {
LABEL_169:
    if ( strlen(v67) )
      v68 = ssl_cipher_process_rulestr(v67, &head_p, &tail_p, v66);
  }
  CRYPTO_free(v66);
  if ( v68 && (v70 = (stack_st_SSL_CIPHER *)sk_new_null()) != 0 )
  {
    for ( i = head_p; i; i = i->next )
    {
      if ( i->active )
        sk_push(&v70->stack, (char *)i->cipher);
    }
    CRYPTO_free(str);
    v72 = (stack_st_SSL_CIPHER *)sk_dup(&v70->stack);
    if ( v72 )
    {
      if ( *cipher_list )
        sk_free(&(*cipher_list)->stack);
      *cipher_list = v70;
      if ( *cipher_list_by_id )
        sk_free(&(*cipher_list_by_id)->stack);
      *cipher_list_by_id = v72;
      sk_set_cmp_func(&v72->stack, (int (__cdecl *)(const void *, const void *))ssl_cipher_ptr_id_cmp);
      sk_sort(&(*cipher_list_by_id)->stack);
      return v70;
    }
    else
    {
      sk_free(&v70->stack);
      return 0;
    }
  }
  else
  {
LABEL_154:
    CRYPTO_free(str);
    return 0;
  }
}
