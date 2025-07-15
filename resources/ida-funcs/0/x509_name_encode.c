unsigned int __usercall x509_name_encode@<eax>(X509_name_st *a@<esi>)
{
  int v1; // ebx
  int v2; // ebp
  struct ASN1_VALUE_st *v3; // eax
  char *v4; // edi
  stack_st *v5; // eax
  unsigned __int8 *v6; // edi
  unsigned int result; // eax
  struct ASN1_VALUE_st *pval; // [esp+Ch] [ebp-Ch] BYREF
  stack_st *v9; // [esp+10h] [ebp-8h]
  unsigned __int8 *out; // [esp+14h] [ebp-4h] BYREF

  v1 = 0;
  v9 = 0;
  v2 = -1;
  v3 = (struct ASN1_VALUE_st *)sk_new_null();
  pval = v3;
  if ( !v3 )
    goto memerr_2;
  if ( sk_num(&a->entries->stack) > 0 )
  {
    do
    {
      v4 = sk_value(&a->entries->stack, v1);
      if ( *((_DWORD *)v4 + 2) != v2 )
      {
        v5 = sk_new_null();
        v9 = v5;
        if ( !v5 || !sk_push((stack_st *)pval, (char *)v5) )
          goto LABEL_10;
        v2 = *((_DWORD *)v4 + 2);
      }
      if ( !sk_push(v9, v4) )
        goto LABEL_10;
      ++v1;
    }
    while ( v1 < sk_num(&a->entries->stack) );
  }
  v6 = ASN1_item_ex_i2d(&pval, 0, &stru_6CE1B0, -1, -1);
  if ( !BUF_MEM_grow(a->bytes, (unsigned int)v6) )
  {
LABEL_10:
    v3 = pval;
memerr_2:
    sk_pop_free((stack_st *)v3, (void (__cdecl *)(void *))local_sk_X509_NAME_ENTRY_free);
    ERR_put_error(v1, 0xDu, 203, 65, ".\\crypto\\asn1\\x_name.c", 290);
    return -1;
  }
  out = (unsigned __int8 *)a->bytes->data;
  ASN1_item_ex_i2d(&pval, &out, &stru_6CE1B0, -1, -1);
  sk_pop_free((stack_st *)pval, (void (__cdecl *)(void *))local_sk_X509_NAME_ENTRY_free);
  result = (unsigned int)v6;
  a->modified = 0;
  return result;
}
