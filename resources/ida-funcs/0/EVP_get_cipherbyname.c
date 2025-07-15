const evp_cipher_st *__cdecl EVP_get_cipherbyname(char *name)
{
  return (const evp_cipher_st *)OBJ_NAME_get(name, 2);
}
