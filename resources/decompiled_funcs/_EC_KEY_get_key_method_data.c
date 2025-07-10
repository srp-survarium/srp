void *__cdecl EC_KEY_get_key_method_data(
        ec_key_st *key,
        void *(__cdecl *dup_func)(void *),
        void (__cdecl *free_func)(void *),
        void (__cdecl *clear_free_func)(void *))
{
  return EC_EX_DATA_get_data(key->method_data, dup_func, free_func, clear_free_func);
}
