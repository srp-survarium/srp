int __usercall asn1_d2i_ex_primitive@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        asn1_type_st **pval,
        unsigned __int8 **in,
        const unsigned __int8 **inlen,
        const ASN1_ITEM_st *it,
        int aclass,
        char opt,
        ASN1_TLC_st *ctx)
{
  int v9; // esi
  int result; // eax
  int utype; // ebx
  unsigned __int8 **v12; // edi
  int v13; // eax
  int length; // esi
  unsigned __int8 *v15; // ebp
  const __m128i *data; // edi
  char v17; // [esp+Ah] [ebp-1Eh] BYREF
  unsigned __int8 v18; // [esp+Bh] [ebp-1Dh] BYREF
  __m128i *v19; // [esp+Ch] [ebp-1Ch] BYREF
  int v20; // [esp+10h] [ebp-18h] BYREF
  int v21; // [esp+14h] [ebp-14h] BYREF
  int v22; // [esp+18h] [ebp-10h]
  buf_mem_st v23; // [esp+1Ch] [ebp-Ch] BYREF

  v9 = a1;
  v17 = 0;
  if ( !pval )
  {
    ERR_put_error(a2, 0xDu, 108, 125, ".\\crypto\\asn1\\tasn_dec.c", 780);
    return 0;
  }
  if ( it->itype == 5 )
  {
    utype = a1;
    v9 = -1;
  }
  else
  {
    utype = it->utype;
  }
  v20 = utype;
  if ( utype == -4 )
  {
    if ( v9 >= 0 )
    {
      ERR_put_error(-4, 0xDu, 108, 127, ".\\crypto\\asn1\\tasn_dec.c", 799);
      return 0;
    }
    if ( opt )
    {
      ERR_put_error(-4, 0xDu, 108, 126, ".\\crypto\\asn1\\tasn_dec.c", 805);
      return 0;
    }
    v12 = in;
    v19 = (__m128i *)*in;
    if ( !asn1_check_tlen(0, &v20, &v18, 0, 0, (ASN1_TLC_st **)&v19, inlen, -1, 0, 0, ctx) )
    {
      ERR_put_error(-4, 0xDu, 108, 58, ".\\crypto\\asn1\\tasn_dec.c", 814);
      return 0;
    }
    if ( v18 )
      utype = -3;
    else
      utype = v20;
  }
  else
  {
    v12 = in;
  }
  if ( v9 == -1 )
  {
    v9 = utype;
    v13 = 0;
  }
  else
  {
    v13 = aclass;
  }
  v19 = (__m128i *)*v12;
  result = asn1_check_tlen(
             (const unsigned __int8 **)&v20,
             0,
             0,
             (char *)&v21,
             (char *)&v18,
             (ASN1_TLC_st **)&v19,
             inlen,
             v9,
             v13,
             opt,
             ctx);
  if ( !result )
  {
    ERR_put_error(utype, 0xDu, 108, 58, ".\\crypto\\asn1\\tasn_dec.c", 831);
    return 0;
  }
  if ( result != -1 )
  {
    v22 = 0;
    if ( utype == 16 || utype == 17 )
    {
      if ( !v18 )
      {
        ERR_put_error(utype, 0xDu, 108, 156, ".\\crypto\\asn1\\tasn_dec.c", 852);
        return 0;
      }
    }
    else
    {
      if ( utype != -3 )
      {
        if ( v18 )
        {
          memset(&v23, 0, sizeof(v23));
          if ( !asn1_collect(&v23, (unsigned __int8 **)&v19, v20, v21, -1, 0, 0) )
          {
            v17 = 1;
            goto LABEL_46;
          }
          length = v23.length;
          if ( !BUF_MEM_grow_clean(&v23, v23.length + 1) )
          {
            ERR_put_error(utype, 0xDu, 108, 65, ".\\crypto\\asn1\\tasn_dec.c", 892);
            return 0;
          }
          v15 = (unsigned __int8 *)v19;
          v23.data[length] = 0;
          data = (const __m128i *)v23.data;
          v17 = 1;
        }
        else
        {
          length = v20;
          data = v19;
          v15 = &v19->m128i_u8[v20];
        }
        goto LABEL_43;
      }
      if ( ctx )
        ctx->valid = 0;
    }
    data = (const __m128i *)*v12;
    if ( (_BYTE)v21 )
    {
      if ( !asn1_find_end(v20, utype, (unsigned __int8 **)&v19, v21) )
        goto err_48;
      v15 = (unsigned __int8 *)v19;
      length = (char *)v19 - (char *)data;
    }
    else
    {
      length = (int)v19->m128i_i32 + v20 - (_DWORD)data;
      v15 = &v19->m128i_u8[v20];
      v23.data = 0;
    }
LABEL_43:
    if ( asn1_ex_c2i(pval, data, length, utype, &v17, it) )
    {
      *in = v15;
      v22 = 1;
    }
err_48:
    if ( !v17 )
      return v22;
LABEL_46:
    if ( v23.data )
      CRYPTO_free(v23.data);
    return v22;
  }
  return result;
}
