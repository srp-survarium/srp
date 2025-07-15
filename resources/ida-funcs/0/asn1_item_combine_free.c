void __usercall asn1_item_combine_free(stack_st **pval@<edi>, const ASN1_ITEM_st *it@<esi>, int combine)
{
  _DWORD *funcs; // eax
  int (__cdecl *v4)(int, stack_st **, const ASN1_ITEM_st *, _DWORD); // ebx
  int choice_selector; // eax
  const ASN1_TEMPLATE_st *v6; // ebp
  stack_st **v7; // eax
  void (__cdecl *v8)(stack_st *); // eax
  void (__cdecl *v9)(stack_st **, const ASN1_ITEM_st *); // eax
  int tcount; // eax
  const ASN1_TEMPLATE_st *v11; // ebp
  const ASN1_TEMPLATE_st *v12; // eax
  const ASN1_TEMPLATE_st *v13; // ebx
  stack_st **field_ptr; // eax
  int (__cdecl *v15)(int, stack_st **, const ASN1_ITEM_st *, _DWORD); // [esp+0h] [ebp-8h]
  int v16; // [esp+4h] [ebp-4h]

  funcs = it->funcs;
  if ( pval && (!it->itype || *pval) )
  {
    if ( funcs && (v4 = (int (__cdecl *)(int, stack_st **, const ASN1_ITEM_st *, _DWORD))funcs[4]) != 0 )
    {
      v15 = (int (__cdecl *)(int, stack_st **, const ASN1_ITEM_st *, _DWORD))funcs[4];
    }
    else
    {
      v15 = 0;
      v4 = 0;
    }
    switch ( it->itype )
    {
      case 0:
        if ( !it->templates )
          goto $LN21_16;
        ASN1_template_free(pval, it->templates);
        break;
      case 1:
      case 6:
        if ( asn1_do_lock((struct ASN1_VALUE_st **)pval, -1, it) <= 0 && (!v4 || v4(2, pval, it, 0) != 2) )
        {
          asn1_enc_free((struct ASN1_VALUE_st **)pval, it);
          tcount = it->tcount;
          v11 = &it->templates[tcount - 1];
          v16 = 0;
          if ( tcount > 0 )
          {
            do
            {
              v12 = asn1_do_adb((struct ASN1_VALUE_st **)pval, v11, 0);
              v13 = v12;
              if ( v12 )
              {
                field_ptr = (stack_st **)asn1_get_field_ptr((struct ASN1_VALUE_st **)pval, v12);
                ASN1_template_free(field_ptr, v13);
              }
              --v11;
              ++v16;
            }
            while ( v16 < it->tcount );
            v4 = v15;
          }
          goto LABEL_31;
        }
        break;
      case 2:
        if ( !v4 || v4(2, pval, it, 0) != 2 )
        {
          choice_selector = asn1_get_choice_selector((struct ASN1_VALUE_st **)pval, it);
          if ( choice_selector >= 0 && choice_selector < it->tcount )
          {
            v6 = &it->templates[choice_selector];
            v7 = (stack_st **)asn1_get_field_ptr((struct ASN1_VALUE_st **)pval, v6);
            ASN1_template_free(v7, v6);
          }
LABEL_31:
          if ( v4 )
            v4(3, pval, it, 0);
          if ( !combine )
          {
            CRYPTO_free(*pval);
            *pval = 0;
          }
        }
        break;
      case 3:
        if ( funcs )
        {
          v8 = (void (__cdecl *)(stack_st *))funcs[1];
          if ( v8 )
            v8(*pval);
        }
        break;
      case 4:
        if ( funcs )
        {
          v9 = (void (__cdecl *)(stack_st **, const ASN1_ITEM_st *))funcs[2];
          if ( v9 )
            v9(pval, it);
        }
        break;
      case 5:
$LN21_16:
        ASN1_primitive_free((struct ASN1_VALUE_st **)pval, it);
        break;
      default:
        return;
    }
  }
}
