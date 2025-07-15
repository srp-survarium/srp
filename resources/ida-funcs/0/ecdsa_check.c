ecdsa_data_st *__usercall ecdsa_check@<eax>(int a1@<edi>, ec_key_st *key)
{
  ecdsa_data_st *result; // eax
  ecdsa_data_st *v3; // eax
  ecdsa_data_st *v4; // esi

  result = (ecdsa_data_st *)EC_KEY_get_key_method_data(
                              key,
                              (void *(__cdecl *)(void *))ecdsa_data_dup,
                              (void (__cdecl *)(void *))ecdsa_data_free,
                              (void (__cdecl *)(void *))ecdsa_data_free);
  if ( !result )
  {
    v3 = ECDSA_DATA_new_method(0, (int)key);
    v4 = v3;
    if ( v3 )
    {
      EC_KEY_insert_key_method_data(
        a1,
        (int)key,
        key,
        v3,
        (void *(__cdecl *)(void *))ecdsa_data_dup,
        (void (__cdecl *)(void *))ecdsa_data_free,
        (void (__cdecl *)(void *))ecdsa_data_free);
      return v4;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
