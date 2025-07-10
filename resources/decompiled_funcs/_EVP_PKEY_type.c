int __cdecl EVP_PKEY_type(int type)
{
  const evp_pkey_asn1_method_st *v1; // eax
  int pkey_id; // esi
  engine_st *pe; // [esp+4h] [ebp-4h] BYREF

  v1 = EVP_PKEY_asn1_find(&pe, type);
  if ( v1 )
    pkey_id = v1->pkey_id;
  else
    pkey_id = 0;
  if ( pe )
    ENGINE_finish(pe);
  return pkey_id;
}
