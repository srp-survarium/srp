const evp_pkey_asn1_method_st *__cdecl EVP_PKEY_asn1_find_str(engine_st **pe, char *str, engine_st *len)
{
  engine_st *v3; // ebx
  const evp_pkey_asn1_method_st *v4; // esi
  int i; // ebp
  stack_st_EVP_PKEY_ASN1_METHOD *v7; // ecx
  int v8; // eax
  int v9; // eax
  char *v10; // esi
  const char *v11; // eax
  const char *v12; // edi
  int v13; // eax

  v3 = len;
  if ( len == (engine_st *)-1 )
    v3 = (engine_st *)strlen(str);
  if ( pe )
  {
    v4 = ENGINE_pkey_asn1_find_str((int)pe, (int)v3, &len, str, (int)v3);
    if ( v4 )
    {
      if ( !ENGINE_init((int)pe, len) )
        v4 = 0;
      ENGINE_free((int)pe, (int)v3, len);
      *pe = len;
      return v4;
    }
    *pe = 0;
  }
  for ( i = 0; ; ++i )
  {
    v7 = app_methods;
    v8 = 10;
    if ( app_methods )
    {
      v9 = sk_num(&app_methods->stack);
      v7 = app_methods;
      v8 = v9 + 10;
    }
    if ( i >= v8 )
      break;
    if ( i >= 0 )
    {
      if ( i >= 10 )
        v10 = sk_value(&v7->stack, i - 10);
      else
        v10 = (char *)standard_methods[i];
    }
    else
    {
      v10 = 0;
    }
    if ( (v10[8] & 1) == 0 )
    {
      v11 = (const char *)*((_DWORD *)v10 + 3);
      v12 = v11 + 1;
      if ( (engine_st *)strlen(v11) == v3 )
      {
        _strnicmp((int)v3, v12, *((char **)v10 + 3), str, (unsigned int)v3);
        if ( !v13 )
          return (const evp_pkey_asn1_method_st *)v10;
      }
    }
  }
  return 0;
}
