const evp_pkey_asn1_method_st *__usercall ENGINE_pkey_asn1_find_str@<eax>(
        unsigned int a1@<edi>,
        engine_st **pe,
        const char *str,
        int len)
{
  engine_st *v4; // eax
  engine_st *arg; // [esp+0h] [ebp-10h] BYREF
  int v7; // [esp+4h] [ebp-Ch]
  const char *v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  arg = 0;
  v7 = 0;
  v8 = str;
  v9 = len;
  CRYPTO_lock(a1, 9, 30, ".\\crypto\\engine\\tb_asnmth.c", 235);
  engine_table_doall(pkey_asn1_meth_table, look_str_cb, &arg);
  v4 = arg;
  if ( arg )
  {
    ++arg->struct_ref;
    v4 = arg;
  }
  *pe = v4;
  CRYPTO_lock(a1, 10, 30, ".\\crypto\\engine\\tb_asnmth.c", 244);
  return (const evp_pkey_asn1_method_st *)v7;
}
