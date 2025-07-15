int __cdecl asn1_d2i_ex_primitive(
        struct ASN1_VALUE_st **pval,
        unsigned __int8 **in,
        unsigned __int8 *inlen,
        const ASN1_ITEM_st *it,
        int aclass,
        char opt,
        ASN1_TLC_st *ctx)
{
  int tag; // ecx
  int v8; // esi
  int result; // eax
  int utype; // ebx
  unsigned __int8 **v11; // edi
  int v12; // eax
  int length; // esi
  unsigned __int8 *v14; // ebp
  unsigned __int8 *data; // edi
  char free_cont; // [esp+Ah] [ebp-1Eh] BYREF
  unsigned __int8 oclass; // [esp+Bh] [ebp-1Dh] BYREF
  unsigned __int8 *ina; // [esp+Ch] [ebp-1Ch] BYREF
  int otag; // [esp+10h] [ebp-18h] BYREF
  char inf[4]; // [esp+14h] [ebp-14h] BYREF
  int v21; // [esp+18h] [ebp-10h]
  buf_mem_st buf; // [esp+1Ch] [ebp-Ch] BYREF

  v8 = tag;
  free_cont = 0;
  if ( !pval )
  {
    ERR_put_error(0xDu, 108, 125, ".\\crypto\\asn1\\tasn_dec.c", 780);
    return 0;
  }
  if ( it->itype == 5 )
  {
    utype = tag;
    v8 = -1;
  }
  else
  {
    utype = it->utype;
  }
  otag = utype;
  if ( utype == -4 )
  {
    if ( v8 >= 0 )
    {
      ERR_put_error(0xDu, 108, 127, ".\\crypto\\asn1\\tasn_dec.c", 799);
      return 0;
    }
    if ( opt )
    {
      ERR_put_error(0xDu, 108, 126, ".\\crypto\\asn1\\tasn_dec.c", 805);
      return 0;
    }
    v11 = in;
    ina = *in;
    if ( !asn1_check_tlen(0, &otag, &oclass, 0, 0, (ASN1_TLC_st **)&ina, inlen, -1, 0, 0, ctx) )
    {
      ERR_put_error(0xDu, 108, 58, ".\\crypto\\asn1\\tasn_dec.c", 814);
      return 0;
    }
    if ( oclass )
      utype = -3;
    else
      utype = otag;
  }
  else
  {
    v11 = in;
  }
  if ( v8 == -1 )
  {
    v8 = utype;
    v12 = 0;
  }
  else
  {
    v12 = aclass;
  }
  ina = *v11;
  result = asn1_check_tlen(&otag, 0, 0, inf, (char *)&oclass, (ASN1_TLC_st **)&ina, inlen, v8, v12, opt, ctx);
  if ( !result )
  {
    ERR_put_error(0xDu, 108, 58, ".\\crypto\\asn1\\tasn_dec.c", 831);
    return 0;
  }
  if ( result != -1 )
  {
    v21 = 0;
    if ( utype == 16 || utype == 17 )
    {
      if ( !oclass )
      {
        ERR_put_error(0xDu, 108, 156, ".\\crypto\\asn1\\tasn_dec.c", 852);
        return 0;
      }
    }
    else
    {
      if ( utype != -3 )
      {
        if ( oclass )
        {
          memset(&buf, 0, sizeof(buf));
          if ( !asn1_collect(&buf, &ina, otag, inf[0], -1, 0, 0) )
          {
            free_cont = 1;
            goto LABEL_46;
          }
          length = buf.length;
          if ( !BUF_MEM_grow_clean(&buf, buf.length + 1) )
          {
            ERR_put_error(0xDu, 108, 65, ".\\crypto\\asn1\\tasn_dec.c", 892);
            return 0;
          }
          v14 = ina;
          buf.data[length] = 0;
          data = (unsigned __int8 *)buf.data;
          free_cont = 1;
        }
        else
        {
          length = otag;
          data = ina;
          v14 = &ina[otag];
        }
        goto LABEL_43;
      }
      if ( ctx )
        ctx->valid = 0;
    }
    data = *v11;
    if ( inf[0] )
    {
      if ( !asn1_find_end(&ina, inf[0]) )
        goto err_46;
      v14 = ina;
      length = ina - data;
    }
    else
    {
      length = (int)&ina[otag - (_DWORD)data];
      v14 = &ina[otag];
      buf.data = 0;
    }
LABEL_43:
    if ( asn1_ex_c2i((asn1_type_st **)pval, data, length, utype, &free_cont, it) )
    {
      *in = v14;
      v21 = 1;
    }
err_46:
    if ( !free_cont )
      return v21;
LABEL_46:
    if ( buf.data )
      CRYPTO_free(buf.data);
    return v21;
  }
  return result;
}
