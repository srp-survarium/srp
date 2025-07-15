int __usercall pkey_set_type@<eax>(evp_pkey_st *pkey@<esi>, char *str@<ecx>, void *type, engine_st *len)
{
  const evp_pkey_asn1_method_st *ameth; // eax
  void (__cdecl *pkey_free)(evp_pkey_st *); // eax
  const evp_pkey_asn1_method_st *v7; // eax
  const evp_pkey_asn1_method_st *v8; // edi
  engine_st *v10; // eax
  engine_st *pe; // [esp+Ch] [ebp-4h] BYREF

  pe = 0;
  if ( pkey )
  {
    if ( pkey->pkey.ptr )
    {
      ameth = pkey->ameth;
      if ( ameth )
      {
        pkey_free = ameth->pkey_free;
        if ( pkey_free )
        {
          pkey_free(pkey);
          pkey->pkey.ptr = 0;
        }
      }
      if ( pkey->engine )
      {
        ENGINE_finish((int)str, pkey->engine);
        pkey->engine = 0;
      }
    }
    if ( type == (void *)pkey->save_type && pkey->ameth )
      return 1;
    if ( pkey->engine )
    {
      ENGINE_finish((int)str, pkey->engine);
      pkey->engine = 0;
    }
  }
  if ( str )
    v7 = EVP_PKEY_asn1_find_str(&pe, str, len);
  else
    v7 = (const evp_pkey_asn1_method_st *)EVP_PKEY_asn1_find(&pe, type);
  v8 = v7;
  if ( !pkey && pe )
    ENGINE_finish((int)v7, pe);
  if ( !v8 )
  {
    ERR_put_error(0, 6u, 158, 156, ".\\crypto\\evp\\p_lib.c", 239);
    return 0;
  }
  if ( pkey )
  {
    v10 = pe;
    pkey->ameth = v8;
    pkey->engine = v10;
    pkey->type = v8->pkey_id;
    pkey->save_type = (int)type;
  }
  return 1;
}
