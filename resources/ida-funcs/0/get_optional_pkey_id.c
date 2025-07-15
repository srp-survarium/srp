int __usercall get_optional_pkey_id@<eax>(int a1@<edi>, int a2@<ebx>, char *pkey_name)
{
  const evp_pkey_asn1_method_st *str; // eax
  int v5; // [esp+0h] [ebp-8h] BYREF
  engine_st *v6; // [esp+4h] [ebp-4h] BYREF

  v6 = 0;
  v5 = 0;
  str = EVP_PKEY_asn1_find_str(&v6, pkey_name, (engine_st *)0xFFFFFFFF);
  if ( str )
    EVP_PKEY_asn1_get0_info(&v5, 0, 0, 0, 0, str);
  if ( v6 )
    ENGINE_finish(a1, a2, v6);
  return v5;
}
