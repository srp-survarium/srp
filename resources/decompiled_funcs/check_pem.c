BOOL __usercall check_pem@<eax>(char *nm@<edi>, const char *name@<ecx>)
{
  engine_st *v4; // eax
  const evp_pkey_asn1_method_st *str; // eax
  engine_st *v6; // eax
  const evp_pkey_asn1_method_st *v7; // eax
  BOOL v8; // esi
  engine_st *pe; // [esp+4h] [ebp-4h] BYREF

  if ( !strcmp(nm, name) )
    return 1;
  if ( !strcmp(name, "ANY PRIVATE KEY") )
  {
    if ( !strcmp(nm, "ENCRYPTED PRIVATE KEY") || !strcmp(nm, "PRIVATE KEY") )
      return 1;
    v4 = (engine_st *)pem_check_suffix(nm, "PRIVATE KEY");
    if ( (int)v4 > 0 )
    {
      str = EVP_PKEY_asn1_find_str(0, nm, v4);
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
  v6 = (engine_st *)pem_check_suffix(nm, "PARAMETERS");
  if ( (int)v6 <= 0 )
    return 0;
  v7 = EVP_PKEY_asn1_find_str(&pe, nm, v6);
  if ( !v7 )
    return 0;
  v8 = v7->param_decode != 0;
  if ( pe )
    ENGINE_finish((unsigned int)nm, pe);
  return v8;
}
