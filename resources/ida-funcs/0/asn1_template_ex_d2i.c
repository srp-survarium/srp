int __usercall asn1_template_ex_d2i@<eax>(
        unsigned __int8 *inlen@<edx>,
        const ASN1_TEMPLATE_st *tt@<esi>,
        char opt@<cl>,
        struct ASN1_VALUE_st **val,
        unsigned __int8 **in,
        ASN1_TLC_st *ctx)
{
  ASN1_TLC_st *v6; // ebx
  stack_st **v7; // ebp
  int result; // eax
  unsigned int flags; // eax
  unsigned __int8 *v10; // edi
  int v11; // ebx
  int v12; // ebx
  ASN1_TLC_st *v13; // [esp-8h] [ebp-1Ch]
  char v14; // [esp+Bh] [ebp-9h] BYREF
  unsigned __int8 *ina; // [esp+Ch] [ebp-8h] BYREF
  int len; // [esp+10h] [ebp-4h] BYREF

  v6 = ctx;
  v7 = (stack_st **)val;
  if ( !val )
    return 0;
  flags = tt->flags;
  ina = *in;
  if ( (flags & 0x10) == 0 )
    return asn1_template_noexp_d2i((stack_st **)val, in, inlen, tt, opt, ctx);
  result = asn1_check_tlen(
             (const unsigned __int8 **)&len,
             0,
             0,
             &v14,
             (char *)&val,
             (ASN1_TLC_st **)&ina,
             (const unsigned __int8 **)inlen,
             tt->tag,
             flags & 0xC0,
             opt,
             ctx);
  v10 = ina;
  if ( !result )
  {
    ERR_put_error((int)v6, 0xDu, 132, 58, ".\\crypto\\asn1\\tasn_dec.c", 563);
    return 0;
  }
  if ( result == -1 )
    return result;
  if ( !(_BYTE)val )
  {
    ERR_put_error((int)v6, 0xDu, 132, 120, ".\\crypto\\asn1\\tasn_dec.c", 571);
    return 0;
  }
  v13 = v6;
  v11 = len;
  if ( !asn1_template_noexp_d2i(v7, &ina, (const unsigned __int8 *)len, tt, 0, v13) )
  {
    ERR_put_error(v11, 0xDu, 132, 58, ".\\crypto\\asn1\\tasn_dec.c", 579);
    return 0;
  }
  v12 = v10 - ina + v11;
  if ( v14 )
  {
    if ( !asn1_check_eoc(v12) )
    {
      ERR_put_error(v12, 0xDu, 132, 137, ".\\crypto\\asn1\\tasn_dec.c", 590);
LABEL_17:
      ASN1_template_free((const stack_st **)v7, tt);
      return 0;
    }
  }
  else if ( v12 )
  {
    ERR_put_error(v12, 0xDu, 132, 119, ".\\crypto\\asn1\\tasn_dec.c", 601);
    goto LABEL_17;
  }
  *in = ina;
  return 1;
}
