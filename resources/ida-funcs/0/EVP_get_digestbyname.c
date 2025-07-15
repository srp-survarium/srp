const env_md_st *__cdecl EVP_get_digestbyname(char *name)
{
  return (const env_md_st *)OBJ_NAME_get(name, 1);
}
