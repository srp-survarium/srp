int __usercall PKCS1_MGF1@<eax>(
        unsigned int a1@<edi>,
        unsigned __int8 *mask,
        int len,
        const unsigned __int8 *seed,
        unsigned int seedlen,
        const env_md_st *dgst)
{
  const env_md_st *v6; // ebp
  int v7; // esi
  int v8; // ebx
  int v10; // [esp+10h] [ebp-6Ch]
  int v11; // [esp+18h] [ebp-64h]
  env_md_ctx_st ctx; // [esp+20h] [ebp-5Ch] BYREF
  unsigned __int8 src[64]; // [esp+38h] [ebp-44h] BYREF

  v6 = dgst;
  v7 = 0;
  v10 = -1;
  EVP_MD_CTX_init(&ctx);
  v11 = EVP_MD_size(dgst);
  if ( v11 >= 0 )
  {
    v8 = 0;
    if ( len <= 0 )
    {
LABEL_14:
      v10 = 0;
    }
    else
    {
      while ( EVP_DigestInit_ex(&ctx, v6, 0) && EVP_DigestUpdate(&ctx) && EVP_DigestUpdate(&ctx) )
      {
        if ( v11 + v7 > len )
        {
          if ( !EVP_DigestFinal_ex(len, &ctx, src, 0) )
            break;
          memcpy(&mask[v7], src, len - v7);
          v7 = len;
        }
        else
        {
          if ( !EVP_DigestFinal_ex(len, &ctx, &mask[v7], 0) )
            break;
          v7 += v11;
        }
        ++v8;
        if ( v7 >= len )
          goto LABEL_14;
        v6 = dgst;
      }
    }
  }
  EVP_MD_CTX_cleanup(a1, &ctx);
  return v10;
}
