unsigned int __usercall x509_name_encode@<eax>(X509_name_st *a@<esi>)
{
  int v1; // ebx
  int v2; // ebp
  stack_st *v3; // eax
  char *v4; // edi
  stack_st *v5; // eax
  unsigned int v6; // edi
  unsigned int result; // eax
  stack_st *st; // [esp+Ch] [ebp-Ch] BYREF
  stack_st *v9; // [esp+10h] [ebp-8h]
  unsigned __int8 *out; // [esp+14h] [ebp-4h] BYREF

  v1 = 0;
  v9 = 0;
  v2 = -1;
  v3 = sk_new_null();
  st = v3;
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
        if ( !v5 || !sk_push(st, (char *)v5) )
          goto LABEL_10;
        v2 = *((_DWORD *)v4 + 2);
      }
      if ( !sk_push(v9, v4) )
        goto LABEL_10;
      ++v1;
    }
    while ( v1 < sk_num(&a->entries->stack) );
  }
  v6 = ASN1_item_ex_i2d((struct ASN1_VALUE_st **)&st, 0, &stru_83C4F4, -1, -1);
  if ( !BUF_MEM_grow(a->bytes, v6) )
  {
LABEL_10:
    v3 = st;
memerr_2:
    sk_pop_free(v3, (void (__cdecl *)(void *))local_sk_X509_NAME_ENTRY_free);
    ERR_put_error(0xDu, 203, 65, ".\\crypto\\asn1\\x_name.c", 290);
    return -1;
  }
  out = (unsigned __int8 *)a->bytes->data;
  ASN1_item_ex_i2d((struct ASN1_VALUE_st **)&st, &out, &stru_83C4F4, -1, -1);
  sk_pop_free(st, (void (__cdecl *)(void *))local_sk_X509_NAME_ENTRY_free);
  result = v6;
  a->modified = 0;
  return result;
}
