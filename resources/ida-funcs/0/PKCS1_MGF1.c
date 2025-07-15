int __usercall PKCS1_MGF1@<eax>(
        int a1@<edi>,
        int a2@<ebx>,
        unsigned __int8 *mask,
        int len,
        const unsigned __int8 *seed,
        int seedlen,
        const env_md_st *dgst)
{
  const env_md_st *v7; // ebp
  int v8; // esi
  engine_st *v9; // ebx
  int v11; // [esp-4h] [ebp-80h]
  int v12; // [esp+10h] [ebp-6Ch]
  int v13; // [esp+18h] [ebp-64h]
  env_md_ctx_st ctx; // [esp+20h] [ebp-5Ch] BYREF
  __m128i src[4]; // [esp+38h] [ebp-44h] BYREF

  v7 = dgst;
  v8 = 0;
  v12 = -1;
  EVP_MD_CTX_init(&ctx);
  v13 = EVP_MD_size(a2, dgst);
  if ( v13 >= 0 )
  {
    v11 = a2;
    v9 = 0;
    if ( len <= 0 )
    {
LABEL_14:
      v12 = 0;
    }
    else
    {
      while ( EVP_DigestInit_ex(v9, &ctx, v7, 0) && EVP_DigestUpdate(&ctx) && EVP_DigestUpdate(&ctx) )
      {
        if ( v13 + v8 > len )
        {
          if ( !EVP_DigestFinal_ex(len, (int)v9, &ctx, (unsigned __int8 *)src, 0) )
            break;
          memcpy((int)&mask[v8], src, len - v8);
          v8 = len;
        }
        else
        {
          if ( !EVP_DigestFinal_ex(len, (int)v9, &ctx, &mask[v8], 0) )
            break;
          v8 += v13;
        }
        v9 = (engine_st *)((char *)v9 + 1);
        if ( v8 >= len )
          goto LABEL_14;
        v7 = dgst;
      }
    }
    a2 = v11;
  }
  EVP_MD_CTX_cleanup(a1, a2, &ctx);
  return v12;
}
