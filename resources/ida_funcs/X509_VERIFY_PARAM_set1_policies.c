int __cdecl X509_VERIFY_PARAM_set1_policies(X509_VERIFY_PARAM_st *param, stack_st_ASN1_OBJECT *policies)
{
  int v2; // edi
  stack_st_ASN1_OBJECT *v4; // eax
  stack_st_ASN1_OBJECT *v5; // eax
  char *v6; // eax
  asn1_object_st *v7; // esi

  v2 = 0;
  if ( !param )
    return 0;
  v4 = param->policies;
  if ( v4 )
    sk_pop_free(&v4->stack, (void (__cdecl *)(void *))ASN1_OBJECT_free);
  if ( policies )
  {
    v5 = (stack_st_ASN1_OBJECT *)sk_new_null();
    param->policies = v5;
    if ( v5 )
    {
      if ( sk_num(&policies->stack) <= 0 )
      {
LABEL_13:
        param->flags |= 0x80u;
        return 1;
      }
      else
      {
        while ( 1 )
        {
          v6 = sk_value(&policies->stack, v2);
          v7 = OBJ_dup((const asn1_object_st *)v6);
          if ( !v7 )
            return 0;
          if ( !sk_push(&param->policies->stack, (char *)v7) )
          {
            ASN1_OBJECT_free(v7);
            return 0;
          }
          if ( ++v2 >= sk_num(&policies->stack) )
            goto LABEL_13;
        }
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    param->policies = 0;
    return 1;
  }
}
