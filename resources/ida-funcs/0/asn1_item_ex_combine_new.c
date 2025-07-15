int __usercall asn1_item_ex_combine_new@<eax>(
        struct ASN1_VALUE_st **pval@<edi>,
        const ASN1_ITEM_st *it@<ecx>,
        int combine)
{
  _DWORD *funcs; // eax
  int v5; // ebp
  int (__cdecl *v6)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD); // eax
  int (__cdecl *v7)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD); // ebx
  _DWORD *v8; // eax
  int (__cdecl *v9)(struct ASN1_VALUE_st **, const ASN1_ITEM_st *); // eax
  int v10; // eax
  bool v11; // zf
  int (**v13)(void); // esi
  struct ASN1_VALUE_st *v14; // eax
  int v15; // eax
  struct ASN1_VALUE_st *v16; // eax
  int v17; // eax
  struct ASN1_VALUE_st *v18; // eax
  const ASN1_TEMPLATE_st *templates; // ebx
  struct ASN1_VALUE_st **field_ptr; // eax
  int (__cdecl *v21)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD); // [esp+Ch] [ebp-4h]

  funcs = it->funcs;
  v5 = 0;
  if ( funcs && (v6 = (int (__cdecl *)(int, struct ASN1_VALUE_st **, const ASN1_ITEM_st *, _DWORD))funcs[4]) != 0 )
  {
    v7 = v6;
    v21 = v6;
  }
  else
  {
    v21 = 0;
    v7 = 0;
  }
  if ( !combine )
    *pval = 0;
  switch ( it->itype )
  {
    case 0:
      if ( !it->templates )
        goto $LN24_8;
      v10 = ASN1_template_new(pval, it->templates);
      goto LABEL_11;
    case 1:
    case 6:
      if ( !v7 )
        goto LABEL_32;
      v17 = v7(0, pval, it, 0);
      if ( !v17 )
        goto auxerr;
      if ( v17 == 2 )
        return 1;
LABEL_32:
      if ( combine )
        goto LABEL_35;
      v18 = (struct ASN1_VALUE_st *)CRYPTO_malloc(it->size, ".\\crypto\\asn1\\tasn_new.c", 191);
      *pval = v18;
      if ( !v18 )
        goto memerr_0;
      memset((int)v18, 0, it->size);
      asn1_do_lock(pval, 0, it);
      asn1_enc_init(pval, it);
LABEL_35:
      templates = it->templates;
      if ( it->tcount <= 0 )
        goto LABEL_38;
      break;
    case 2:
      if ( !v7 )
        goto LABEL_23;
      v15 = v7(0, pval, it, 0);
      if ( !v15 )
        goto auxerr;
      if ( v15 == 2 )
        return 1;
LABEL_23:
      if ( combine )
        goto LABEL_26;
      v16 = (struct ASN1_VALUE_st *)CRYPTO_malloc(it->size, ".\\crypto\\asn1\\tasn_new.c", 163);
      *pval = v16;
      if ( !v16 )
        goto memerr_0;
      memset((int)v16, 0, it->size);
LABEL_26:
      asn1_set_choice_selector(pval, -1, it);
      if ( !v7 )
        return 1;
      if ( !v7(1, pval, it, 0) )
        goto auxerr;
      return 1;
    case 3:
      v13 = (int (**)(void))it->funcs;
      if ( !v13 || !*v13 )
        return 1;
      v14 = (struct ASN1_VALUE_st *)(*v13)();
      *pval = v14;
      v11 = v14 == 0;
      goto LABEL_12;
    case 4:
      v8 = it->funcs;
      if ( !v8 )
        return 1;
      v9 = (int (__cdecl *)(struct ASN1_VALUE_st **, const ASN1_ITEM_st *))v8[1];
      if ( !v9 )
        return 1;
      v10 = v9(pval, it);
LABEL_11:
      v11 = v10 == 0;
LABEL_12:
      if ( !v11 )
        return 1;
      goto memerr_0;
    case 5:
$LN24_8:
      v10 = ASN1_primitive_new(pval, it);
      goto LABEL_11;
    default:
      return 1;
  }
  do
  {
    field_ptr = asn1_get_field_ptr(pval, templates);
    if ( !ASN1_template_new(field_ptr, templates) )
    {
memerr_0:
      ERR_put_error(0xDu, 121, 65, ".\\crypto\\asn1\\tasn_new.c", 214);
      return 0;
    }
    ++v5;
    ++templates;
  }
  while ( v5 < it->tcount );
LABEL_38:
  if ( !v21 || v21(1, pval, it, 0) )
    return 1;
auxerr:
  ERR_put_error(0xDu, 121, 100, ".\\crypto\\asn1\\tasn_new.c", 221);
  ASN1_item_ex_free(pval, it);
  return 0;
}
