int __cdecl get_cert_by_subject(x509_lookup_st *xl, int type, X509_name_st *name, x509_object_st *ret)
{
  int v5; // ebx
  buf_mem_st *v6; // ebp
  char *method_data; // edi
  char *v8; // esi
  int v9; // eax
  char *v10; // edi
  int v11; // ebx
  int v13; // eax
  int v14; // eax
  x509_object_st *v15; // ecx
  int v16; // [esp+8h] [ebp-100h]
  int i; // [esp+10h] [ebp-F8h]
  int v18; // [esp+14h] [ebp-F4h]
  char *v19; // [esp+18h] [ebp-F0h]
  const char *v20; // [esp+1Ch] [ebp-ECh]
  char *v21; // [esp+20h] [ebp-E8h]
  int v22; // [esp+24h] [ebp-E4h] BYREF
  _DWORD *v23; // [esp+28h] [ebp-E0h]
  char data[8]; // [esp+2Ch] [ebp-DCh] BYREF
  x509_object_st *v25; // [esp+34h] [ebp-D4h]
  _stat64i32 buf; // [esp+38h] [ebp-D0h] BYREF
  _DWORD v27[19]; // [esp+68h] [ebp-A0h] BYREF
  char v28; // [esp+B4h] [ebp-54h] BYREF
  X509_name_st *v29; // [esp+BCh] [ebp-4Ch]
  char v30; // [esp+D0h] [ebp-38h] BYREF
  X509_name_st *v31; // [esp+E4h] [ebp-24h]

  v25 = ret;
  v18 = 0;
  if ( !name )
    return 0;
  v5 = type;
  v22 = type;
  if ( type == 1 )
  {
    v27[0] = &v30;
    v31 = name;
    v23 = v27;
    v20 = (const char *)&::buf;
LABEL_7:
    v6 = BUF_MEM_new();
    if ( v6 )
    {
      method_data = xl->method_data;
      v21 = method_data;
      v16 = X509_NAME_hash(name);
      i = 0;
      if ( sk_num(*((const stack_st **)method_data + 1)) > 0 )
      {
        while ( 1 )
        {
          v8 = sk_value(*((const stack_st **)method_data + 1), i);
          if ( !BUF_MEM_grow(v6, strlen(*(const char **)v8) + 17) )
          {
            ERR_put_error(0xBu, 103, 65, ".\\crypto\\x509\\by_dir.c", 335);
            goto finish_1;
          }
          if ( v5 == 2 && *((_DWORD *)v8 + 2) )
          {
            *(_DWORD *)data = v16;
            CRYPTO_lock((unsigned int)method_data, 5, 11, ".\\crypto\\x509\\by_dir.c", 341);
            v9 = sk_find(*((stack_st **)v8 + 2), data);
            if ( v9 < 0 )
            {
              v10 = 0;
              v11 = 0;
            }
            else
            {
              v10 = sk_value(*((const stack_st **)v8 + 2), v9);
              v11 = *((_DWORD *)v10 + 1);
            }
            CRYPTO_lock((unsigned int)v10, 6, 11, ".\\crypto\\x509\\by_dir.c", 353);
          }
          else
          {
            v11 = 0;
            v10 = 0;
          }
          while ( 1 )
          {
            BIO_snprintf(v6->data, v6->max, "%s%c%08lx.%s%d", *(const char **)v8, 47, v16, v20, v11);
            if ( _stat64i32(v6->data, &buf) < 0 )
              break;
            if ( !(type == 1
                 ? X509_load_cert_file(xl, v6->data, *((_DWORD *)v8 + 1))
                 : X509_load_crl_file(xl, v6->data, *((_DWORD *)v8 + 1))) )
              break;
            ++v11;
          }
          CRYPTO_lock((unsigned int)v10, 9, 11, ".\\crypto\\x509\\by_dir.c", 423);
          v13 = sk_find(&xl->store_ctx->objs->stack, (char *)&v22);
          if ( v13 == -1 )
            v19 = 0;
          else
            v19 = sk_value(&xl->store_ctx->objs->stack, v13);
          CRYPTO_lock((unsigned int)v10, 10, 11, ".\\crypto\\x509\\by_dir.c", 427);
          if ( type == 2 )
          {
            CRYPTO_lock((unsigned int)v10, 9, 11, ".\\crypto\\x509\\by_dir.c", 434);
            if ( v10
              || (*(_DWORD *)data = v16, v14 = sk_find(*((stack_st **)v8 + 2), data), v14 >= 0)
              && (v10 = sk_value(*((const stack_st **)v8 + 2), v14)) != 0 )
            {
              if ( *((_DWORD *)v10 + 1) < v11 )
                *((_DWORD *)v10 + 1) = v11;
            }
            else
            {
              v10 = (char *)CRYPTO_malloc(8, ".\\crypto\\x509\\by_dir.c", 448);
              *(_DWORD *)v10 = v16;
              *((_DWORD *)v10 + 1) = v11;
              if ( !sk_push(*((stack_st **)v8 + 2), v10) )
              {
                CRYPTO_lock((unsigned int)v10, 10, 11, ".\\crypto\\x509\\by_dir.c", 453);
                CRYPTO_free(v10);
                v18 = 0;
                goto finish_1;
              }
            }
            CRYPTO_lock((unsigned int)v10, 10, 11, ".\\crypto\\x509\\by_dir.c", 462);
          }
          if ( v19 )
            break;
          if ( ++i >= sk_num(*((const stack_st **)v21 + 1)) )
            goto finish_1;
          method_data = v21;
          v5 = type;
        }
        v15 = v25;
        v25->type = *(_DWORD *)v19;
        v18 = 1;
        v15->data.ptr = (char *)*((_DWORD *)v19 + 1);
      }
    }
    else
    {
      ERR_put_error(0xBu, 103, 7, ".\\crypto\\x509\\by_dir.c", 319);
    }
finish_1:
    if ( v6 )
      BUF_MEM_free(v6);
    return v18;
  }
  if ( type == 2 )
  {
    v27[0] = &v28;
    v29 = name;
    v23 = v27;
    v20 = "r";
    goto LABEL_7;
  }
  ERR_put_error(0xBu, 103, 112, ".\\crypto\\x509\\by_dir.c", 313);
  return v18;
}
