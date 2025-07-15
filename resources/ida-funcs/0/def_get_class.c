st_ex_class_item *__usercall def_get_class@<eax>(void *class_index@<ebx>, int a2@<edi>)
{
  st_ex_class_item *result; // eax
  void **v3; // edi
  void **v4; // eax
  void **v5; // esi
  stack_st *v6; // eax
  int data[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( ex_data || (result = (st_ex_class_item *)ex_data_check(a2, (int)class_index)) != 0 )
  {
    data[0] = (int)class_index;
    CRYPTO_lock(a2, (int)class_index, 9, 2, ".\\crypto\\ex_data.c", 304);
    v3 = lh_retrieve((lhash_st *)ex_data, data);
    if ( !v3 )
    {
      v4 = (void **)CRYPTO_malloc(12, ".\\crypto\\ex_data.c", 308);
      v5 = v4;
      if ( v4 )
      {
        *v4 = class_index;
        v4[2] = 0;
        v6 = sk_new_null();
        v5[1] = v6;
        if ( v6 )
        {
          lh_insert((lhash_st *)ex_data, v5);
          v3 = v5;
        }
        else
        {
          CRYPTO_free(v5);
        }
      }
    }
    CRYPTO_lock((int)v3, (int)class_index, 10, 2, ".\\crypto\\ex_data.c", 325);
    if ( !v3 )
      ERR_put_error((int)class_index, 0xFu, 105, 65, ".\\crypto\\ex_data.c", 327);
    return (st_ex_class_item *)v3;
  }
  return result;
}
