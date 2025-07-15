int __usercall x509_name_canon@<eax>(X509_name_st *a@<ebx>)
{
  unsigned __int8 *canon_enc; // eax
  int v2; // ebp
  stack_st_STACK_OF_X509_NAME_ENTRY *v4; // edi
  char *v5; // esi
  char *v6; // eax
  struct ASN1_VALUE_st *v7; // edi
  asn1_object_st *v8; // eax
  asn1_string_st *v9; // ecx
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // eax
  stack_st_STACK_OF_X509_NAME_ENTRY *_intname; // [esp+4h] [ebp-14h]
  int v13; // [esp+8h] [ebp-10h]
  stack_st *v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned __int8 *in; // [esp+14h] [ebp-4h] BYREF

  canon_enc = a->canon_enc;
  v2 = 0;
  v14 = 0;
  v13 = -1;
  v15 = 0;
  if ( canon_enc )
  {
    CRYPTO_free(canon_enc);
    a->canon_enc = 0;
  }
  if ( sk_num(&a->entries->stack) )
  {
    v4 = (stack_st_STACK_OF_X509_NAME_ENTRY *)sk_new_null();
    _intname = v4;
    if ( v4 )
    {
      if ( sk_num(&a->entries->stack) <= 0 )
      {
LABEL_15:
        v10 = i2d_name_canon(v4, 0);
        a->canon_enclen = (int)v10;
        v11 = (unsigned __int8 *)CRYPTO_malloc((int)v10, ".\\crypto\\asn1\\x_name.c", 365);
        in = v11;
        if ( v11 )
        {
          a->canon_enc = v11;
          i2d_name_canon(v4, &in);
          v15 = 1;
        }
      }
      else
      {
        while ( 1 )
        {
          v5 = sk_value(&a->entries->stack, v2);
          if ( *((_DWORD *)v5 + 2) != v13 )
          {
            v6 = (char *)sk_new_null();
            v14 = (stack_st *)v6;
            if ( !v6 || !sk_push(&_intname->stack, v6) )
              goto LABEL_19;
            v13 = *((_DWORD *)v5 + 2);
          }
          v7 = ASN1_item_new(&local_it_35);
          v8 = OBJ_dup((int)a, *(const asn1_object_st **)v5);
          v9 = (asn1_string_st *)*((_DWORD *)v7 + 1);
          *(_DWORD *)v7 = v8;
          if ( !asn1_string_canon(v9) || !sk_push(v14, (char *)v7) )
            break;
          if ( ++v2 >= sk_num(&a->entries->stack) )
          {
            v4 = _intname;
            goto LABEL_15;
          }
        }
        if ( v7 )
          ASN1_item_free(v7, &local_it_35);
LABEL_19:
        v4 = _intname;
      }
      sk_pop_free(&v4->stack, (void (__cdecl *)(void *))local_sk_X509_NAME_ENTRY_pop_free);
    }
    return v15;
  }
  else
  {
    a->canon_enclen = 0;
    return 1;
  }
}
