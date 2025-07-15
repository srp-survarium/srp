BOOL __usercall check_pem@<eax>(char *nm@<edi>, const char *name@<ecx>, int a3@<ebx>)
{
  engine_st *v5; // eax
  const evp_pkey_asn1_method_st *str; // eax
  engine_st *v7; // eax
  const evp_pkey_asn1_method_st *v8; // eax
  BOOL v9; // esi
  engine_st *v10; // [esp+4h] [ebp-4h] BYREF

  if ( !strcmp(nm, name) )
    return 1;
  if ( !strcmp(name, "ANY PRIVATE KEY") )
  {
    if ( !strcmp(nm, "ENCRYPTED PRIVATE KEY") || !strcmp(nm, "PRIVATE KEY") )
      return 1;
    v5 = (engine_st *)pem_check_suffix(nm, "PRIVATE KEY");
    if ( (int)v5 > 0 )
    {
      str = EVP_PKEY_asn1_find_str(0, nm, v5);
      if ( str )
      {
        if ( str->old_priv_decode )
          return 1;
      }
    }
    return 0;
  }
  if ( strcmp(name, "PARAMETERS") )
    return !strcmp(nm, "X509 CERTIFICATE") && !strcmp(name, "CERTIFICATE")
        || !strcmp(nm, "NEW CERTIFICATE REQUEST") && !strcmp(name, "CERTIFICATE REQUEST")
        || !strcmp(nm, "CERTIFICATE") && !strcmp(name, "TRUSTED CERTIFICATE")
        || !strcmp(nm, "X509 CERTIFICATE") && !strcmp(name, "TRUSTED CERTIFICATE")
        || !strcmp(nm, "CERTIFICATE") && !strcmp(name, "PKCS7")
        || !strcmp(nm, "PKCS #7 SIGNED DATA") && !strcmp(name, "PKCS7")
        || !strcmp(nm, "CERTIFICATE") && !strcmp(name, "CMS")
        || !strcmp(nm, "PKCS7") && !strcmp(name, "CMS");
  v7 = (engine_st *)pem_check_suffix(nm, "PARAMETERS");
  if ( (int)v7 <= 0 )
    return 0;
  v8 = EVP_PKEY_asn1_find_str(&v10, nm, v7);
  if ( !v8 )
    return 0;
  v9 = v8->param_decode != 0;
  if ( v10 )
    ENGINE_finish((int)nm, a3, v10);
  return v9;
}
