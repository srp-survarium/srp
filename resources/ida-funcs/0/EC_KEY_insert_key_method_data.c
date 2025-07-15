void __usercall EC_KEY_insert_key_method_data(
        int a1@<edi>,
        int a2@<ebx>,
        ec_key_st *key,
        void *data,
        void *(__cdecl *dup_func)(void *),
        void (__cdecl *free_func)(void *),
        void (__cdecl *clear_free_func)(void *))
{
  CRYPTO_lock(a1, a2, 9, 33, ".\\crypto\\ec\\ec_key.c", 445);
  if ( !EC_EX_DATA_get_data(key->method_data, dup_func, free_func, clear_free_func) )
    EC_EX_DATA_set_data(&key->method_data, data, dup_func, free_func, clear_free_func);
  CRYPTO_lock((int)clear_free_func, (int)free_func, 10, 33, ".\\crypto\\ec\\ec_key.c", 449);
}
