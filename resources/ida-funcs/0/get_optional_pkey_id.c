int __usercall get_optional_pkey_id@<eax>(unsigned int a1@<edi>, char *pkey_name)
{
  const evp_pkey_asn1_method_st *str; // eax
  int ppkey_id; // [esp+0h] [ebp-8h] BYREF
  engine_st *pe; // [esp+4h] [ebp-4h] BYREF

  pe = 0;
  ppkey_id = 0;
  str = EVP_PKEY_asn1_find_str(&pe, pkey_name, (engine_st *)0xFFFFFFFF);
  if ( str )
    EVP_PKEY_asn1_get0_info(&ppkey_id, 0, 0, 0, 0, str);
  if ( pe )
    ENGINE_finish(a1, pe);
  return ppkey_id;
}
