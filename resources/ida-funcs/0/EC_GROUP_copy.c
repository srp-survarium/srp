int __usercall EC_GROUP_copy@<eax>(int a1@<ebx>, ec_group_st *dest, const ec_group_st *src)
{
  ec_extra_data_st *i; // esi
  void *v5; // eax
  ec_point_st *v6; // eax
  unsigned __int8 *seed; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const ec_method_st *meth; // ecx
  const ec_method_st *v11; // ecx

  if ( !dest->meth->group_copy )
  {
    ERR_put_error(a1, 0x10u, 106, 66, ".\\crypto\\ec\\ec_lib.c", 177);
    return 0;
  }
  if ( dest->meth != src->meth )
  {
    ERR_put_error((int)src, 0x10u, 106, 101, ".\\crypto\\ec\\ec_lib.c", 182);
    return 0;
  }
  if ( dest == src )
    return 1;
  EC_EX_DATA_free_all_data(&dest->extra_data);
  for ( i = src->extra_data; i; i = i->next )
  {
    v5 = i->dup_func(i->data);
    if ( !v5 || !EC_EX_DATA_set_data(&dest->extra_data, v5, i->dup_func, i->free_func, i->clear_free_func) )
      return 0;
  }
  if ( src->generator )
  {
    if ( !dest->generator )
    {
      v6 = EC_POINT_new((int)src, dest);
      dest->generator = v6;
      if ( !v6 )
        return 0;
    }
    if ( !EC_POINT_copy((int)src, dest->generator, src->generator) )
      return 0;
  }
  else if ( dest->generator )
  {
    EC_POINT_clear_free(dest->generator);
    dest->generator = 0;
  }
  if ( !BN_copy(&dest->order, &src->order) || !BN_copy(&dest->cofactor, &src->cofactor) )
    return 0;
  dest->curve_name = src->curve_name;
  seed = dest->seed;
  dest->asn1_flag = src->asn1_flag;
  dest->asn1_form = src->asn1_form;
  if ( src->seed )
  {
    if ( seed )
      CRYPTO_free(seed);
    v8 = (unsigned __int8 *)CRYPTO_malloc(src->seed_len, ".\\crypto\\ec\\ec_lib.c", 230);
    dest->seed = v8;
    if ( !v8 )
      return 0;
    memcpy((int)v8, (const __m128i *)src->seed, src->seed_len);
    if ( !v9 )
      return 0;
    meth = dest->meth;
    dest->seed_len = src->seed_len;
    return meth->group_copy(dest, src);
  }
  else
  {
    if ( seed )
      CRYPTO_free(seed);
    v11 = dest->meth;
    dest->seed = 0;
    dest->seed_len = 0;
    return v11->group_copy(dest, src);
  }
}
