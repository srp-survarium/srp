stack_st_POLICYINFO *__usercall r2i_certpol@<eax>(int a1@<ebx>, v3_ext_method *method, v3_ext_ctx *ctx, char *value)
{
  stack_st_CONF_VALUE *v5; // eax
  stack_st *p_stack; // edi
  char *v7; // eax
  char *v8; // ebx
  char *v9; // esi
  stack_st_CONF_VALUE *section; // eax
  stack_st_CONF_VALUE *v11; // edi
  POLICYINFO_st *v12; // esi
  asn1_object_st *v13; // edi
  stack_st_CONF_VALUE *v14; // [esp+4h] [ebp-10h]
  int v15; // [esp+8h] [ebp-Ch]
  stack_st *st; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]

  st = sk_new_null();
  if ( !st )
  {
    ERR_put_error(a1, 0x22u, 130, 65, ".\\crypto\\x509v3\\v3_cpols.c", 143);
    return 0;
  }
  v5 = X509V3_parse_list(value);
  p_stack = &v5->stack;
  v14 = v5;
  if ( !v5 )
  {
    ERR_put_error(a1, 0x22u, 130, 34, ".\\crypto\\x509v3\\v3_cpols.c", 148);
err_102:
    sk_pop_free(p_stack, (void (__cdecl *)(void *))X509V3_conf_free);
    sk_pop_free(st, (void (__cdecl *)(void *))POLICYINFO_free);
    return 0;
  }
  v17 = 0;
  v15 = 0;
  if ( sk_num(&v5->stack) > 0 )
  {
    while ( 1 )
    {
      v7 = sk_value(p_stack, v15);
      v8 = v7;
      if ( *((_DWORD *)v7 + 2) )
        break;
      v9 = (char *)*((_DWORD *)v7 + 1);
      if ( !v9 )
        break;
      if ( !strcmp(*((const char **)v7 + 1), "ia5org") )
      {
        v17 = 1;
      }
      else
      {
        if ( *v9 == 64 )
        {
          section = X509V3_get_section((int)v8, ctx);
          v11 = section;
          if ( !section )
          {
            ERR_put_error((int)v8, 0x22u, 130, 135, ".\\crypto\\x509v3\\v3_cpols.c", 167);
LABEL_22:
            ERR_add_error_data(
              6,
              "section:",
              *(_DWORD *)v8,
              ",name:",
              *((_DWORD *)v8 + 1),
              ",value:",
              *((_DWORD *)v8 + 2));
LABEL_13:
            p_stack = &v14->stack;
            goto err_102;
          }
          v12 = policy_section(ctx, section, (stack_st_CONF_VALUE *)v17);
          X509V3_section_free(ctx, v11);
          if ( !v12 )
            goto LABEL_13;
        }
        else
        {
          v13 = OBJ_txt2obj((int)v8, v9, 0);
          if ( !v13 )
          {
            ERR_put_error((int)v8, 0x22u, 130, 110, ".\\crypto\\x509v3\\v3_cpols.c", 177);
            goto LABEL_22;
          }
          v12 = (POLICYINFO_st *)ASN1_item_new(&local_it_76);
          v12->policyid = v13;
        }
        if ( !sk_push(st, (char *)v12) )
        {
          POLICYINFO_free(v12);
          ERR_put_error((int)v8, 0x22u, 130, 65, ".\\crypto\\x509v3\\v3_cpols.c", 186);
          goto LABEL_13;
        }
        p_stack = &v14->stack;
      }
      if ( ++v15 >= sk_num(p_stack) )
        goto LABEL_20;
    }
    ERR_put_error((int)v7, 0x22u, 130, 134, ".\\crypto\\x509v3\\v3_cpols.c", 155);
    ERR_add_error_data(6, "section:", *(_DWORD *)v8, ",name:", *((_DWORD *)v8 + 1), ",value:", *((_DWORD *)v8 + 2));
    goto err_102;
  }
LABEL_20:
  sk_pop_free(p_stack, (void (__cdecl *)(void *))X509V3_conf_free);
  return (stack_st_POLICYINFO *)st;
}
