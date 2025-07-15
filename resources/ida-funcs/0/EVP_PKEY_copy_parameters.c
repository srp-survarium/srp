int __usercall EVP_PKEY_copy_parameters@<eax>(int a1@<ebx>, evp_pkey_st *to, const evp_pkey_st *from)
{
  const evp_pkey_asn1_method_st *ameth; // eax
  int (__cdecl *param_missing)(const evp_pkey_st *); // eax
  const evp_pkey_asn1_method_st *v6; // eax
  int (__cdecl *param_copy)(evp_pkey_st *, const evp_pkey_st *); // eax

  if ( to->type != from->type )
  {
    ERR_put_error(a1, 6u, 103, 101, ".\\crypto\\evp\\p_lib.c", 128);
    return 0;
  }
  ameth = from->ameth;
  if ( ameth && (param_missing = ameth->param_missing) != 0 && param_missing(from) )
  {
    ERR_put_error(a1, 6u, 103, 103, ".\\crypto\\evp\\p_lib.c", 134);
    return 0;
  }
  else
  {
    v6 = from->ameth;
    if ( !v6 )
      return 0;
    param_copy = v6->param_copy;
    if ( !param_copy )
      return 0;
    return param_copy(to, from);
  }
}
