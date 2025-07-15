BOOL __usercall EVP_add_cipher@<eax>(int a1@<edi>, const evp_cipher_st *c)
{
  const char *v2; // eax
  BOOL result; // eax
  const char *v4; // eax

  v2 = OBJ_nid2sn(c->nid);
  result = OBJ_NAME_add(a1, v2, 2, (const char *)c);
  if ( result )
  {
    check_defer(c->nid);
    v4 = OBJ_nid2ln(c->nid);
    return OBJ_NAME_add(a1, v4, 2, (const char *)c);
  }
  return result;
}
