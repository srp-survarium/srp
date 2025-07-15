const char *__usercall EVP_PKEY_type@<eax>(int a1@<edi>, void *type)
{
  engine_st *v2; // eax
  const char *id; // esi
  engine_st *pe; // [esp+4h] [ebp-4h] BYREF

  v2 = EVP_PKEY_asn1_find(&pe, type);
  if ( v2 )
    id = v2->id;
  else
    id = 0;
  if ( pe )
    ENGINE_finish(a1, pe);
  return id;
}
