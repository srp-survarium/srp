BOOL __cdecl EVP_add_digest(const env_md_st *md)
{
  const char *v1; // edi
  BOOL result; // eax
  const char *v3; // eax
  unsigned int pkey_type; // ecx
  const char *v5; // eax
  const char *v6; // eax

  v1 = OBJ_nid2sn(md->type);
  if ( !OBJ_NAME_add((int)v1, v1, 1, (const char *)md) )
    return 0;
  check_defer(md->type);
  v3 = OBJ_nid2ln(md->type);
  result = OBJ_NAME_add((int)v1, v3, 1, (const char *)md);
  if ( !result )
    return 0;
  pkey_type = md->pkey_type;
  if ( pkey_type && md->type != pkey_type )
  {
    v5 = OBJ_nid2sn(pkey_type);
    if ( OBJ_NAME_add((int)v1, v5, 32769, v1) )
    {
      check_defer(md->pkey_type);
      v6 = OBJ_nid2ln(md->pkey_type);
      return OBJ_NAME_add((int)v1, v6, 32769, v1);
    }
    return 0;
  }
  return result;
}
