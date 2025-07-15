const evp_pkey_asn1_method_st *__usercall ENGINE_pkey_asn1_find_str@<eax>(
        int a1@<edi>,
        int a2@<ebx>,
        engine_st **pe,
        const char *str,
        int len)
{
  engine_st *v5; // eax
  engine_st *arg; // [esp+0h] [ebp-10h] BYREF
  int v8; // [esp+4h] [ebp-Ch]
  const char *v9; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]

  arg = 0;
  v8 = 0;
  v9 = str;
  v10 = len;
  CRYPTO_lock(a1, a2, 9, 30, ".\\crypto\\engine\\tb_asnmth.c", 235);
  engine_table_doall((lhash_st *)pkey_asn1_meth_table, look_str_cb, &arg);
  v5 = arg;
  if ( arg )
  {
    ++arg->struct_ref;
    v5 = arg;
  }
  *pe = v5;
  CRYPTO_lock(a1, a2, 10, 30, ".\\crypto\\engine\\tb_asnmth.c", 244);
  return (const evp_pkey_asn1_method_st *)v8;
}
