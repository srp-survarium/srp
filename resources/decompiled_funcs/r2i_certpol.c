stack_st_POLICYINFO *__cdecl r2i_certpol(v3_ext_method *method, v3_ext_ctx *ctx, char *value)
{
  stack_st_CONF_VALUE *v4; // eax
  stack_st *p_stack; // edi
  char *v6; // eax
  char *v7; // ebx
  char *v8; // esi
  stack_st_CONF_VALUE *section; // eax
  stack_st_CONF_VALUE *v10; // edi
  POLICYINFO_st *v11; // esi
  asn1_object_st *v12; // edi
  stack_st_CONF_VALUE *v13; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  stack_st *st; // [esp+Ch] [ebp-8h]
  int ia5org; // [esp+10h] [ebp-4h]

  st = sk_new_null();
  if ( !st )
  {
    ERR_put_error(0x22u, 130, 65, ".\\crypto\\x509v3\\v3_cpols.c", 143);
    return 0;
  }
  v4 = X509V3_parse_list(value);
  p_stack = &v4->stack;
  v13 = v4;
  if ( !v4 )
  {
    ERR_put_error(0x22u, 130, 34, ".\\crypto\\x509v3\\v3_cpols.c", 148);
err_100:
    sk_pop_free(p_stack, (void (__cdecl *)(void *))X509V3_conf_free);
    sk_pop_free(st, (void (__cdecl *)(void *))POLICYINFO_free);
    return 0;
  }
  ia5org = 0;
  i = 0;
  if ( sk_num(&v4->stack) > 0 )
  {
    while ( 1 )
    {
      v6 = sk_value(p_stack, i);
      v7 = v6;
      if ( *((_DWORD *)v6 + 2) )
        break;
      v8 = (char *)*((_DWORD *)v6 + 1);
      if ( !v8 )
        break;
      if ( !strcmp(*((const char **)v6 + 1), "ia5org") )
      {
        ia5org = 1;
      }
      else
      {
        if ( *v8 == 64 )
        {
          section = X509V3_get_section(ctx);
          v10 = section;
          if ( !section )
          {
            ERR_put_error(0x22u, 130, 135, ".\\crypto\\x509v3\\v3_cpols.c", 167);
LABEL_22:
            ERR_add_error_data(
              6,
              "section:",
              *(_DWORD *)v7,
              ",name:",
              *((_DWORD *)v7 + 1),
              ",value:",
              *((_DWORD *)v7 + 2));
LABEL_13:
            p_stack = &v13->stack;
            goto err_100;
          }
          v11 = policy_section(ctx, section, (stack_st_CONF_VALUE *)ia5org);
          X509V3_section_free(ctx, v10);
          if ( !v11 )
            goto LABEL_13;
        }
        else
        {
          v12 = OBJ_txt2obj(v8, 0);
          if ( !v12 )
          {
            ERR_put_error(0x22u, 130, 110, ".\\crypto\\x509v3\\v3_cpols.c", 177);
            goto LABEL_22;
          }
          v11 = (POLICYINFO_st *)ASN1_item_new(&local_it_76);
          v11->policyid = v12;
        }
        if ( !sk_push(st, (char *)v11) )
        {
          POLICYINFO_free(v11);
          ERR_put_error(0x22u, 130, 65, ".\\crypto\\x509v3\\v3_cpols.c", 186);
          goto LABEL_13;
        }
        p_stack = &v13->stack;
      }
      if ( ++i >= sk_num(p_stack) )
        goto LABEL_20;
    }
    ERR_put_error(0x22u, 130, 134, ".\\crypto\\x509v3\\v3_cpols.c", 155);
    ERR_add_error_data(6, "section:", *(_DWORD *)v7, ",name:", *((_DWORD *)v7 + 1), ",value:", *((_DWORD *)v7 + 2));
    goto err_100;
  }
LABEL_20:
  sk_pop_free(p_stack, (void (__cdecl *)(void *))X509V3_conf_free);
  return (stack_st_POLICYINFO *)st;
}
