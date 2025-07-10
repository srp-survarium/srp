int __cdecl EVP_add_cipher(const evp_cipher_st *c)
{
  const char *v1; // eax
  int result; // eax
  const char *v3; // eax

  v1 = OBJ_nid2sn(c->nid);
  result = OBJ_NAME_add(v1, 2, (const char *)c);
  if ( result )
  {
    check_defer(c->nid);
    v3 = OBJ_nid2ln(c->nid);
    return OBJ_NAME_add(v3, 2, (const char *)c);
  }
  return result;
}
