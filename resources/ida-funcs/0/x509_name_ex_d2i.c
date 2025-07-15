int __cdecl x509_name_ex_d2i(
        struct ASN1_VALUE_st **val,
        unsigned __int8 **in,
        const unsigned __int8 *len,
        const ASN1_ITEM_st *it,
        int tag,
        int aclass,
        int opt,
        ASN1_TLC_st *ctx)
{
  const __m128i *v8; // esi
  int v9; // ebx
  int result; // eax
  struct ASN1_VALUE_st **v11; // edi
  int v12; // eax
  X509_name_st *v13; // ebp
  stack_st *v14; // esi
  int v15; // edi
  char *v16; // eax
  unsigned __int8 *v17; // ecx
  struct ASN1_VALUE_st *pval; // [esp+8h] [ebp-Ch] BYREF
  unsigned __int8 *ina; // [esp+Ch] [ebp-8h] BYREF
  X509_name_st *a; // [esp+10h] [ebp-4h] BYREF

  v8 = (const __m128i *)*in;
  v9 = 0;
  ina = *in;
  pval = 0;
  a = 0;
  result = ASN1_item_ex_d2i(&pval, &ina, len, &stru_6CE1B0, tag, aclass, opt, ctx);
  if ( result > 0 )
  {
    v11 = val;
    if ( *val )
      x509_name_ex_free(val);
    v12 = x509_name_ex_new(0, (struct ASN1_VALUE_st **)&a);
    v13 = a;
    if ( v12 && BUF_MEM_grow(a->bytes, ina - (unsigned __int8 *)v8) )
    {
      memcpy((int)v13->bytes->data, v8, ina - (unsigned __int8 *)v8);
      if ( sk_num((const stack_st *)pval) <= 0 )
      {
LABEL_12:
        sk_free((stack_st *)pval);
        v9 = (int)v13;
        result = x509_name_canon(v13);
        if ( result )
        {
          v13->modified = 0;
          v17 = ina;
          *v11 = (struct ASN1_VALUE_st *)v13;
          *in = v17;
          return result;
        }
      }
      else
      {
        while ( 1 )
        {
          v14 = (stack_st *)sk_value((const stack_st *)pval, v9);
          v15 = 0;
          if ( sk_num(v14) > 0 )
            break;
LABEL_10:
          sk_free(v14);
          if ( ++v9 >= sk_num((const stack_st *)pval) )
          {
            v11 = val;
            goto LABEL_12;
          }
        }
        while ( 1 )
        {
          v16 = sk_value(v14, v15);
          *((_DWORD *)v16 + 2) = v9;
          if ( !sk_push(&v13->entries->stack, v16) )
            break;
          if ( ++v15 >= sk_num(v14) )
            goto LABEL_10;
        }
      }
    }
    if ( v13 )
      ASN1_item_free((struct ASN1_VALUE_st *)v13, &local_it_37);
    ERR_put_error(v9, 0xDu, 158, 58, ".\\crypto\\asn1\\x_name.c", 220);
    return 0;
  }
  return result;
}
