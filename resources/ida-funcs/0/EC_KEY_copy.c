ec_key_st *__usercall EC_KEY_copy@<eax>(const ec_key_st *a1@<ebx>, ec_key_st *dest, const ec_key_st *src)
{
  ec_group_st *group; // eax
  const ec_method_st *v4; // esi
  ec_group_st *v5; // eax
  ec_point_st *v6; // eax
  bignum_st *v7; // eax
  ec_extra_data_st *method_data; // esi
  void *v10; // eax

  if ( dest && (a1 = src) != 0 )
  {
    group = src->group;
    if ( group )
    {
      v4 = (const ec_method_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)group);
      if ( dest->group )
        EC_GROUP_free(dest->group);
      v5 = EC_GROUP_new(v4);
      dest->group = v5;
      if ( !v5 || !EC_GROUP_copy(v5, src->group) )
        return 0;
    }
    if ( src->pub_key && src->group )
    {
      if ( dest->pub_key )
        EC_POINT_free(dest->pub_key);
      v6 = EC_POINT_new(src->group);
      dest->pub_key = v6;
      if ( !v6 || !EC_POINT_copy(v6, src->pub_key) )
        return 0;
    }
    if ( !src->priv_key
      || (dest->priv_key || (v7 = BN_new((int)src), (dest->priv_key = v7) != 0))
      && BN_copy(dest->priv_key, src->priv_key) )
    {
      EC_EX_DATA_free_all_data(&dest->method_data);
      method_data = src->method_data;
      if ( method_data )
      {
        while ( 1 )
        {
          v10 = method_data->dup_func(method_data->data);
          if ( !v10
            || !EC_EX_DATA_set_data(
                  &dest->method_data,
                  v10,
                  method_data->dup_func,
                  method_data->free_func,
                  method_data->clear_free_func) )
          {
            return 0;
          }
          method_data = method_data->next;
          if ( !method_data )
            goto LABEL_23;
        }
      }
      else
      {
LABEL_23:
        dest->enc_flag = src->enc_flag;
        dest->conv_form = src->conv_form;
        dest->version = src->version;
        return dest;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ERR_put_error((int)a1, 0x10u, 178, 67, ".\\crypto\\ec\\ec_key.c", 144);
    return 0;
  }
}
