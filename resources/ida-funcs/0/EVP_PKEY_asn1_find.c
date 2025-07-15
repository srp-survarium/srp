engine_st *__cdecl EVP_PKEY_asn1_find(engine_st **pe, void *type)
{
  void *pkey_base_id; // edi
  const evp_pkey_asn1_method_st *i; // esi
  engine_st *pkey_asn1_meth_engine; // eax

  pkey_base_id = type;
  for ( i = pkey_asn1_find(type); i; i = pkey_asn1_find(pkey_base_id) )
  {
    if ( (i->pkey_flags & 1) == 0 )
      break;
    pkey_base_id = (void *)i->pkey_base_id;
  }
  if ( pe )
  {
    pkey_asn1_meth_engine = ENGINE_get_pkey_asn1_meth_engine((int)pkey_base_id);
    if ( pkey_asn1_meth_engine )
    {
      *pe = pkey_asn1_meth_engine;
      return ENGINE_get_pkey_asn1_meth((evp_pkey_asn1_method_st *)pkey_asn1_meth_engine, (int)pkey_base_id);
    }
    *pe = 0;
  }
  return (engine_st *)i;
}
