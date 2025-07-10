int __cdecl def_load_bio(conf_st *conf, bio_st *in, int *line)
{
  lhash_st_CONF_VALUE *data; // edx
  int v4; // ebx
  buf_mem_st *v5; // esi
  char *v6; // eax
  char *v7; // ebp
  char *v8; // esi
  int v9; // eax
  int v10; // edx
  int v11; // ebp
  char v12; // cl
  char *v13; // eax
  int v14; // edx
  _BYTE *v15; // ecx
  int v16; // eax
  char *v17; // esi
  char *v18; // eax
  _BYTE *meth_data; // ebp
  char *v20; // esi
  unsigned __int8 v21; // al
  char *j; // edx
  char *v23; // eax
  int v24; // ecx
  int v25; // ecx
  char *v26; // esi
  char *v27; // eax
  char *v28; // ebp
  char *v29; // eax
  unsigned __int8 *v30; // esi
  char *v31; // ebx
  _BYTE *v32; // eax
  int v33; // edx
  char *k; // esi
  CONF_VALUE *v35; // esi
  char *v36; // eax
  char **p_value; // esi
  char *v38; // esi
  CONF_VALUE *v39; // eax
  lhash_st_CONF_VALUE *v41; // eax
  CONF_VALUE *v42; // esi
  bio_st *v43; // [esp-Ch] [ebp-60h]
  buf_mem_st *str; // [esp+10h] [ebp-44h]
  char *pto; // [esp+14h] [ebp-40h] BYREF
  char *section; // [esp+18h] [ebp-3Ch]
  CONF_VALUE *value; // [esp+1Ch] [ebp-38h]
  char *from; // [esp+20h] [ebp-34h]
  int v49; // [esp+24h] [ebp-30h]
  int i; // [esp+28h] [ebp-2Ch]
  char *src; // [esp+2Ch] [ebp-28h]
  int v52; // [esp+30h] [ebp-24h]
  int *v53; // [esp+34h] [ebp-20h]
  lhash_st_CONF_VALUE *v54; // [esp+38h] [ebp-1Ch]
  bio_st *b; // [esp+3Ch] [ebp-18h]
  char buf[16]; // [esp+40h] [ebp-14h] BYREF

  data = conf->data;
  v4 = 0;
  b = in;
  v53 = line;
  v49 = 0;
  value = 0;
  v54 = data;
  v5 = BUF_MEM_new();
  str = v5;
  if ( !v5 )
  {
    ERR_put_error(0xEu, 121, 7, ".\\crypto\\conf\\conf_def.c", 227);
LABEL_73:
    if ( v53 )
      *v53 = v49;
    BIO_snprintf(buf, 0xDu, "%ld", v49);
    ERR_add_error_data(2, "line ", buf);
    v41 = conf->data;
    if ( v54 != v41 && v41 )
    {
      CONF_free(conf->data);
      conf->data = 0;
    }
    v42 = value;
    if ( value )
    {
      if ( value->name )
        CRYPTO_free(value->name);
      if ( v42->value )
        CRYPTO_free(v42->value);
      CRYPTO_free(v42);
    }
    return 0;
  }
  v6 = (char *)CRYPTO_malloc(10, ".\\crypto\\conf\\conf_def.c", 231);
  v7 = v6;
  pto = v6;
  if ( !v6 )
  {
    ERR_put_error(0xEu, 121, 65, ".\\crypto\\conf\\conf_def.c", 234);
    goto err_27;
  }
  BUF_strlcpy(v6, &result.m_buffer[40], 0xAu);
  if ( !_CONF_new_data(conf) )
  {
    ERR_put_error(0xEu, 121, 65, ".\\crypto\\conf\\conf_def.c", 241);
    goto err_27;
  }
  from = (char *)_CONF_new_section(conf, v7);
  if ( !from )
  {
    ERR_put_error(0xEu, 121, 103, ".\\crypto\\conf\\conf_def.c", 249);
    goto err_27;
  }
  i = 0;
  if ( !BUF_MEM_grow(v5, 0x200u) )
  {
LABEL_63:
    ERR_put_error(0xEu, 121, 7, ".\\crypto\\conf\\conf_def.c", 259);
err_27:
    BUF_MEM_free(str);
    if ( pto )
      CRYPTO_free(pto);
    goto LABEL_73;
  }
  while ( 1 )
  {
    v8 = &str->data[v4];
    v43 = b;
    *v8 = 0;
    BIO_gets(v43, v8, 511);
    v8[511] = 0;
    v9 = strlen(v8);
    v10 = v9;
    if ( !v9 && !i )
      break;
    v11 = 0;
    for ( i = 0; v9 > 0; --v9 )
    {
      v12 = v8[v9 - 1];
      if ( v12 != 13 && v12 != 10 )
        break;
    }
    if ( v10 && v9 == v10 )
    {
      v11 = 1;
      i = 1;
    }
    else
    {
      ++v49;
      v8[v9] = 0;
    }
    v4 += v9;
    value = 0;
    if ( v4 < 1
      || (v13 = str->data,
          v14 = (unsigned __int8)v13[v4 - 1],
          v15 = conf->meth_data,
          v16 = (int)&v13[v4 - 1],
          (v15[2 * v14] & 0x20) == 0)
      || v4 > 1 && (v15[2 * *(unsigned __int8 *)(v16 - 1)] & 0x20) != 0 )
    {
      if ( !v11 )
      {
        v17 = str->data;
        v4 = 0;
        v52 = 0;
        clear_comments(conf, v17);
        v18 = eat_ws(v17);
        meth_data = conf->meth_data;
        v20 = v18;
        v21 = *v18;
        if ( (meth_data[2 * v21] & 8) == 0 )
        {
          if ( v21 == 91 )
          {
            from = eat_ws(v20 + 1);
            j = from;
            while ( 1 )
            {
              v23 = eat_alpha_numeric(j);
              v24 = 2 * (unsigned __int8)*v23;
              for ( j = v23; (meth_data[v24] & 0x10) != 0; v24 = 2 * v25 )
              {
                if ( (meth_data[v24] & 8) != 0 )
                  break;
                v25 = (unsigned __int8)*++j;
              }
              if ( *j == 93 )
                break;
              if ( !*j )
              {
                ERR_put_error(0xEu, 121, 100, ".\\crypto\\conf\\conf_def.c", 330);
                goto err_27;
              }
            }
            *v23 = 0;
            if ( !str_copy(conf, 0, &pto) )
              goto err_27;
            v26 = pto;
            from = (char *)_CONF_get_section(conf, pto);
            if ( !from )
            {
              from = (char *)_CONF_new_section(conf, v26);
              if ( !from )
              {
                ERR_put_error(0xEu, 121, 103, ".\\crypto\\conf\\conf_def.c", 340);
                goto err_27;
              }
            }
          }
          else
          {
            src = v20;
            section = 0;
            v27 = eat_alpha_numeric(v20);
            v28 = v27;
            if ( *v27 == 58 && v27[1] == 58 )
            {
              *v27 = 0;
              section = v20;
              src = v27 + 2;
              v28 = eat_alpha_numeric(v27 + 2);
            }
            v29 = eat_ws(v28);
            if ( *v29 != 61 )
            {
              ERR_put_error(0xEu, 121, 101, ".\\crypto\\conf\\conf_def.c", 362);
              goto err_27;
            }
            v30 = (unsigned __int8 *)(v29 + 1);
            *v28 = 0;
            v31 = eat_ws(v29 + 1);
            v32 = conf->meth_data;
            if ( (v32[2 * *v30] & 8) == 0 )
            {
              do
                v33 = *++v30;
              while ( (v32[2 * v33] & 8) == 0 );
            }
            for ( k = (char *)(v30 - 1); k != v31; --k )
            {
              if ( (v32[2 * (unsigned __int8)*k] & 0x10) == 0 )
                break;
            }
            k[1] = 0;
            v35 = (CONF_VALUE *)CRYPTO_malloc(12, ".\\crypto\\conf\\conf_def.c", 376);
            value = v35;
            if ( !v35 )
            {
              ERR_put_error(0xEu, 121, 65, ".\\crypto\\conf\\conf_def.c", 379);
              goto err_27;
            }
            if ( !section )
              section = pto;
            v36 = (char *)CRYPTO_malloc(strlen(src) + 1, ".\\crypto\\conf\\conf_def.c", 383);
            v35->name = v36;
            p_value = &v35->value;
            *p_value = 0;
            if ( !v36 )
            {
              ERR_put_error(0xEu, 121, 65, ".\\crypto\\conf\\conf_def.c", 388);
              goto err_27;
            }
            BUF_strlcpy(v36, src, strlen(src) + 1);
            if ( !str_copy(conf, section, p_value) )
              goto err_27;
            v38 = section;
            if ( !strcmp(section, pto) )
            {
              v39 = (CONF_VALUE *)from;
            }
            else
            {
              v39 = _CONF_get_section(conf, section);
              if ( !v39 )
              {
                v39 = _CONF_new_section(conf, v38);
                if ( !v39 )
                {
                  ERR_put_error(0xEu, 121, 103, ".\\crypto\\conf\\conf_def.c", 402);
                  goto err_27;
                }
              }
            }
            if ( !_CONF_add_string(conf, v39, value) )
            {
              ERR_put_error(0xEu, 121, 65, ".\\crypto\\conf\\conf_def.c", 412);
              goto err_27;
            }
            v4 = v52;
            value = 0;
          }
        }
      }
    }
    else
    {
      --v4;
      i = 1;
    }
    if ( !BUF_MEM_grow(str, v4 + 512) )
      goto LABEL_63;
    v7 = pto;
  }
  BUF_MEM_free(str);
  if ( v7 )
    CRYPTO_free(v7);
  return 1;
}
