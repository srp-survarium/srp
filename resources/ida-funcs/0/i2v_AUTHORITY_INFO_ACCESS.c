stack_st_CONF_VALUE *__cdecl i2v_AUTHORITY_INFO_ACCESS(
        v3_ext_method *method,
        stack_st_ACCESS_DESCRIPTION *ainfo,
        stack_st_CONF_VALUE *ret)
{
  stack_st_ACCESS_DESCRIPTION *v3; // esi
  int v5; // ebp
  char *v7; // esi
  stack_st_CONF_VALUE *v8; // eax
  char *v9; // ebx
  unsigned int v10; // edi
  char *v11; // eax
  char *v12; // esi
  stack_st_CONF_VALUE *v13; // [esp+10h] [ebp-60h]
  char buf[80]; // [esp+1Ch] [ebp-54h] BYREF

  v3 = ainfo;
  v5 = 0;
  if ( sk_num(&ainfo->stack) > 0 )
  {
    while ( 1 )
    {
      v7 = sk_value(&v3->stack, v5);
      v8 = i2v_GENERAL_NAME(method, *((GENERAL_NAME_st **)v7 + 1), ret);
      v13 = v8;
      if ( !v8 )
        return (stack_st_CONF_VALUE *)sk_new_null();
      v9 = sk_value(&v8->stack, v5);
      i2t_ASN1_OBJECT(buf, 0x50u, *(asn1_object_st **)v7);
      v10 = strlen(*((const char **)v9 + 1)) + strlen(buf) + 5;
      v11 = (char *)CRYPTO_malloc(v10, ".\\crypto\\x509v3\\v3_info.c", 118);
      v12 = v11;
      if ( !v11 )
      {
        ERR_put_error(0x22u, 138, 65, ".\\crypto\\x509v3\\v3_info.c", 121);
        return 0;
      }
      BUF_strlcpy(v11, buf, v10);
      BUF_strlcat(v12, " - ", v10);
      BUF_strlcat(v12, *((const char **)v9 + 1), v10);
      CRYPTO_free(*((void **)v9 + 1));
      *((_DWORD *)v9 + 1) = v12;
      ++v5;
      ret = v13;
      if ( v5 >= sk_num(&ainfo->stack) )
        break;
      v3 = ainfo;
    }
  }
  if ( !ret )
    return (stack_st_CONF_VALUE *)sk_new_null();
  return ret;
}
