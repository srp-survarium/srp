int __cdecl PEM_read_bio(bio_st *bp, char **name, char **header, unsigned __int8 **data, int *len)
{
  buf_mem_st *v5; // esi
  buf_mem_st *v6; // ebp
  buf_mem_st *v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned int v10; // kr00_4
  int v11; // edi
  int i; // esi
  int v13; // esi
  unsigned int v14; // esi
  bio_st *v15; // ecx
  buf_mem_st *v16; // esi
  int v17; // esi
  int v18; // esi
  signed int v19; // esi
  buf_mem_st *v20; // edi
  int v21; // eax
  int v22; // eax
  buf_mem_st *v23; // eax
  unsigned int v24; // esi
  bool v25; // zf
  int v26; // eax
  buf_mem_st *v27; // ecx
  _DWORD *v28; // edi
  buf_mem_st *v29; // esi
  bio_st *v31; // [esp-Ch] [ebp-1ACh]
  int outl; // [esp+10h] [ebp-190h] BYREF
  buf_mem_st *a; // [esp+14h] [ebp-18Ch]
  bio_st *v34; // [esp+18h] [ebp-188h]
  buf_mem_st *str; // [esp+1Ch] [ebp-184h]
  int v36; // [esp+20h] [ebp-180h]
  int v37; // [esp+24h] [ebp-17Ch]
  int v38; // [esp+28h] [ebp-178h] BYREF
  unsigned __int8 **v39; // [esp+2Ch] [ebp-174h]
  int *v40; // [esp+30h] [ebp-170h]
  char **v41; // [esp+34h] [ebp-16Ch]
  char **v42; // [esp+38h] [ebp-168h]
  evp_Encode_Ctx_st ctx; // [esp+3Ch] [ebp-164h] BYREF
  char in[9]; // [esp+9Ch] [ebp-104h] BYREF
  char last[2]; // [esp+A5h] [ebp-FBh] BYREF
  unsigned __int8 src[245]; // [esp+A7h] [ebp-F9h] BYREF

  v42 = name;
  v34 = bp;
  v41 = header;
  v39 = data;
  v40 = len;
  v37 = 0;
  outl = 0;
  v36 = 0;
  v5 = BUF_MEM_new();
  str = v5;
  v6 = BUF_MEM_new();
  v7 = BUF_MEM_new();
  a = v7;
  if ( v5 && v6 && v7 )
  {
    src[243] = 0;
    v8 = BIO_gets(bp, in, 254);
    if ( v8 <= 0 )
    {
LABEL_10:
      ERR_put_error(9u, 109, 108, ".\\crypto\\pem\\pem_lib.c", 696);
    }
    else
    {
      while ( 1 )
      {
        do
        {
          if ( in[v8] > 32 )
            break;
          --v8;
        }
        while ( v8 >= 0 );
        v9 = v8 + 1;
        in[v9] = 10;
        in[v9 + 1] = 0;
        if ( !strncmp(in, "-----BEGIN ", 0xBu) )
        {
          v10 = strlen((const char *)src);
          if ( !strncmp(&in[v10 + 5], "-----\n", 6u) )
            break;
        }
        v8 = BIO_gets(bp, in, 254);
        if ( v8 <= 0 )
          goto LABEL_10;
      }
      if ( BUF_MEM_grow(str, v10 + 9) )
      {
        memcpy((unsigned __int8 *)str->data, src, v10 - 6);
        str->data[v10 - 6] = 0;
        v11 = 0;
        if ( BUF_MEM_grow(v6, 0x100u) )
        {
          v31 = v34;
          *v6->data = 0;
          for ( i = BIO_gets(v31, in, 254); i > 0; i = BIO_gets(v15, in, 254) )
          {
            do
            {
              if ( in[i] > 32 )
                break;
              --i;
            }
            while ( i >= 0 );
            v13 = i + 1;
            in[v13] = 10;
            v14 = v13 + 1;
            in[v14] = 0;
            if ( in[0] == 10 )
              break;
            if ( !BUF_MEM_grow(v6, v14 + v11 + 9) )
            {
              ERR_put_error(9u, 109, 65, ".\\crypto\\pem\\pem_lib.c", 733);
              goto err_209;
            }
            if ( !strncmp(in, "-----END ", 9u) )
            {
              v36 = 1;
              break;
            }
            memcpy((unsigned __int8 *)&v6->data[v11], (unsigned __int8 *)in, v14);
            v15 = v34;
            v6->data[v14 + v11] = 0;
            v11 += v14;
          }
          v16 = a;
          outl = 0;
          if ( BUF_MEM_grow(a, 0x400u) )
          {
            *a->data = 0;
            if ( v36 )
            {
              v23 = v6;
              outl = v11;
              v6 = v16;
              a = v23;
              v20 = v23;
            }
            else
            {
              v17 = BIO_gets(v34, in, 254);
              if ( v17 > 0 )
              {
                while ( 1 )
                {
                  do
                  {
                    if ( in[v17] > 32 )
                      break;
                    --v17;
                  }
                  while ( v17 >= 0 );
                  v18 = v17 + 1;
                  in[v18] = 10;
                  v19 = v18 + 1;
                  in[v19] = 0;
                  if ( v19 != 65 )
                    v37 = 1;
                  if ( !strncmp(in, "-----END ", 9u) || v19 > 65 )
                    break;
                  v20 = a;
                  if ( !BUF_MEM_grow_clean(a, v19 + outl + 9) )
                  {
                    ERR_put_error(9u, 109, 65, ".\\crypto\\pem\\pem_lib.c", 764);
                    goto err_209;
                  }
                  memcpy((unsigned __int8 *)&a->data[outl], (unsigned __int8 *)in, v19);
                  a->data[v19 + outl] = 0;
                  outl += v19;
                  if ( v37 )
                  {
                    in[0] = 0;
                    v21 = BIO_gets(v34, in, 254);
                    if ( v21 > 0 )
                    {
                      do
                      {
                        if ( in[v21] > 32 )
                          break;
                        --v21;
                      }
                      while ( v21 >= 0 );
                      v22 = v21 + 1;
                      in[v22] = 10;
                      in[v22 + 1] = 0;
                    }
                    goto LABEL_46;
                  }
                  v17 = BIO_gets(v34, in, 254);
                  if ( v17 <= 0 )
                    goto LABEL_46;
                }
              }
              v20 = a;
            }
LABEL_46:
            v24 = strlen(str->data);
            if ( !strncmp(in, "-----END ", 9u) && !strncmp(str->data, last, v24) && !strncmp(&last[v24], "-----\n", 6u) )
            {
              EVP_DecodeInit(&ctx);
              if ( EVP_DecodeUpdate(&ctx, (unsigned __int8 *)v20->data, &outl, (const unsigned __int8 *)v20->data, outl) >= 0 )
              {
                if ( EVP_DecodeFinal(&ctx, (unsigned __int8 *)&v20->data[outl], &v38) >= 0 )
                {
                  v25 = v38 + outl == 0;
                  v26 = v38 + outl;
                  outl += v38;
                  if ( !v25 )
                  {
                    v27 = str;
                    v28 = v39;
                    *v42 = str->data;
                    *v41 = v6->data;
                    v29 = a;
                    *v28 = a->data;
                    *v40 = v26;
                    CRYPTO_free(v27);
                    CRYPTO_free(v6);
                    CRYPTO_free(v29);
                    return 1;
                  }
                }
                else
                {
                  ERR_put_error(9u, 109, 100, ".\\crypto\\pem\\pem_lib.c", 811);
                }
              }
              else
              {
                ERR_put_error(9u, 109, 100, ".\\crypto\\pem\\pem_lib.c", 805);
              }
            }
            else
            {
              ERR_put_error(9u, 109, 102, ".\\crypto\\pem\\pem_lib.c", 795);
            }
          }
          else
          {
            ERR_put_error(9u, 109, 65, ".\\crypto\\pem\\pem_lib.c", 746);
          }
        }
        else
        {
          ERR_put_error(9u, 109, 65, ".\\crypto\\pem\\pem_lib.c", 721);
        }
      }
      else
      {
        ERR_put_error(9u, 109, 65, ".\\crypto\\pem\\pem_lib.c", 711);
      }
    }
err_209:
    BUF_MEM_free(str);
    BUF_MEM_free(v6);
    BUF_MEM_free(a);
  }
  else
  {
    BUF_MEM_free(v5);
    BUF_MEM_free(v6);
    BUF_MEM_free(a);
    ERR_put_error(9u, 109, 65, ".\\crypto\\pem\\pem_lib.c", 685);
  }
  return 0;
}
